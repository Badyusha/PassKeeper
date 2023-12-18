#include "UserCabinet.hpp"

UserCabinet::UserCabinet(const uint64_t& id_, QWidget *parent)
			: QMainWindow(parent), ui(new Ui::UserCabinetClass())
{
	ui->setupUi(this);
	this->id = id_;

	int recordsCount = getRecordsCount();

	if (recordsCount == CONDITION::ERROR) { return; }

	this->ui->RecordsCount->setStyleSheet("color: rgb(255, 255, 255);");
	this->ui->RecordsCount->setText("Your keeper records count: " + QString::number(recordsCount));
}

UserCabinet::~UserCabinet() { delete ui; }

Ui::UserCabinetClass* UserCabinet::getUi() const { return this->ui; }

int UserCabinet::getRecordsCount() {
	Database::setPreparedStatement(Database::getConnection()->prepareStatement("select count(*) from PasswordsKeeper where UserId = ?;"));
	Database::getPreparedStatement()->setInt(1, this->id);

	try {
		Database::setResultSet(Database::getPreparedStatement()->executeQuery());
		Database::getResultSet()->next();
	}
	catch (sql::SQLException error) {
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);

		this->ui->RecordsCount->setStyleSheet("color: rgb(255, 224, 70);");
		this->ui->RecordsCount->setText("Oops! Something went wrong");
		return CONDITION::ERROR;
	}

	return Database::getResultSet()->getInt(1);
}
