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

	this->ui->LoginStatus->setStyleSheet("color: rgb(255, 224, 70);"); // set red color text
	this->ui->LoginStatus->setText(errorMessage);
}


CONDITION RegisterUser::enteredDataIsIncorrect() {
	if (this->ui->LoginInput->text().size() < LEN_NUM::MIN_LOGIN_CHARACTERS) {
		this->ui->LoginInput->clear();
		errorLoginingMessage("Login is too short");
		return CONDITION::ERROR;
	}

	if (this->ui->LoginInput->text().size() > LEN_NUM::MAX_LOGIN_CHARACTERS) {
		this->ui->LoginInput->clear();
		errorLoginingMessage("Login is too long");
		return CONDITION::ERROR;
	}

	if (this->ui->PasswordInput->text().size() < LEN_NUM::MIN_PASSWORD_CHARACTERS) {
		errorLoginingMessage("Password is too short");
		return CONDITION::ERROR;
	}

	if (this->ui->PasswordInput->text().size() > LEN_NUM::MAX_PASSWORD_CHARACTERS) {
		errorLoginingMessage("Password is too long");
		return CONDITION::ERROR;
	}

	if (this->ui->PasswordInput->text().size() != this->ui->RepeatPasswordInput->text().size()) {
		errorLoginingMessage("Passwords does not match");
		return CONDITION::ERROR;
	}
	return CONDITION::NO_ERROR;
}

void RegisterUser::on_SignUp_clicked() {
	if (enteredDataIsIncorrect()) { return; }

	Database::getConnection()->setSchema("PassKeeper");

	Database::setPreparedStatement(Database::getConnection()->prepareStatement("insert into Users(Login, HashedPassword) values (?, ?);"));
	Database::getPreparedStatement()->setString(1, this->ui->LoginInput->text().toLocal8Bit().constData());
	Database::getPreparedStatement()->setString(2, hashEncrypt(this->ui->PasswordInput->text().toLocal8Bit().constData()));

	try {
		Database::getPreparedStatement()->execute();
	}
	catch (sql::InvalidArgumentException error) {
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);

		this->ui->LoginInput->clear();
		this->ui->PasswordInput->clear();

		this->ui->LoginStatus->setStyleSheet("color: rgb(255, 224, 70);"); // set red color text
		this->ui->LoginStatus->setText("Oops! Something went wrong");
		return;
	}

	this->ui->LoginStatus->setStyleSheet("color: rgb(170, 255, 127);"); // set green color text
	this->ui->LoginStatus->setText("Successfully");

	// redirect to menu
}
