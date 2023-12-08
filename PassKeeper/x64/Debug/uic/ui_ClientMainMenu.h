/********************************************************************************
** Form generated from reading UI file 'ClientMainMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMAINMENU_H
#define UI_CLIENTMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientMainMenuClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientMainMenuClass)
    {
        if (ClientMainMenuClass->objectName().isEmpty())
            ClientMainMenuClass->setObjectName("ClientMainMenuClass");
        ClientMainMenuClass->resize(600, 400);
        menuBar = new QMenuBar(ClientMainMenuClass);
        menuBar->setObjectName("menuBar");
        ClientMainMenuClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientMainMenuClass);
        mainToolBar->setObjectName("mainToolBar");
        ClientMainMenuClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ClientMainMenuClass);
        centralWidget->setObjectName("centralWidget");
        ClientMainMenuClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ClientMainMenuClass);
        statusBar->setObjectName("statusBar");
        ClientMainMenuClass->setStatusBar(statusBar);

        retranslateUi(ClientMainMenuClass);

        QMetaObject::connectSlotsByName(ClientMainMenuClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClientMainMenuClass)
    {
        ClientMainMenuClass->setWindowTitle(QCoreApplication::translate("ClientMainMenuClass", "ClientMainMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientMainMenuClass: public Ui_ClientMainMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMAINMENU_H
