/********************************************************************************
** Form generated from reading UI file 'ShowRecord.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWRECORD_H
#define UI_SHOWRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowRecordClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *ErrorLabel;
    QTableView *tableView;

    void setupUi(QMainWindow *ShowRecordClass)
    {
        if (ShowRecordClass->objectName().isEmpty())
            ShowRecordClass->setObjectName("ShowRecordClass");
        ShowRecordClass->resize(859, 570);
        ShowRecordClass->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);"));
        centralWidget = new QWidget(ShowRecordClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("border: none;"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("/* VERTICAL SCROLLBAR */\n"
" QScrollBar:vertical {\n"
"	border: none;\n"
"	background-color: rgb(65, 65, 65);\n"
"    width: 14px;\n"
"    margin: 15px 0 15px 0;\n"
"	border-radius: 0px;\n"
" }\n"
"\n"
"/*  HANDLE BAR VERTICAL */\n"
"QScrollBar::handle:vertical {	\n"
"	background-color: rgb(105, 101, 134);\n"
"	min-height: 30px;\n"
"	border-radius: 7px;\n"
"}\n"
"QScrollBar::handle:vertical:hover{	\n"
"	background-color: rgb(111, 106, 141);\n"
"}\n"
"QScrollBar::handle:vertical:pressed {	\n"
"	background-color: rgb(101, 97, 129);\n"
"}\n"
"\n"
"/* BTN TOP - SCROLLBAR */\n"
"QScrollBar::sub-line:vertical {\n"
"	border: none;\n"
"	background-color: rgb(65, 65, 65);\n"
"	height: 15px;\n"
"	border-top-left-radius: 7px;\n"
"	border-top-right-radius: 7px;\n"
"	subcontrol-position: top;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical:hover {	\n"
"	background-color: rgb(111, 106, 141);\n"
"}\n"
"QScrollBar::sub-line:vertical:pressed {	\n"
"	background-color: rgb(101, 97, 129);\n"
"}\n"
"\n"
"/"
                        "* BTN BOTTOM - SCROLLBAR */\n"
"QScrollBar::add-line:vertical {\n"
"	border: none;\n"
"	background-color: rgb(65, 65, 65);\n"
"	height: 15px;\n"
"	border-bottom-left-radius: 7px;\n"
"	border-bottom-right-radius: 7px;\n"
"	subcontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-line:vertical:hover {	\n"
"	background-color: rgb(111, 106, 141);\n"
"}\n"
"QScrollBar::add-line:vertical:pressed {	\n"
"	background-color: rgb(101, 97, 129);\n"
"}\n"
"\n"
"/* RESET ARROW */\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"	background: none;\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"	background: none;\n"
"}\n"
"\n"
"/* HORIZONTAL SCROLLBAR - HOMEWORK */\n"
"QScrollBar:horizontal {\n"
"    margin: 15px 0 15px 0;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 827, 5040));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        ErrorLabel = new QLabel(scrollAreaWidgetContents);
        ErrorLabel->setObjectName("ErrorLabel");
        QFont font;
        font.setBold(true);
        ErrorLabel->setFont(font);
        ErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 224, 70)"));
        ErrorLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ErrorLabel);

        tableView = new QTableView(scrollAreaWidgetContents);
        tableView->setObjectName("tableView");
        tableView->setMinimumSize(QSize(0, 5000));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"text-align: center;\n"
"border: none;\n"
"font: bold;\n"
"\n"
"QTableView::item:selected{\n"
"	background-color: rgb(101, 97, 129);\n"
"}"));

        verticalLayout_2->addWidget(tableView);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        ShowRecordClass->setCentralWidget(centralWidget);

        retranslateUi(ShowRecordClass);

        QMetaObject::connectSlotsByName(ShowRecordClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShowRecordClass)
    {
        ShowRecordClass->setWindowTitle(QCoreApplication::translate("ShowRecordClass", "ShowRecord", nullptr));
        ErrorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShowRecordClass: public Ui_ShowRecordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWRECORD_H
