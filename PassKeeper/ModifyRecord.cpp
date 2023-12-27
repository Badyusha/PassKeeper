#include "ModifyRecord.hpp"

ModifyRecord::ModifyRecord(unsigned int& userId_, QWidget *parent)
			 : QMainWindow(parent), ui(new Ui::ModifyRecordClass()), userId(userId_)
{
	ui->setupUi(this);

    QStandardItemModel* new_model = new QStandardItemModel(0, 5, this);

    new_model->setHeaderData(0, Qt::Horizontal, tr("Associated_Name"));
    new_model->setHeaderData(1, Qt::Horizontal, tr("Login"));
    new_model->setHeaderData(2, Qt::Horizontal, tr("Email"));
    new_model->setHeaderData(3, Qt::Horizontal, tr("Password"));
    new_model->setHeaderData(4, Qt::Horizontal, tr("Additional_Info"));
    this->ui->tableView->setModel(new_model);

    // make columns change size when window size have changed
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    new_model->insertRow(new_model->rowCount());

    const QString style_sheet = "QHeaderView::section {" // dont know how to setup this shit in ui
        "  color: rgb(255, 255, 255);"
        "  background-color: rgb(101, 97, 129);"
        "  text-align: center;"
        "  font: bold;"
        "  border: 1px solid rgb(77, 75, 99);"
        "}";
    this->ui->tableView->horizontalHeader()->setStyleSheet(style_sheet);
    this->ui->tableView->verticalHeader()->setStyleSheet(style_sheet);

}

ModifyRecord::~ModifyRecord() {	delete ui; }
