/********************************************************************************
** Form generated from reading UI file 'RegisterUser.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSER_H
#define UI_REGISTERUSER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterUserClass
{
public:
    QPushButton *SignUp;
    QLabel *LoginStatus;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Login;
    QLabel *Password;
    QLabel *RepeatPassword;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *LoginInput;
    QLineEdit *PasswordInput;
    QLineEdit *RepeatPasswordInput;
    QPushButton *Close_2;

    void setupUi(QWidget *RegisterUserClass)
    {
        if (RegisterUserClass->objectName().isEmpty())
            RegisterUserClass->setObjectName("RegisterUserClass");
        RegisterUserClass->resize(500, 270);
        RegisterUserClass->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);"));
        SignUp = new QPushButton(RegisterUserClass);
        SignUp->setObjectName("SignUp");
        SignUp->setGeometry(QRect(210, 180, 80, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        SignUp->setFont(font);
        SignUp->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        LoginStatus = new QLabel(RegisterUserClass);
        LoginStatus->setObjectName("LoginStatus");
        LoginStatus->setGeometry(QRect(10, 225, 481, 16));
        QFont font1;
        font1.setBold(true);
        LoginStatus->setFont(font1);
        LoginStatus->setStyleSheet(QString::fromUtf8("color: rgb(170, 255, 127);"));
        LoginStatus->setAlignment(Qt::AlignCenter);
        formLayoutWidget_2 = new QWidget(RegisterUserClass);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(70, 60, 341, 90));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        formLayout_2->setHorizontalSpacing(3);
        formLayout_2->setVerticalSpacing(3);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        Login = new QLabel(formLayoutWidget_2);
        Login->setObjectName("Login");
        Login->setFont(font);
        Login->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(Login);

        Password = new QLabel(formLayoutWidget_2);
        Password->setObjectName("Password");
        Password->setFont(font);
        Password->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(Password);

        RepeatPassword = new QLabel(formLayoutWidget_2);
        RepeatPassword->setObjectName("RepeatPassword");
        RepeatPassword->setFont(font);
        RepeatPassword->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(RepeatPassword);


        horizontalLayout->addLayout(verticalLayout);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(7);
        formLayout->setVerticalSpacing(9);
        formLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        LoginInput = new QLineEdit(formLayoutWidget_2);
        LoginInput->setObjectName("LoginInput");
        LoginInput->setFont(font1);
        LoginInput->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, LoginInput);

        PasswordInput = new QLineEdit(formLayoutWidget_2);
        PasswordInput->setObjectName("PasswordInput");
        PasswordInput->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, PasswordInput);

        RepeatPasswordInput = new QLineEdit(formLayoutWidget_2);
        RepeatPasswordInput->setObjectName("RepeatPasswordInput");
        RepeatPasswordInput->setStyleSheet(QString::fromUtf8("border:2px solid rgb(111, 106, 141);\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, RepeatPasswordInput);


        horizontalLayout_4->addLayout(formLayout);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        Close_2 = new QPushButton(RegisterUserClass);
        Close_2->setObjectName("Close_2");
        Close_2->setGeometry(QRect(470, 0, 31, 24));
        Close_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        Close_2->setIcon(icon);
        Close_2->setIconSize(QSize(12, 12));

        retranslateUi(RegisterUserClass);
        QObject::connect(Close_2, &QPushButton::clicked, RegisterUserClass, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(RegisterUserClass);
    } // setupUi

    void retranslateUi(QWidget *RegisterUserClass)
    {
        RegisterUserClass->setWindowTitle(QCoreApplication::translate("RegisterUserClass", "RegisterUser", nullptr));
        SignUp->setText(QCoreApplication::translate("RegisterUserClass", "Sign Up", nullptr));
        LoginStatus->setText(QString());
        Login->setText(QCoreApplication::translate("RegisterUserClass", "Login", nullptr));
        Password->setText(QCoreApplication::translate("RegisterUserClass", "Password", nullptr));
        RepeatPassword->setText(QCoreApplication::translate("RegisterUserClass", "Repeat Password", nullptr));
        Close_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterUserClass: public Ui_RegisterUserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSER_H
