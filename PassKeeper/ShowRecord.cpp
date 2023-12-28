#include "ShowRecord.hpp"

ShowRecord::ShowRecord(const unsigned int& userId_, QWidget *parent)
		   : QMainWindow(parent), ui(new Ui::ShowRecordClass()), userId(userId_)
{
	ui->setupUi(this);

    ShowRecord::setHeaders();

    getDataFromTable();
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

void ShowRecord::getDataFromTable() {
    try {
        Database::setPreparedStatement(Database::getConnection()->prepareStatement("select KeeperName, KeeperLogin, KeeperEmail, KeeperPassword, KeeperAdditionalInfo "
																				   "from PasswordsKeeper "
                                                                                   "where UserId = ?"));
        Database::getPreparedStatement()->setInt(1, this->userId);
        Database::setResultSet(Database::getPreparedStatement()->executeQuery());
    }
    catch (sql::SQLException error) {
        Database::setPreparedStatement(nullptr);
        Database::setResultSet(nullptr);

        this->ui->ErrorLabel->setText("Unable to get data from database!");
        return;
    }

    std::pair<std::string, std::string> keyNiv = getKeyNiv();

    for (;Database::getResultSet()->next();) {
        ShowRecord::addData(decrypt(Database::getResultSet()->getString(1), keyNiv.first, keyNiv.second).c_str(),
                            decrypt(Database::getResultSet()->getString(2), keyNiv.first, keyNiv.second).c_str(),
                            decrypt(Database::getResultSet()->getString(3), keyNiv.first, keyNiv.second).c_str(),
                            decrypt(Database::getResultSet()->getString(4), keyNiv.first, keyNiv.second).c_str(),
                            decrypt(Database::getResultSet()->getString(5), keyNiv.first, keyNiv.second).c_str());
    }

}
