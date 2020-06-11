/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QPushButton *pushButtonClose;
    QComboBox *comboBoxSource;
    QPushButton *pushButton_2;
    QComboBox *comboBoxDest;
    QPushButton *pushButton_3;
    QLineEdit *lineEditName;
    QLabel *label;
    QPushButton *pushButtonSetName;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1019, 815);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonAddInput = new QPushButton(centralwidget);
        pushButtonAddInput->setObjectName(QString::fromUtf8("pushButtonAddInput"));
        pushButtonAddInput->setGeometry(QRect(0, 0, 90, 32));
        pushButtonAddWire = new QPushButton(centralwidget);
        pushButtonAddWire->setObjectName(QString::fromUtf8("pushButtonAddWire"));
        pushButtonAddWire->setGeometry(QRect(90, 0, 90, 32));
        pushButtonAddAND = new QPushButton(centralwidget);
        pushButtonAddAND->setObjectName(QString::fromUtf8("pushButtonAddAND"));
        pushButtonAddAND->setGeometry(QRect(180, 0, 90, 32));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 0, 90, 32));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 831, 431));
        pushButtonClose = new QPushButton(centralwidget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(360, 0, 90, 32));
        comboBoxSource = new QComboBox(centralwidget);
        comboBoxSource->setObjectName(QString::fromUtf8("comboBoxSource"));
        comboBoxSource->setGeometry(QRect(20, 480, 211, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 470, 90, 32));
        comboBoxDest = new QComboBox(centralwidget);
        comboBoxDest->setObjectName(QString::fromUtf8("comboBoxDest"));
        comboBoxDest->setGeometry(QRect(370, 480, 211, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 500, 90, 32));
        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(70, 540, 113, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 550, 57, 16));
        pushButtonSetName = new QPushButton(centralwidget);
        pushButtonSetName->setObjectName(QString::fromUtf8("pushButtonSetName"));
        pushButtonSetName->setGeometry(QRect(210, 540, 41, 32));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 580, 256, 192));
        textBrowser->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1019, 28));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonAddInput->setText(QApplication::translate("MainWindow", "Input", nullptr));
        pushButtonAddWire->setText(QApplication::translate("MainWindow", "Wire", nullptr));
        pushButtonAddAND->setText(QApplication::translate("MainWindow", "AND", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "XOR", nullptr));
        pushButtonClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "->", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "X", nullptr));
        label->setText(QApplication::translate("MainWindow", "Name: ", nullptr));
        pushButtonSetName->setText(QApplication::translate("MainWindow", "Set", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">kk</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">kk</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k</p>\n"
"<"
                        "p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">kkk</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">k</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">kk</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\">k</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
