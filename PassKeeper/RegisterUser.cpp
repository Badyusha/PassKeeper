#include "RegisterUser.hpp"


RegisterUser::RegisterUser(QWidget* parent)
	: QWidget(parent, Qt::FramelessWindowHint), ui(new Ui::RegisterUserClass())
{
	ui->setupUi(this);
	ui->PasswordInput->setEchoMode(QLineEdit::Password);
	ui->RepeatPasswordInput->setEchoMode(QLineEdit::Password);
}


RegisterUser::~RegisterUser() { delete this->ui; }


void RegisterUser::errorLoginingMessage(const QString& errorMessage) {
	this->ui->PasswordInput->clear();
	this->ui->RepeatPasswordInput->clear();

	this->ui->LoginStatus->setStyleSheet("color: rgb(255, 224, 70);"); // set yellow color text
	this->ui->LoginStatus->setText(errorMessage);
}

int RegisterUser::loginAlreadyExists() {
	Database::setPreparedStatement(Database::getConnection()->prepareStatement("select count(*) "
																				"from Users "
																				"where Login = ?;"));

	std::string login = this->ui->LoginInput->text().toLocal8Bit().data();
	Database::getPreparedStatement()->setString(1, login);

	try {
		Database::setResultSet(Database::getPreparedStatement()->executeQuery());
		Database::getResultSet()->next();
	}
	catch (sql::SQLException error) { 
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);

		this->ui->LoginInput->clear();
		RegisterUser::errorLoginingMessage("Oops! Something went wrong");
		return CONDITION::ERROR;
	}

	if (Database::getResultSet()->getInt(1)) {
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);

		this->ui->LoginInput->clear();
		RegisterUser::errorLoginingMessage("User with this login already exists\nChoose another one");
		return CONDITION::ERROR;
	}

	return CONDITION::NO_ERROR;
}

CONDITION RegisterUser::enteredDataIsIncorrect() {
	if (RegisterUser::loginAlreadyExists() == CONDITION::ERROR) { return CONDITION::ERROR; }

	int loginStrLength = this->ui->LoginInput->text().size();
	int passwordStrLength = this->ui->PasswordInput->text().size();

	if (loginStrLength < LEN_NUM::MIN_LOGIN_CHARACTERS) {
		this->ui->LoginInput->clear();
		RegisterUser::errorLoginingMessage("Login is too short");
		return CONDITION::ERROR;
	}

	if (loginStrLength > LEN_NUM::MAX_LOGIN_CHARACTERS) {
		this->ui->LoginInput->clear();
		RegisterUser::errorLoginingMessage("Login is too long");
		return CONDITION::ERROR;
	}

	if (passwordStrLength < LEN_NUM::MIN_PASSWORD_CHARACTERS) {
		RegisterUser::errorLoginingMessage("Password is too short");
		return CONDITION::ERROR;
	}

	if (passwordStrLength > LEN_NUM::MAX_PASSWORD_CHARACTERS) {
		RegisterUser::errorLoginingMessage("Password is too long");
		return CONDITION::ERROR;
	}

	if (this->ui->PasswordInput->text() != this->ui->RepeatPasswordInput->text()) {
		RegisterUser::errorLoginingMessage("Passwords does not match");
		return CONDITION::ERROR;
	}
	return CONDITION::NO_ERROR;
}

void RegisterUser::on_SignUp_clicked() {
	Database::getConnection()->setSchema("PassKeeper");

	if (enteredDataIsIncorrect()) { return; }

	Database::setPreparedStatement(Database::getConnection()->prepareStatement("insert into Users(Login, HashedPassword) values (?, ?);"));
	
	std::string login = this->ui->LoginInput->text().toLocal8Bit().constData();
	Database::getPreparedStatement()->setString(1, login);
	Database::getPreparedStatement()->setString(2, hashEncrypt(this->ui->PasswordInput->text().toLocal8Bit().constData()));

	try {
		Database::getPreparedStatement()->executeQuery();
	}
	catch (sql::SQLException error) {
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);

		this->ui->LoginInput->clear();
		RegisterUser::errorLoginingMessage("Oops! Something went wrong\nMake sure there are no russian letters");
		return;
	}

	this->hide();

	//this->ui->LoginStatus->setStyleSheet("color: rgb(170, 255, 127);"); // set green color text
	//this->ui->LoginStatus->setText("Successfully");

	Database::setPreparedStatement(Database::getConnection()->prepareStatement("select Id from Users where Login = ?;"));
	Database::getPreparedStatement()->setString(1, this->ui->LoginInput->text().toLocal8Bit().constData());

	try {
		Database::setResultSet(Database::getPreparedStatement()->executeQuery());
		Database::getResultSet()->next();
	}
	catch (sql::SQLException error) {
		WarningMessage* warning = new WarningMessage();
		warning->unhandledExceptionError();

		this->hide();
		warning->show();
		return;
	}
	// redirect to menu
	UserCabinet* userCab = new UserCabinet(Database::getResultSet()->getUInt64(1));
	userCab->getUi()->Login->setText(login.c_str());
	userCab->show();
}
