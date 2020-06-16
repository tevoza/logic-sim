/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonAddInput;
    QPushButton *pushButtonAddWire;
    QPushButton *pushButtonAddAND;
    QPushButton *pushButtonAddXOR;
    QGraphicsView *graphicsView;
    QPushButton *pushButtonClose;
    QComboBox *comboBoxSource;
    QPushButton *pushButtonConnectNodes;
    QComboBox *comboBoxDest;
    QPushButton *pushButtonDisconnectNodes;
    QLineEdit *lineEditName;
    QLabel *label;
    QPushButton *pushButtonSetName;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonCalculateCircuit;
    QLabel *label_2;
    QPushButton *pushButtonDeleteNode;
    QPushButton *pushButtonAddOR;
    QPushButton *pushButtonAddNAND;
    QPushButton *pushButtonClear;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButtonTest;
    QPushButton *pushButtonAddNOR;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(851, 878);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonAddInput = new QPushButton(centralwidget);
        pushButtonAddInput->setObjectName(QString::fromUtf8("pushButtonAddInput"));
        pushButtonAddInput->setGeometry(QRect(0, 0, 61, 32));
        pushButtonAddWire = new QPushButton(centralwidget);
        pushButtonAddWire->setObjectName(QString::fromUtf8("pushButtonAddWire"));
        pushButtonAddWire->setGeometry(QRect(60, 0, 61, 32));
        pushButtonAddAND = new QPushButton(centralwidget);
        pushButtonAddAND->setObjectName(QString::fromUtf8("pushButtonAddAND"));
        pushButtonAddAND->setGeometry(QRect(120, 0, 51, 32));
        pushButtonAddXOR = new QPushButton(centralwidget);
        pushButtonAddXOR->setObjectName(QString::fromUtf8("pushButtonAddXOR"));
        pushButtonAddXOR->setGeometry(QRect(320, 0, 51, 32));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 831, 461));
        pushButtonClose = new QPushButton(centralwidget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(740, 0, 90, 32));
        comboBoxSource = new QComboBox(centralwidget);
        comboBoxSource->setObjectName(QString::fromUtf8("comboBoxSource"));
        comboBoxSource->setGeometry(QRect(20, 540, 251, 41));
        pushButtonConnectNodes = new QPushButton(centralwidget);
        pushButtonConnectNodes->setObjectName(QString::fromUtf8("pushButtonConnectNodes"));
        pushButtonConnectNodes->setGeometry(QRect(290, 540, 90, 32));
        comboBoxDest = new QComboBox(centralwidget);
        comboBoxDest->setObjectName(QString::fromUtf8("comboBoxDest"));
        comboBoxDest->setGeometry(QRect(390, 550, 211, 41));
        pushButtonDisconnectNodes = new QPushButton(centralwidget);
        pushButtonDisconnectNodes->setObjectName(QString::fromUtf8("pushButtonDisconnectNodes"));
        pushButtonDisconnectNodes->setGeometry(QRect(290, 570, 90, 32));
        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(90, 590, 113, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 600, 57, 16));
        pushButtonSetName = new QPushButton(centralwidget);
        pushButtonSetName->setObjectName(QString::fromUtf8("pushButtonSetName"));
        pushButtonSetName->setGeometry(QRect(220, 590, 41, 32));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 630, 256, 161));
        textBrowser->setReadOnly(true);
        pushButtonCalculateCircuit = new QPushButton(centralwidget);
        pushButtonCalculateCircuit->setObjectName(QString::fromUtf8("pushButtonCalculateCircuit"));
        pushButtonCalculateCircuit->setGeometry(QRect(510, 0, 131, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 490, 361, 41));
        pushButtonDeleteNode = new QPushButton(centralwidget);
        pushButtonDeleteNode->setObjectName(QString::fromUtf8("pushButtonDeleteNode"));
        pushButtonDeleteNode->setGeometry(QRect(20, 800, 251, 32));
        pushButtonDeleteNode->setFlat(false);
        pushButtonAddOR = new QPushButton(centralwidget);
        pushButtonAddOR->setObjectName(QString::fromUtf8("pushButtonAddOR"));
        pushButtonAddOR->setGeometry(QRect(220, 0, 51, 32));
        pushButtonAddNAND = new QPushButton(centralwidget);
        pushButtonAddNAND->setObjectName(QString::fromUtf8("pushButtonAddNAND"));
        pushButtonAddNAND->setGeometry(QRect(170, 0, 51, 32));
        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(650, 0, 90, 32));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 500, 181, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(340, 630, 361, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 660, 361, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 690, 361, 41));
        pushButtonTest = new QPushButton(centralwidget);
        pushButtonTest->setObjectName(QString::fromUtf8("pushButtonTest"));
        pushButtonTest->setGeometry(QRect(700, 570, 90, 32));
        pushButtonAddNOR = new QPushButton(centralwidget);
        pushButtonAddNOR->setObjectName(QString::fromUtf8("pushButtonAddNOR"));
        pushButtonAddNOR->setGeometry(QRect(270, 0, 51, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 851, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonClose, SIGNAL(clicked()), MainWindow, SLOT(close()));

        comboBoxSource->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonAddInput->setText(QCoreApplication::translate("MainWindow", "INPUT", nullptr));
        pushButtonAddWire->setText(QCoreApplication::translate("MainWindow", "WIRE", nullptr));
        pushButtonAddAND->setText(QCoreApplication::translate("MainWindow", "AND", nullptr));
        pushButtonAddXOR->setText(QCoreApplication::translate("MainWindow", "XOR", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        pushButtonConnectNodes->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        pushButtonDisconnectNodes->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Set Name: ", nullptr));
        pushButtonSetName->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">INFO</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">DOUBLE CLICK INPUTS to switch state.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Node Info - not necessary to set Node Names.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; "
                        "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButtonCalculateCircuit->setText(QCoreApplication::translate("MainWindow", "CALCULATE CIRCUIT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CONNECT/DISCONNECT LEFT NODE TO RIGHT(DIRECTED)", nullptr));
        pushButtonDeleteNode->setText(QCoreApplication::translate("MainWindow", "DELETE SELECTED NODE", nullptr));
        pushButtonAddOR->setText(QCoreApplication::translate("MainWindow", "OR", nullptr));
        pushButtonAddNAND->setText(QCoreApplication::translate("MainWindow", "NAND", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "SELECT NODE", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "GENERAL INFO", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "BLACK => OFF, GREEN => ON, YELLOW => UNDEFINED", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "DOUBLE CLICK INPUTS TO TOGGLE STATE", nullptr));
        pushButtonTest->setText(QCoreApplication::translate("MainWindow", "update", nullptr));
        pushButtonAddNOR->setText(QCoreApplication::translate("MainWindow", "NOR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
