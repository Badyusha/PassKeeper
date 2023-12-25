#include "UserCabinet.hpp"



UserCabinet::UserCabinet(const unsigned int& id_, QWidget *parent)
			: QMainWindow(parent), ui(new Ui::UserCabinetClass()), id(id_)
{
	ui->setupUi(this);

	connect(this->ui->actionDeleteAccount, &QAction::triggered, this, &UserCabinet::on_actionDeleteAccount_triggered);

	unsigned int recordsCount = UserCabinet::getRecordsCount();

	if (recordsCount == CONDITION::ERROR) { return; }

	this->ui->RecordsCount->setStyleSheet("color: rgb(255, 255, 255);");
	this->ui->RecordsCount->setText("Your keeper records count: " + QString::number(recordsCount));

	// set login into status bar
	try {
		Database::setPreparedStatement(Database::getConnection()->prepareStatement("select Login from Users "
																				   "where Id = ?"));
		Database::getPreparedStatement()->setInt(1, this->id);

		Database::setResultSet(Database::getPreparedStatement()->executeQuery());
		Database::getResultSet()->next();
	}
	catch (sql::SQLException error) {
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);

		this->ui->Login->setStyleSheet("color; rgb(255, 224, 70);");
		this->ui->Login->setText("Error occured while executing query");
		return;
	}

	this->ui->Login->setText(Database::getResultSet()->getString(1).c_str());
}

UserCabinet::~UserCabinet() { delete ui; }

Ui::UserCabinetClass* UserCabinet::getUi() const { return this->ui; }

int UserCabinet::getRecordsCount() {
	try {
		Database::setPreparedStatement(Database::getConnection()->prepareStatement("select count(*) "
																					"from PasswordsKeeper "
																					"where UserId = ?;"));
		Database::getPreparedStatement()->setInt(1, this->id);

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
	try {
		Database::setPreparedStatement(Database::getConnection()->prepareStatement(query));
		Database::getPreparedStatement()->setInt(1, this->id);

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


void UserCabinet::onButtonClicked(const WARNING_MESSAGE& buttonId) {
	if (buttonId == WARNING_MESSAGE::CLOSE_BUTTON) { return; }

	if (UserCabinet::deleteUserFromTable("delete from Users "
										 "where Users.Id = ?;")
		== CONDITION::ERROR) { return; }

	if (UserCabinet::deleteUserFromTable("delete from PasswordsKeeper "
										 "where PasswordsKeeper.UserId = ?")
		== CONDITION::ERROR) { return; }

	this->on_actionQuit_triggered();
}

void UserCabinet::on_actionDeleteAccount_triggered() {
	// // realization with QMessageBox
	/*QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Deleting account", "R u sure?",
		QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::Yes) {
		qDebug() << "Deleted";
		this->on_actionQuit_triggered();
	}
	else {
		qDebug() << "Canceled";
	}*/


	// all this code is to avoid double warning window appearing
	QList<WarningMessage*> warningMessages = this->findChildren<WarningMessage*>();

	if (!warningMessages.isEmpty()) { 
		// Если найдено, используем первый экземпляр
		WarningMessage* existingWarningMessage = warningMessages.first();
		existingWarningMessage->show();
		return;
	}

	// Если не найдено, создаем новое окно
	WarningMessage* newWarningMessage = new WarningMessage(this);
	newWarningMessage->getUi()->WarningMessage->setText("The hardest choices require the strongest wills");
	newWarningMessage->getUi()->ErrorCode->setText("OK if you wanna delete account, cross if not");

	// Создаем локальное соединение с destroyed
	QObject::connect(newWarningMessage, &QObject::destroyed, this, [this, newWarningMessage]() {
		// Обнуляем указатель после уничтожения объекта
		Q_UNUSED("newWarningMessage");
		});

	connect(newWarningMessage, &WarningMessage::buttonClicked, this, &UserCabinet::onButtonClicked);
	newWarningMessage->show();
}



void UserCabinet::on_actionCreate_new_triggered() {
	this->hide();
	Record* record = new Record(this->id);
	record->show();
}

void UserCabinet::on_actionModify_triggered() {
	this->hide();

}
