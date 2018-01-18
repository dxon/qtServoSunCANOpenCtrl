#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QMetaEnum>

namespace Ui {
  class MainWindow;
}


class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

signals:
  void startReading();
  void moveMsgPassing(float);

private slots:
  void on_Connect_btn_clicked();
  void on_Read_btn_clicked();
  void on_Clear_btn_clicked();
  void on_pbT_Pos_clicked();
  void on_pb_STF_clicked();
  void on_cb_CyclePos_stateChanged(int arg1);
  void on_leT_Pos_returnPressed();
  void on_cb_Logging_stateChanged(int arg1);

public slots:
  void canToGui(unsigned char*, QString);
  void readErrToGui(QString r_err);
  void writeErrToGui(QString);

  void closeEvent(QCloseEvent *event);
};


class CAN_Reader : public QObject
{
  Q_OBJECT

signals:
  void readResPassing(unsigned char*, QString);
  void readErrPassing(QString);
  void moveMsgPassing(float);

  void restartReading();

public slots:
  void readCanFlow();
};


class CAN_Writer : public QObject
{
  Q_OBJECT

signals:
  void readResPassing(unsigned char*, QString);
  void writeErrPassing(QString);

public slots:
  void moveMsgToCan(float);
};

class CAN_Helper : public QObject
{
  Q_OBJECT

signals:
  void readAgain();

public slots:
  void execRestartReading();
};


#endif // MAINWINDOW_H
