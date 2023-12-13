#include "Registration.hpp"

Registration::Registration(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint) ,ui(new Ui::RegistrationClass())
{
    ui->setupUi(this);
	ui->PasswordInput->setEchoMode(QLineEdit::Password);
}

Registration::~Registration() { delete this->ui; }


void Registration::on_SignIn_clicked() {
	Database::getConnection()->setSchema("PassKeeper");

	Database::setPreparedStatement(Database::getConnection()->prepareStatement("select Login, HashedPassword from Users where Login = ?;"));

	std::string login = this->ui->LoginInput->text().toLocal8Bit().constData();
	Database::getPreparedStatement()->setString(1, login);

	Database::setResultSet(Database::getPreparedStatement()->executeQuery());

	Database::getResultSet()->next();

	try {
		if (Database::getResultSet()->getString(1) != login ||
			Database::getResultSet()->getString(2) != hashEncrypt(this->ui->PasswordInput->text().toLocal8Bit().constData()))
		{
			throw sql::InvalidArgumentException("Incorrect data");
		}
	}
	catch (sql::InvalidArgumentException error) {
		Database::setPreparedStatement(nullptr);
		Database::setResultSet(nullptr);
		
		this->ui->LoginInput->clear();
		this->ui->PasswordInput->clear();

		this->ui->LoginStatus->setStyleSheet("color: rgb(255, 224, 70);");
		this->ui->LoginStatus->setText("Incorrect login or password");
		return;
	}
	catch (...) {
		WarningMessage* warning = new WarningMessage();
		warning->unhandledExceptionError();
		abort();
	}

	this->ui->LoginStatus->setStyleSheet("color: rgb(170, 255, 127);");
	this->ui->LoginStatus->setText("Successfully");
	// redirect to the menu
}

void Registration::on_SignUp_clicked() {
	RegisterUser* registerUser = new RegisterUser();
	registerUser->show();
	hide();
}
