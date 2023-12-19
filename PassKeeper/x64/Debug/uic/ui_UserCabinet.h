/********************************************************************************
** Form generated from reading UI file 'UserCabinet.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCABINET_H
#define UI_USERCABINET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserCabinetClass
{
public:
    QAction *actionCreate_new;
    QAction *actionModify;
    QAction *actionShow_all;
    QAction *actionFind_by;
    QAction *actionDelete;
    QAction *actionDeleteAccount;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *Login;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLabel *RecordsCount;
    QMenuBar *menuBar;
    QMenu *menuAccount;
    QMenu *menuKeeper;

    void setupUi(QMainWindow *UserCabinetClass)
    {
        if (UserCabinetClass->objectName().isEmpty())
            UserCabinetClass->setObjectName("UserCabinetClass");
        UserCabinetClass->resize(700, 425);
        UserCabinetClass->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);"));
        actionCreate_new = new QAction(UserCabinetClass);
        actionCreate_new->setObjectName("actionCreate_new");
        actionModify = new QAction(UserCabinetClass);
        actionModify->setObjectName("actionModify");
        actionShow_all = new QAction(UserCabinetClass);
        actionShow_all->setObjectName("actionShow_all");
        actionFind_by = new QAction(UserCabinetClass);
        actionFind_by->setObjectName("actionFind_by");
        actionDelete = new QAction(UserCabinetClass);
        actionDelete->setObjectName("actionDelete");
        actionDeleteAccount = new QAction(UserCabinetClass);
        actionDeleteAccount->setObjectName("actionDeleteAccount");
        actionQuit = new QAction(UserCabinetClass);
        actionQuit->setObjectName("actionQuit");
        centralWidget = new QWidget(UserCabinetClass);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        Login = new QLabel(centralWidget);
        Login->setObjectName("Login");
        Login->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        Login->setFont(font);
        Login->setStyleSheet(QString::fromUtf8("color: rgb(155, 155, 155);"));
        Login->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(Login, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        RecordsCount = new QLabel(centralWidget);
        RecordsCount->setObjectName("RecordsCount");
        RecordsCount->setFont(font);
        RecordsCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(RecordsCount, 0, 0, 1, 1);

        UserCabinetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserCabinetClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        menuBar->setStyleSheet(QString::fromUtf8("QMenuBar{\n"
"	color: rgb(255, 255, 255);\n"
"	selection-background-color:  rgb(111, 106, 141);\n"
"	background-color: rgb(101, 97, 129);\n"
"}\n"
"\n"
"QMenuBar::item::selected {\n"
"	background-color: rgb(111, 106, 141);\n"
"}\n"
"\n"
""));
        menuAccount = new QMenu(menuBar);
        menuAccount->setObjectName("menuAccount");
        menuAccount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(111, 106, 141);\n"
"background-color: rgb(101, 97, 129);\n"
""));
        menuKeeper = new QMenu(menuBar);
        menuKeeper->setObjectName("menuKeeper");
        menuKeeper->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(111, 106, 141);\n"
"background-color: rgb(101, 97, 129);"));
        UserCabinetClass->setMenuBar(menuBar);

        menuBar->addAction(menuKeeper->menuAction());
        menuBar->addAction(menuAccount->menuAction());
        menuAccount->addAction(actionDeleteAccount);
        menuAccount->addAction(actionQuit);
        menuKeeper->addAction(actionCreate_new);
        menuKeeper->addAction(actionModify);
        menuKeeper->addSeparator();
        menuKeeper->addAction(actionShow_all);
        menuKeeper->addAction(actionFind_by);
        menuKeeper->addSeparator();
        menuKeeper->addAction(actionDelete);

        retranslateUi(UserCabinetClass);

        QMetaObject::connectSlotsByName(UserCabinetClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserCabinetClass)
    {
        UserCabinetClass->setWindowTitle(QCoreApplication::translate("UserCabinetClass", "UserCabinet", nullptr));
        actionCreate_new->setText(QCoreApplication::translate("UserCabinetClass", "Create new", nullptr));
        actionModify->setText(QCoreApplication::translate("UserCabinetClass", "Modify", nullptr));
        actionShow_all->setText(QCoreApplication::translate("UserCabinetClass", "Show all", nullptr));
        actionFind_by->setText(QCoreApplication::translate("UserCabinetClass", "Find by...", nullptr));
        actionDelete->setText(QCoreApplication::translate("UserCabinetClass", "Delete", nullptr));
        actionDeleteAccount->setText(QCoreApplication::translate("UserCabinetClass", "Delete", nullptr));
        actionQuit->setText(QCoreApplication::translate("UserCabinetClass", "Quit", nullptr));
        Login->setText(QString());
        RecordsCount->setText(QString());
        menuAccount->setTitle(QCoreApplication::translate("UserCabinetClass", "Account", nullptr));
        menuKeeper->setTitle(QCoreApplication::translate("UserCabinetClass", "Keeper", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserCabinetClass: public Ui_UserCabinetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCABINET_H
