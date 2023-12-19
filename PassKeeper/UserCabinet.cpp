#include "UserCabinet.hpp"

UserCabinet::UserCabinet(const unsigned int& id_, QWidget *parent)
			: QMainWindow(parent), ui(new Ui::UserCabinetClass())
{
	ui->setupUi(this);
	this->id = id_;

	unsigned int recordsCount = UserCabinet::getRecordsCount();

	if (recordsCount == CONDITION::ERROR) { return; }

	this->ui->RecordsCount->setStyleSheet("color: rgb(255, 255, 255);");
	this->ui->RecordsCount->setText("Your keeper records count: " + QString::number(recordsCount));
}

UserCabinet::~UserCabinet() { delete ui; }

Ui::UserCabinetClass* UserCabinet::getUi() const { return this->ui; }

int UserCabinet::getRecordsCount() {
	Database::setPreparedStatement(Database::getConnection()->prepareStatement("select count(*) "
																				"from PasswordsKeeper "
																				"where UserId = ?;"));
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


// actions

void UserCabinet::on_actionQuit_triggered() {
	this->hide();
	Registration* regMenu = new Registration();
	regMenu->show();
}

CONDITION UserCabinet::deleteUserFromTable(const char* query) {
	Database::setPreparedStatement(Database::getConnection()->prepareStatement(query));
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

	return CONDITION::NO_ERROR;
}

void UserCabinet::on_actionDeleteAccount_triggered() {

	if (UserCabinet::deleteUserFromTable("delete from Users "
										 "where Users.Id = ?; ") 
		== CONDITION::ERROR) { return; }

	if (UserCabinet::deleteUserFromTable("delete from PasswordsKeeper "
										 "where PasswordsKeeper.UserId = ?")
		== CONDITION::ERROR) { return; }

	this->on_actionQuit_triggered();
}
