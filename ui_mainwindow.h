/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *Connect_btn;
    QPushButton *Read_btn;
    QPushButton *Clear_btn;
    QPushButton *pb_STF;
    QCheckBox *cb_SHTML;
    QCheckBox *cb_Logging;
    QFrame *line_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_5;
    QLineEdit *leT_Pos;
    QPushButton *pbT_Pos;
    QFrame *line_21;
    QLabel *label_4;
    QFrame *line_3;
    QCheckBox *cb_CyclePos;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(956, 814);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(551, 0));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(531, 0));
        QFont font;
        font.setFamily(QStringLiteral("Droid Sans Mono"));
        font.setPointSize(10);
        textBrowser->setFont(font);
        textBrowser->setAcceptDrops(false);
        textBrowser->setStyleSheet(QLatin1String("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: blue;"));
        textBrowser->setReadOnly(true);
        textBrowser->setAcceptRichText(false);
        textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
        textBrowser->setPlaceholderText(QStringLiteral(""));
        textBrowser->setOpenLinks(false);

        verticalLayout->addWidget(textBrowser);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Connect_btn = new QPushButton(groupBox);
        Connect_btn->setObjectName(QStringLiteral("Connect_btn"));

        horizontalLayout->addWidget(Connect_btn);

        Read_btn = new QPushButton(groupBox);
        Read_btn->setObjectName(QStringLiteral("Read_btn"));
        Read_btn->setEnabled(true);

        horizontalLayout->addWidget(Read_btn);

        Clear_btn = new QPushButton(groupBox);
        Clear_btn->setObjectName(QStringLiteral("Clear_btn"));

        horizontalLayout->addWidget(Clear_btn);

        pb_STF = new QPushButton(groupBox);
        pb_STF->setObjectName(QStringLiteral("pb_STF"));

        horizontalLayout->addWidget(pb_STF);

        cb_SHTML = new QCheckBox(groupBox);
        cb_SHTML->setObjectName(QStringLiteral("cb_SHTML"));

        horizontalLayout->addWidget(cb_SHTML);


        verticalLayout->addLayout(horizontalLayout);

        cb_Logging = new QCheckBox(groupBox);
        cb_Logging->setObjectName(QStringLiteral("cb_Logging"));
        cb_Logging->setChecked(true);

        verticalLayout->addWidget(cb_Logging);


        horizontalLayout_2->addWidget(groupBox);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);

        horizontalLayout_2->addWidget(line_2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(407, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        leT_Pos = new QLineEdit(groupBox_2);
        leT_Pos->setObjectName(QStringLiteral("leT_Pos"));
        leT_Pos->setMinimumSize(QSize(190, 0));
        leT_Pos->setMaximumSize(QSize(190, 16777215));
        leT_Pos->setStyleSheet(QLatin1String("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: blue;"));

        gridLayout_5->addWidget(leT_Pos, 0, 0, 1, 1);

        pbT_Pos = new QPushButton(groupBox_2);
        pbT_Pos->setObjectName(QStringLiteral("pbT_Pos"));
        pbT_Pos->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(pbT_Pos, 0, 3, 1, 1);

        line_21 = new QFrame(groupBox_2);
        line_21->setObjectName(QStringLiteral("line_21"));
        line_21->setFrameShadow(QFrame::Plain);
        line_21->setFrameShape(QFrame::VLine);

        gridLayout_5->addWidget(line_21, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_5);

        line_3 = new QFrame(groupBox_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        cb_CyclePos = new QCheckBox(groupBox_2);
        cb_CyclePos->setObjectName(QStringLiteral("cb_CyclePos"));

        verticalLayout_2->addWidget(cb_CyclePos);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(groupBox_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 956, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "CAN Bus Dataflow", Q_NULLPTR));
        Connect_btn->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        Read_btn->setText(QApplication::translate("MainWindow", "Start/stop reading", Q_NULLPTR));
        Clear_btn->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        pb_STF->setText(QApplication::translate("MainWindow", "Save to file", Q_NULLPTR));
        cb_SHTML->setText(QApplication::translate("MainWindow", "As HTML", Q_NULLPTR));
        cb_Logging->setText(QApplication::translate("MainWindow", "Logging canFlow to screen", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Settings and Control", Q_NULLPTR));
        leT_Pos->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pbT_Pos->setText(QApplication::translate("MainWindow", "Start moving", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "[m]", Q_NULLPTR));
        cb_CyclePos->setText(QApplication::translate("MainWindow", "Cycle CW <-> CCW", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
