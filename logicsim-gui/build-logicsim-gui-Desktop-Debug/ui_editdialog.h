/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_editDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *edtName;
    QLabel *lblName;

    void setupUi(QDialog *editDialog)
    {
        if (editDialog->objectName().isEmpty())
            editDialog->setObjectName(QString::fromUtf8("editDialog"));
        editDialog->resize(436, 297);
        buttonBox = new QDialogButtonBox(editDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        edtName = new QLineEdit(editDialog);
        edtName->setObjectName(QString::fromUtf8("edtName"));
        edtName->setGeometry(QRect(200, 40, 113, 26));
        lblName = new QLabel(editDialog);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        lblName->setGeometry(QRect(50, 50, 57, 16));

        retranslateUi(editDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), editDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), editDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(editDialog);
    } // setupUi

    void retranslateUi(QDialog *editDialog)
    {
        editDialog->setWindowTitle(QCoreApplication::translate("editDialog", "Dialog", nullptr));
        lblName->setText(QCoreApplication::translate("editDialog", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editDialog: public Ui_editDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
