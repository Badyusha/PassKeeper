/********************************************************************************
** Form generated from reading UI file 'WarningMessage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGMESSAGE_H
#define UI_WARNINGMESSAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarningMessageClass
{
public:
    QWidget *centralWidget;
    QPushButton *Close;
    QLabel *WarningMessage;
    QLabel *warning;
    QLabel *ErrorCode;
    QPushButton *OkButton;

    void setupUi(QMainWindow *WarningMessageClass)
    {
        if (WarningMessageClass->objectName().isEmpty())
            WarningMessageClass->setObjectName("WarningMessageClass");
        WarningMessageClass->resize(285, 170);
        WarningMessageClass->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);"));
        centralWidget = new QWidget(WarningMessageClass);
        centralWidget->setObjectName("centralWidget");
        Close = new QPushButton(centralWidget);
        Close->setObjectName("Close");
        Close->setGeometry(QRect(255, 0, 31, 24));
        Close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: none;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(80, 80, 80);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(90, 90, 90);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        Close->setIcon(icon);
        Close->setIconSize(QSize(12, 12));
        WarningMessage = new QLabel(centralWidget);
        WarningMessage->setObjectName("WarningMessage");
        WarningMessage->setGeometry(QRect(47, 50, 190, 31));
        QFont font;
        font.setBold(true);
        WarningMessage->setFont(font);
        WarningMessage->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        WarningMessage->setScaledContents(true);
        WarningMessage->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        WarningMessage->setWordWrap(true);
        warning = new QLabel(centralWidget);
        warning->setObjectName("warning");
        warning->setGeometry(QRect(42, 20, 200, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        warning->setFont(font1);
        warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 224, 70);"));
        warning->setAlignment(Qt::AlignCenter);
        ErrorCode = new QLabel(centralWidget);
        ErrorCode->setObjectName("ErrorCode");
        ErrorCode->setGeometry(QRect(5, 90, 281, 20));
        ErrorCode->setFont(font);
        ErrorCode->setStyleSheet(QString::fromUtf8("color: rgb(255, 224, 70);"));
        ErrorCode->setScaledContents(true);
        ErrorCode->setAlignment(Qt::AlignCenter);
        OkButton = new QPushButton(centralWidget);
        OkButton->setObjectName("OkButton");
        OkButton->setGeometry(QRect(112, 123, 60, 30));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        OkButton->setFont(font2);
        OkButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(111, 106, 141);\n"
"	border: none;\n"
"	border-radius: 13px;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(105, 101, 134);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(101, 97, 129);\n"
"}"));
        WarningMessageClass->setCentralWidget(centralWidget);

        retranslateUi(WarningMessageClass);

        QMetaObject::connectSlotsByName(WarningMessageClass);
    } // setupUi

    void retranslateUi(QMainWindow *WarningMessageClass)
    {
        WarningMessageClass->setWindowTitle(QCoreApplication::translate("WarningMessageClass", "WarningMessage", nullptr));
        Close->setText(QString());
        WarningMessage->setText(QString());
        warning->setText(QCoreApplication::translate("WarningMessageClass", "Warning!", nullptr));
        ErrorCode->setText(QString());
        OkButton->setText(QCoreApplication::translate("WarningMessageClass", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningMessageClass: public Ui_WarningMessageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGMESSAGE_H
