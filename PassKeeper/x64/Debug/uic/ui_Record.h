/********************************************************************************
** Form generated from reading UI file 'Record.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    QLineEdit *NameLabel;
    QLabel *Login;
    QLineEdit *LoginLabel;
    QLabel *Email;
    QLineEdit *EmailLabel;
    QLabel *Password;
    QLineEdit *PasswordLabel;
    QLabel *AddItionalInfo;
    QLineEdit *AdditioanlInfoLabel;
    QPushButton *SaveButton;
    QPushButton *ClearButton;
    QPushButton *ExitButton;
    QPushButton *Close;
    QLabel *ErrorLabel;

    void setupUi(QMainWindow *RecordClass)
    {
        if (RecordClass->objectName().isEmpty())
            RecordClass->setObjectName("RecordClass");
        RecordClass->resize(550, 400);
        RecordClass->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);"));
        centralWidget = new QWidget(RecordClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(130, 30, 301, 246));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Name = new QLabel(verticalLayoutWidget);
        Name->setObjectName("Name");
        QFont font;
        font.setBold(true);
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("color: rgb(155, 155, 155);"));

        verticalLayout->addWidget(Name);

        NameLabel = new QLineEdit(verticalLayoutWidget);
        NameLabel->setObjectName("NameLabel");
        NameLabel->setFont(font);
        NameLabel->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(NameLabel);

        Login = new QLabel(verticalLayoutWidget);
        Login->setObjectName("Login");
        Login->setFont(font);
        Login->setStyleSheet(QString::fromUtf8("color: rgb(155, 155, 155);"));

        verticalLayout->addWidget(Login);

        LoginLabel = new QLineEdit(verticalLayoutWidget);
        LoginLabel->setObjectName("LoginLabel");
        LoginLabel->setFont(font);
        LoginLabel->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(LoginLabel);

        Email = new QLabel(verticalLayoutWidget);
        Email->setObjectName("Email");
        Email->setFont(font);
        Email->setStyleSheet(QString::fromUtf8("color: rgb(155, 155, 155);"));

        verticalLayout->addWidget(Email);

        EmailLabel = new QLineEdit(verticalLayoutWidget);
        EmailLabel->setObjectName("EmailLabel");
        EmailLabel->setFont(font);
        EmailLabel->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(EmailLabel);

        Password = new QLabel(verticalLayoutWidget);
        Password->setObjectName("Password");
        Password->setFont(font);
        Password->setStyleSheet(QString::fromUtf8("color: rgb(155, 155, 155);"));

        verticalLayout->addWidget(Password);

        PasswordLabel = new QLineEdit(verticalLayoutWidget);
        PasswordLabel->setObjectName("PasswordLabel");
        PasswordLabel->setFont(font);
        PasswordLabel->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(PasswordLabel);

        AddItionalInfo = new QLabel(verticalLayoutWidget);
        AddItionalInfo->setObjectName("AddItionalInfo");
        AddItionalInfo->setFont(font);
        AddItionalInfo->setStyleSheet(QString::fromUtf8("color: rgb(155, 155, 155);"));

        verticalLayout->addWidget(AddItionalInfo);

        AdditioanlInfoLabel = new QLineEdit(verticalLayoutWidget);
        AdditioanlInfoLabel->setObjectName("AdditioanlInfoLabel");
        AdditioanlInfoLabel->setFont(font);
        AdditioanlInfoLabel->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(AdditioanlInfoLabel);

        SaveButton = new QPushButton(centralWidget);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setGeometry(QRect(130, 300, 80, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        SaveButton->setFont(font1);
        SaveButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        ClearButton = new QPushButton(centralWidget);
        ClearButton->setObjectName("ClearButton");
        ClearButton->setGeometry(QRect(240, 300, 80, 30));
        ClearButton->setFont(font1);
        ClearButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setGeometry(QRect(350, 300, 80, 30));
        ExitButton->setFont(font1);
        ExitButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        Close = new QPushButton(centralWidget);
        Close->setObjectName("Close");
        Close->setGeometry(QRect(520, 0, 31, 24));
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
        ErrorLabel = new QLabel(centralWidget);
        ErrorLabel->setObjectName("ErrorLabel");
        ErrorLabel->setGeometry(QRect(10, 350, 531, 20));
        ErrorLabel->setFont(font);
        ErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 224, 70);"));
        ErrorLabel->setAlignment(Qt::AlignCenter);
        RecordClass->setCentralWidget(centralWidget);

        retranslateUi(RecordClass);

        QMetaObject::connectSlotsByName(RecordClass);
    } // setupUi

    void retranslateUi(QMainWindow *RecordClass)
    {
        RecordClass->setWindowTitle(QCoreApplication::translate("RecordClass", "Record", nullptr));
        Name->setText(QCoreApplication::translate("RecordClass", "Associated platform/site name", nullptr));
        Login->setText(QCoreApplication::translate("RecordClass", "Login (not necessary)", nullptr));
        Email->setText(QCoreApplication::translate("RecordClass", "Email (not necessary)", nullptr));
        Password->setText(QCoreApplication::translate("RecordClass", "Password", nullptr));
        AddItionalInfo->setText(QCoreApplication::translate("RecordClass", "Additional Info (not necessary)", nullptr));
        SaveButton->setText(QCoreApplication::translate("RecordClass", "Save", nullptr));
        ClearButton->setText(QCoreApplication::translate("RecordClass", "Clear", nullptr));
        ExitButton->setText(QCoreApplication::translate("RecordClass", "Exit", nullptr));
        Close->setText(QString());
        ErrorLabel->setText(QCoreApplication::translate("RecordClass", "Error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordClass: public Ui_RecordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
