#include "Record.hpp"

Record::Record(unsigned int& userId_, QWidget *parent)
	   : QMainWindow(parent, Qt::FramelessWindowHint) , ui(new Ui::RecordClass()), userId(userId_)
{
	ui->setupUi(this);
}

Record::~Record() {	delete ui; }

void Record::on_Close_clicked() {
	this->close();
	UserCabinet* userCab = new UserCabinet(this->userId);
	userCab->show();
}

void Record::on_ExitButton_clicked() { Record::on_Close_clicked(); }


void Record::on_SaveButton_clicked() {
	std::string keeperName, login, email, password, additionalInfo;

	keeperName = this->ui->NameLabel->text().toLocal8Bit().constData();
	login = this->ui->LoginLabel->text().toLocal8Bit().constData();
	email = this->ui->EmailLabel->text().toLocal8Bit().constData();
	password = this->ui->PasswordLabel->text().toLocal8Bit().constData();
	additionalInfo = this->ui->AdditionalInfoLabel->text().toLocal8Bit().constData();

	if (keeperName.empty() || password.empty()) {
		this->ui->StatusLabel->setText("Associated name or password is empty");
		return;
	}

	encryptKeeperRecordData(keeperName, login, email, password, additionalInfo);

	try {
		Database::setPreparedStatement(Database::getConnection()->prepareStatement("insert into PasswordsKeeper"
																				   "(UserId, KeeperName, KeeperLogin, KeeperEmail, KeeperPassword, KeeperAdditionalInfo) "
																				   "values (?, ?, ?, ?, ?, ?);"));

		Database::getPreparedStatement()->setInt(1, this->userId);
		Database::getPreparedStatement()->setString(2, keeperName);
		Database::getPreparedStatement()->setString(3, login);
		Database::getPreparedStatement()->setString(4, email);
		Database::getPreparedStatement()->setString(5, password);
		Database::getPreparedStatement()->setString(6, additionalInfo);

		Database::getPreparedStatement()->executeQuery();
	}
	catch (sql::SQLException error) {
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);

		this->ui->StatusLabel->setText("Oops!Something went wrong, better call developer");
		return;
	}

	// clear all labels
	Record::on_ClearButton_clicked();

	this->ui->StatusLabel->setStyleSheet("color: rgb(170, 255, 127);");
	this->ui->StatusLabel->setText("Saved");
}

void Record::on_ClearButton_clicked() {
	this->ui->NameLabel->clear();
	this->ui->LoginLabel->clear();
	this->ui->EmailLabel->clear();
	this->ui->PasswordLabel->clear();
	this->ui->AdditionalInfoLabel->clear();
}
