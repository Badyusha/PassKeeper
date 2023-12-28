#include "ShowRecord.hpp"

ShowRecord::ShowRecord(QWidget *parent)
		   : QMainWindow(parent), ui(new Ui::ShowRecordClass())
{
	ui->setupUi(this);

    ShowRecord::setHeaders();

    this->addData("John Doe", "johndoe", "john@example.com", "securePassword", "Additional Info");
}

ShowRecord::~ShowRecord() {	delete ui; }

void ShowRecord::setHeaders() {
    this->model = new QStandardItemModel(0, 6, this);

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Associated_Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Login"));
    model->setHeaderData(3, Qt::Horizontal, tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, tr("Password"));
    model->setHeaderData(5, Qt::Horizontal, tr("Additional_Info"));

    this->ui->tableView->setModel(model);

    // Make columns change size when window size has changed
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView->verticalHeader()->setDefaultSectionSize(30);

    const QString style_sheet = "QHeaderView::section {"
        "  color: rgb(255, 255, 255);"
        "  background-color: rgb(101, 97, 129);"
        "  text-align: center;"
        "  font: bold;"
        "  border: 1px solid rgb(77, 75, 99);"
        "}";
    this->ui->tableView->horizontalHeader()->setStyleSheet(style_sheet);
    this->ui->tableView->verticalHeader()->setStyleSheet(style_sheet);
}

void ShowRecord::addData(const QString& associatedName, const QString& login, const QString& email, const QString& password, const QString& additionalInfo) {
    QList<QStandardItem*> row;
    row << new QStandardItem(QString::number(1)) << new QStandardItem(associatedName) << new QStandardItem(login) << new QStandardItem(email) << new QStandardItem(password) << new QStandardItem(additionalInfo);

    // make data in table non modifiable
    for (QStandardItem* item : row) {
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    }

    model->appendRow(row);
}