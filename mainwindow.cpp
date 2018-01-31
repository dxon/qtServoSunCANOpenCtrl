// Установить/убрать закладку - Ctrl+M, переход по закладкам - Ctrl+, / Ctrl+.

#include "stdio.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "libusb.h"

#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QCloseEvent>
#include <QFile>
#include <QVector>
#include <QMetaType>


#define VENDOR_ID   0x3208
#define PRODUCT_ID  0x4840

#define USB_DATA_SIZE     64
#define READING_DATA_SIZE 16

static libusb_context *usbContext = nullptr;

static libusb_device_handle *usbHandle = nullptr;

static int ret;

static float movDist = 0;

static bool doBidir = false;

static bool doReading = false;
static bool doLogging = true;

union
{
  int32_t i;
  float f;
} flintconvert;


static QThread *ReaderThread = new QThread;
static QThread *WriterThread = new QThread;
static QThread *HelperThread = new QThread;
static QThread *TriggerThread = new QThread;


static CAN_Reader *CAN_Rdr = new CAN_Reader;
static CAN_Writer *CAN_Wrtr = new CAN_Writer;
static CAN_Helper *CAN_Hlpr = new CAN_Helper;
static CAN_ReadTrigger *CAN_RdTrg = new CAN_ReadTrigger;

static QTimer *hlprCheckTmr = new QTimer(0);

static QList<QVector<uchar> > *readList = new QList<QVector<uchar> >;


//************ < MainWindow > ***************
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  qRegisterMetaType<QVector<uchar> >("QVector<uchar>");

  ui->setupUi(this);

  ui->Read_btn -> setEnabled(false);

  //  -------------
  connect(this, SIGNAL(startReading()), CAN_Rdr, SLOT(readCanFlow()));
  connect(this, SIGNAL(moveMsgPassing(float)), CAN_Wrtr, SLOT(moveMsgToCan(float)));

  connect(CAN_Rdr, SIGNAL(readErrPassing(QString)), this, SLOT(readErrToGui(QString)));
  connect(CAN_Rdr, SIGNAL(moveMsgPassing(float)), CAN_Wrtr, SLOT(moveMsgToCan(float)));

  connect(CAN_Wrtr, SIGNAL(writeErrPassing(QString)), this, SLOT(writeErrToGui(QString)));

  connect(CAN_Rdr, SIGNAL(sendDataToList(QVector<uchar>)), CAN_Hlpr, SLOT(writeDataToList(QVector<uchar>)));

  connect(this, SIGNAL(giveFirstData()), CAN_Hlpr, SLOT(checkList()));

  connect(CAN_Hlpr, SIGNAL(sendDataFromList(QString)), this, SLOT(logToGui(QString)));

  connect(CAN_Rdr, SIGNAL(restartReading()), CAN_RdTrg, SLOT(slotRestartReading()));

  connect(CAN_RdTrg, SIGNAL(sigRestartReading()), CAN_Rdr, SLOT(readCanFlow()));


  //  -------------

  CAN_Rdr -> moveToThread(ReaderThread);
  CAN_Wrtr -> moveToThread(WriterThread);
  CAN_Hlpr -> moveToThread(HelperThread);
  hlprCheckTmr->moveToThread(HelperThread);
  //CAN_RdTrg -> moveToThread(TriggerThread);

  ReaderThread->start();
  WriterThread->start();
  HelperThread->start();
  // TriggerThread->start();
}


MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::logToGui(QString _inputStr)
{
  static UINT64 cntr = 0;

  ui->textBrowser->append("<font color = #6F646D> " + QString::number(cntr++) + " . </font color>" + _inputStr);
}


void MainWindow::readErrToGui(QString r_err)
{
  ui->textBrowser->append("<b><font color = 'red'> **> UsbDev with VID = " + QString("0x%1").arg(VENDOR_ID, 4, 16, QChar('0')) + " and PID = " + QString("0x%1").arg( PRODUCT_ID, 4, 16, QChar('0')) + " read error: " + r_err+ "</font></b> \n");
}


void MainWindow::writeErrToGui(QString w_err)
{
  ui->textBrowser->append("<b><font color = 'red'> **> UsbDev with VID = " + QString("0x%1").arg(VENDOR_ID, 4, 16, QChar('0')) + " and PID = " + QString("0x%1").arg( PRODUCT_ID, 4, 16, QChar('0')) + " write error: " + w_err + "</font></b> \n");
}


void MainWindow::closeEvent(QCloseEvent *event)
{
  int res = -1;

  event->ignore(); // запрещаем завершение приложения

  //--------------------------
  // release usbDev interface
  //--------------------------
  if(usbHandle != nullptr)
    {
      doReading = false;

      res = libusb_release_interface(usbHandle, 0);

      if(res > (-1))
        {
          libusb_close(usbHandle);
          libusb_exit(usbContext);

          // завершаем запущенные нами ранее потоки
          ReaderThread->exit();
          HelperThread->exit();
          WriterThread->exit();
        }
    }
  event->accept(); // разрешаем завершение приложения
}
//************ </ MainWindow > ***************


//************ < CAN_Reader > ***************
void CAN_Reader::readCanFlow()
{
  unsigned char readBuf[USB_DATA_SIZE];
  QVector<uchar> readVec(USB_DATA_SIZE);

  int readRes = -1;

  //-----------------------
  // Read data from usbDev
  //-----------------------
  if(usbHandle != nullptr)
    {
      readRes = libusb_interrupt_transfer(usbHandle, 0x82, readBuf, USB_DATA_SIZE, &ret, 0); // читаем из USB

      readVec.fill(0x00, 64);

      if((readRes >(-1)) && (ret == USB_DATA_SIZE))// если чтение идёт нормально
        {
          if((sizeof(readBuf) / sizeof(readBuf[0])) == USB_DATA_SIZE) //проверяем длину полученного при чтении массива
            {
              memcpy(readVec.data(), readBuf, USB_DATA_SIZE*sizeof(uchar));
            }
          else
            {
              emit readErrPassing("!! size of readBuf < USB_DATA_SIZE!!");
            }

          if(readVec.count() == USB_DATA_SIZE)
            {
              if(doLogging == true)
                {
                  emit sendDataToList(readVec);
                }

              if(doBidir == true)
                {
                  if((readVec.at(6) == 0x0C) && (readVec.at(5) == 0x20) && (readVec.at(8) == 0x4E) && (readVec.at(9) == 0x00) && (readVec.at(10) == 0x22) && (readVec.at(11) == 0x00))
                    {
                      movDist = (-1)*movDist;
                      emit moveMsgPassing(movDist); // отсылаем данные для отправки в USB
                    }
                }
            }
          else
            {
              emit readErrPassing("!! readVec < USB_DATA_SIZE!!");
            }
        }
      else // если проблемы с чтением
        {
          emit readErrPassing(QString(libusb_error_name(readRes)));
        }

      if(doReading == true)
        {
          emit restartReading();
        }
    }
  return;
}
//************ </ CAN_Reader > ***************


//************ < CAN_Helper > ***************
void CAN_Helper::writeDataToList(QVector<uchar> _resBuf)
{
  readList->append(_resBuf);
}


void CAN_Helper::checkList()
{
  QVector<uchar> _resBuf(64);
  QString canDataStr = "";
  QString canTimeStamp = "";
  unsigned canIdHex = 0x00;
  QString canIdStr = "";
  QString canIdRes = "";
  QString totalRes = "";

  if(doLogging == true)
    {
      if(readList->count() > 0)
        {
          _resBuf.fill(0x00, 64);

          _resBuf = readList->takeFirst();

          if(_resBuf.count() == USB_DATA_SIZE)
            {
              canIdHex = ((_resBuf.at(7)<< 24) | (_resBuf.at(6) << 16) | (_resBuf.at(5) << 8) | (_resBuf.at(4)));

              canIdStr = QString("%1").arg( canIdHex, 8, 16, QChar('0')).toUpper() + "  ";

              for(int i = 0; i<7; i=i+2)
                {
                  canIdRes = canIdRes + QString(canIdStr[i]) + QString(canIdStr[i+1]) + " ";
                }

              for(int dataCount = 8; dataCount < READING_DATA_SIZE; dataCount++)
                {
                  canDataStr = canDataStr + " " + QString("%1").arg(_resBuf[dataCount], 2, 16, QChar('0')).toUpper();
                }

              canTimeStamp = "    " + QString("%1").arg(_resBuf[3], 2, 16, QChar('0')).toUpper() + " " + QString("%1").arg(_resBuf[2], 2, 16, QChar('0')).toUpper();

              totalRes = "<b><font color = #000000>" + canIdRes + " .. " + canDataStr + "</font color></b><font color = #6F646D> .. " + canTimeStamp + "</font color>\n";

              emit sendDataFromList(totalRes); // то передаем результат чтения на вывод
            }
        }
    }
  hlprCheckTmr->singleShot(1, CAN_Hlpr, SLOT(checkList()));
}
//************ </ CAN_Helper > ***************



//************ < CAN_Writer > ***************
void CAN_Writer::moveMsgToCan(float _pos)
{
  QVector<uchar> writeVec(USB_DATA_SIZE);
  uchar writeBuf[USB_DATA_SIZE];
  int64_t dist;
  int writeRes = -1;

  dist = 0;

  writeRes = -1;

  writeVec.fill(0x00, 64);

  if(usbHandle != nullptr)
    {
      flintconvert.f = _pos;

      dist = flintconvert.i;

      // ВСЕ НЕИСПОЛЬЗУЕМЫЕ БАЙТЫ ( именно здесь это c writeBuf[16] по writeBuf[63] )
      // ДОЛЖНЫ БЫТЬ РАВНЫ 0x00 !!!
      memset(writeBuf, 0x00, sizeof(writeBuf));

      // Заполняем данными выходной массив
      writeBuf[0] =  0x00;
      writeBuf[1] =  0x08; //длина сообщения
      writeBuf[2] =  0x00;
      writeBuf[3] =  0x00;
      writeBuf[4] =  0x61; // адрес получателя
      writeBuf[5] =  0x02; // второй байт адреса отправителя
      writeBuf[6] =  0x02; // первый байт адреса отправителя
      writeBuf[7] =  0x30; // приоритет

      writeBuf[8] =  0x39; // команда
      writeBuf[9] =  0x00; // канал
      writeBuf[10] = 0x22; // параметр Low
      writeBuf[11] = 0x00; // параметр High
      writeBuf[12] =  dist & 0xFF;
      writeBuf[13] = (dist & 0xFF00) >> 8;
      writeBuf[14] = (dist & 0xFF0000) >> 16;
      writeBuf[15] = (dist & 0xFF000000) >> 24;

      writeBuf[16] = 0xFF; // это так надо в любом сообщении
      writeBuf[32] = 0xFF; // это так надо в любом сообщении
      writeBuf[48] = 0xFF; // это так надо в любом сообщении

      //----------------------
      // Write data to usbDev
      //----------------------
      writeRes = libusb_interrupt_transfer(usbHandle, 0x01, writeBuf, sizeof(writeBuf), &ret, 0);

      if(writeRes < 0)
        {
          emit writeErrPassing(QString(libusb_error_name(writeRes))); // при наличии ошибки записи отправляем её код на вывод в пользовательский GUI
        }
    }
}
//************ </ CAN_Writer > ***************



//************ < CAN_ReadTrigger > ***************
void CAN_ReadTrigger::slotRestartReading()
{
  emit sigRestartReading();
}
//************ </ CAN_ReadTrigger > ***************



// ===== < MainWindow GUI buttons > =====

void MainWindow::on_Connect_btn_clicked()
{
  int res = -1;

  //--------------------------------------------------------------------------------------------------------------
  // Initialize the library, enable debug, open usbDev by vendor ID and Product ID, claim interface of usbDev
  //--------------------------------------------------------------------------------------------------------------

  if(usbHandle == nullptr)
    {
      res = libusb_init(&usbContext);

      if(res >= 0)
        {
          libusb_set_debug(usbContext, /*LIBUSB_LOG_LEVEL_DEBUG*/LIBUSB_LOG_LEVEL_NONE);

          usbHandle = libusb_open_device_with_vid_pid(usbContext, VENDOR_ID, PRODUCT_ID);

          if(usbHandle == nullptr)
            {
              ui->textBrowser->append("<b><font color = 'red'> **> UsbDev with VID = " + QString("0x%1").arg( VENDOR_ID, 4, 16, QChar('0')) + " and PID = " + QString("0x%1").arg( PRODUCT_ID, 4, 16, QChar('0')) + " is not found </font></b>\n");
            }
          else
            {
              // libusb_set_configuration(usbHandle, 1);

              res = libusb_claim_interface(usbHandle, 0);

              if (res < 0)
                {
                  ui->textBrowser->append("<b><font color = 'red'> **> UsbDev with VID = " + QString("0x%1").arg( VENDOR_ID, 4, 16, QChar('0')) + " and PID = " + QString("0x%1").arg( PRODUCT_ID, 4, 16, QChar('0')) + " interface error: " + QString(libusb_error_name(res))+ "</font></b>\n");
                }
              else
                {
                  ui->textBrowser->append("<b><font color = '#08427F'> >> UsbDev with VID = " + QString("0x%1 ").arg( VENDOR_ID, 4, 16, QChar('0')) + " and PID = " + QString("0x%1").arg( PRODUCT_ID, 4, 16, QChar('0')) + " connected OK </font></b>\n");
                  ui->textBrowser->append("");
                  ui->Read_btn->setEnabled(true);
                }
            }
        }
    }
  else
    {
      ui->textBrowser->append("<b><font color = 'red'> **> UsbDev with VID = " + QString("0x%1").arg( VENDOR_ID, 4, 16, QChar('0')) + " and PID = " + QString("0x%1").arg( PRODUCT_ID, 4, 16, QChar('0')) + ": check UsbDev connection - handler is not nullptr </font></b>\n"  );
    }
}


void MainWindow::on_Read_btn_clicked()
{
  doReading = !doReading;
  emit giveFirstData();
  emit startReading();
}


void MainWindow::on_Clear_btn_clicked()
{
  ui->textBrowser->clear();
}


void MainWindow::on_pb_STF_clicked()
{
  QFile file("");

  QTextStream out(&file);

  if(ui->cb_SHTML->isChecked())
    {
      file.setFileName("out.html");

      if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
          return;
        }

      out << ui->textBrowser->document()->toHtml();
    }
  else
    {
      file.setFileName("out.txt");

      if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
          return;
        }

      out << ui->textBrowser->document()->toPlainText();
    }

  file.close();
}


void MainWindow::on_pbT_Pos_clicked()
{
  ui->leT_Pos->returnPressed();
  moveMsgPassing(movDist);
}

void MainWindow::on_cb_CyclePos_stateChanged(int arg1)
{
  if(!arg1)
    {
      doBidir = false;
    }
  else
    {
      doBidir = true;
    }
}

void MainWindow::on_leT_Pos_returnPressed()
{
  if(ui->leT_Pos->text().trimmed() == "")
    {
      movDist = 0;
    }
  else
    {
      movDist = ui->leT_Pos->text().trimmed().toFloat();
    }
}

void MainWindow::on_cb_Logging_stateChanged(int arg1)
{
  if(!arg1)
    {
      doLogging = false;
    }
  else
    {
      doLogging = true;
    }
}
// ===== </ MainWindow GUI controls > =====
