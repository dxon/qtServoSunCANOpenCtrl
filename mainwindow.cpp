// !!! В релизной версии работает с нормальной скоростью (Комплект = Desktop Qt 5.5, сборка = Выпуск),
// в сборке = Отладка скорость заметно падает, чтение USB идёт с ошибками !!!
// Установить/убрать закладку - Ctrl+M, переход по закладкам - Ctrl+, / Ctrl+.

#include "stdio.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "libusb.h"

#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QThread>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <vector>
#include <QMetaType>


#define VENDOR_ID   0x3208
#define PRODUCT_ID  0x4840

#define USB_DATA_SIZE     64
#define READING_DATA_SIZE 16

static libusb_context *usbContext = nullptr;

static libusb_device_handle *usbHandle = nullptr;

static int ret;

float movDist = 0;

bool doBidir = false;

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


static CAN_Reader *CAN_Rdr = new CAN_Reader;
static CAN_Writer *CAN_Wrtr = new CAN_Writer;
static CAN_Helper *CAN_Hlpr = new CAN_Helper;

QTimer *checkTmr = new QTimer;


//************ MainWindow ***************
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->Read_btn -> setEnabled(false);

  qRegisterMetaType<QVector<uchar> >("QVector<uchar>");

  //  -------------
  connect(this, SIGNAL(startReading()), CAN_Rdr, SLOT(readCanFlow()));
  connect(this, SIGNAL(moveMsgPassing(float)), CAN_Wrtr, SLOT(moveMsgToCan(float)));

  connect(CAN_Rdr, SIGNAL(readResPassing(QVector<uchar>, QString)), this, SLOT(logToGui(QVector<uchar>, QString)));
  connect(CAN_Rdr, SIGNAL(readErrPassing(QString)), this, SLOT(readErrToGui(QString)));
  connect(CAN_Rdr, SIGNAL(moveMsgPassing(float)), CAN_Wrtr, SLOT(moveMsgToCan(float)));

  connect(CAN_Wrtr, SIGNAL(readResPassing(QVector<uchar>, QString)), this, SLOT(logToGui(QVector<uchar>, QString)));
  connect(CAN_Wrtr, SIGNAL(writeErrPassing(QString)), this, SLOT(writeErrToGui(QString)));

  connect(CAN_Rdr, SIGNAL(restartReading()), CAN_Hlpr, SLOT(execRestartReading()));
  connect(CAN_Hlpr, SIGNAL(readAgain()), CAN_Rdr, SLOT(readCanFlow()));

  connect(checkTmr, SIGNAL(timeout()), CAN_Rdr, SLOT(sendFirstData()));
  //  -------------

  checkTmr->start(2);

  CAN_Rdr -> moveToThread(ReaderThread);
  CAN_Wrtr -> moveToThread(WriterThread);
  CAN_Hlpr -> moveToThread(HelperThread);

  ReaderThread->start();
  WriterThread->start();
  HelperThread->start();
}


MainWindow::~MainWindow()
{
  delete ui;
}


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
#ifndef NDEBUG
          libusb_set_debug(usbContext, /*LIBUSB_LOG_LEVEL_DEBUG*/LIBUSB_LOG_LEVEL_NONE);
#endif
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


void MainWindow::logToGui(QVector<uchar> _resBuf, QString _msgColor = "black")
{
  static UINT64 cntr = 0;

  QString CanDataStr  = "";
  QString CanTimeStamp = "";
  unsigned  CanIdHex;
  QString CanIdStr = "";
  QString CanIdRes    = "";

  checkTmr->stop();

  if(!_resBuf.empty())
    {
      CanIdHex = ((_resBuf.at(7) << 24)  | (_resBuf.at(6) << 16) | (_resBuf.at(5) << 8) | (_resBuf.at(4)));

      CanIdStr = QString("%1").arg( CanIdHex, 8, 16, QChar('0')).toUpper() + "  ";

      for(int i = 0; i<7; i=i+2)
        {
          CanIdRes = CanIdRes + QString(CanIdStr[i]) + QString(CanIdStr[i+1]) + " ";
        }

      for(int dataCount = 8; dataCount < READING_DATA_SIZE; dataCount++)
        {
          CanDataStr = CanDataStr + " " + QString("%1").arg(_resBuf.at(dataCount), 2, 16, QChar('0')).toUpper();
        }

      CanTimeStamp = "    " + QString("%1").arg(_resBuf.at(3), 2, 16, QChar('0')).toUpper() + " " + QString("%1").arg(_resBuf.at(2), 2, 16, QChar('0')).toUpper();

      ui->textBrowser->append("<font color = #6F646D> " + QString::number(cntr++) + " . " + "</font color><b><font color = '" + _msgColor + "'>" + CanIdRes + " .. " + CanDataStr + "</font color></b><font color = #6F646D> .. " + CanTimeStamp + "</font color>\n");
    }
  checkTmr->start(2);
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

          event->accept(); // разрешаем завершение приложения
        }
    }
  else
    {
      event->accept(); // разрешаем завершение приложения
    }
}


//************ CAN_Reader ***************
void CAN_Reader::readCanFlow()
{
  unsigned char readBuf[USB_DATA_SIZE];

  QVector<uchar> tmpVec(USB_DATA_SIZE);

  int readRes = -1;

  //-----------------------
  // Read data from usbDev
  //-----------------------
  if(usbHandle != nullptr)
    {
      readRes = libusb_interrupt_transfer(usbHandle, 0x82, readBuf, USB_DATA_SIZE, &ret, 5000); // читаем из USB

      if((readRes >(-1)) /*&& (ret <= USB_DATA_SIZE)*/)// если чтение идёт нормально
        {
          if(doLogging == true)
            {
              //** set font black color **
              readBuf[16] = 0x00;
              readBuf[17] = 0x00;
              readBuf[18] = 0x00;
              //**************************

              for(int i = 0; i < USB_DATA_SIZE; i++)
                {
                  tmpVec[i] = readBuf[i];
                }

              readOutBuff.append(tmpVec); // пишем прочитанные данные в буферный список, чтобы GUI мог неспеша их разобрать
            }

          if(doBidir == true)
            {
              if((readBuf[6] == 0x0C) && (readBuf[5] == 0x20) && (readBuf[8] == 0x4E) && (readBuf[9] == 0x00) && (readBuf[10] == 0x22) && (readBuf[11] == 0x00))
                {
                  movDist = (-1)*movDist;
                  emit moveMsgPassing(movDist); // отсылаем данные для отправки в USB
                }
            }
        }
      else // если проблемы с чтением
        {
          emit readErrPassing(QString(libusb_error_name(readRes)));
        }

      if(doReading == true)
        {
          // readCanFlow(); // !! такая рекурсия вызывает в итоге ошибку при выполнении !!

          emit restartReading(); //!!ТАК РАБОТАЕТ НОРМАЛЬНО (через доп.класс в отдельном потоке) - TODO:разобраться !!
        }
    }
}

void CAN_Reader::sendFirstData()
{
  QVector<uchar> tmpVec;
  if(readOutBuff.count() > 0)
    {
      tmpVec = readOutBuff.takeFirst();

      emit readResPassing(tmpVec, "black"); // то передаем результат чтения на вывод
    }
}


void CAN_Helper::execRestartReading()
{
  emit readAgain();
}


//************ CAN_Writer ***************
void CAN_Writer::moveMsgToCan(float _pos)
{
  int64_t dist;
  int writeRes = -1;

  uchar writeBuf[USB_DATA_SIZE];

  QVector<uchar> tmpVec(USB_DATA_SIZE);

  if(usbHandle != nullptr)
    {
      QString CanIdRes    = "";
      QString CanDataStr  = "";
      QString CanTimeStamp = "";

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
      writeRes = libusb_interrupt_transfer(usbHandle, 0x01, writeBuf, sizeof(writeBuf), &ret, 5000);

      if(doLogging == true)
        {
          for(int i = 0; i < USB_DATA_SIZE; i++)
            {
              tmpVec[i] = writeBuf[i];
            }

          emit readResPassing(tmpVec, "#4BC54E"); // передаем отправленную команду на вывод в GUI
        }

      if(writeRes < 0)
        {
          emit writeErrPassing(QString(libusb_error_name(writeRes))); // при наличии ошибки записи отправляем её код на вывод в пользовательский GUI
        }
    }
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
