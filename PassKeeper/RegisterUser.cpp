#include "RegisterUser.hpp"


RegisterUser::RegisterUser(Database* database, QWidget* parent)
	: QWidget(parent, Qt::FramelessWindowHint), ui(new Ui::RegisterUserClass())
{
	ui->setupUi(this);
	ui->PasswordInput->setEchoMode(QLineEdit::Password);
	ui->RepeatPasswordInput->setEchoMode(QLineEdit::Password);

	this->database = std::make_unique<Database>(*database);
}


RegisterUser::~RegisterUser() { delete this->ui; }


void RegisterUser::errorLoginingMessage(const QString& errorMessage) {
	this->ui->PasswordInput->clear();
	this->ui->RepeatPasswordInput->clear();

	this->ui->LoginStatus->setStyleSheet("color: rgb(255, 224, 70);");
	this->ui->LoginStatus->setText(errorMessage);
}


void RegisterUser::on_SignUp_clicked() {
	if (this->ui->LoginInput->text().size() < 7) {
		errorLoginingMessage("Login is too short");
		return;
	}

	if (this->ui->PasswordInput->text().size() < 10) {
		errorLoginingMessage("Password is too short");
		return;
	}

	if (this->ui->PasswordInput->text().size() != this->ui->RepeatPasswordInput->text().size()) {
		errorLoginingMessage("Passwords does not match");
		return;
	}

	this->database.get()->getConnection()->setSchema("PassKeeper");

	try {
		this->database.get()->setPreparedStatement(this->database.get()->getConnection()->prepareStatement("insert into UsersTable(Login, Password) values (?, ?);"));
		this->database.get()->getPreparedStatement()->setString(1, this->ui->LoginInput->text().toLocal8Bit().constData());
		this->database.get()->getPreparedStatement()->setString(2, hashEncrypt(this->ui->PasswordInput->text().toLocal8Bit().constData()));
		this->database.get()->getPreparedStatement()->execute();
	}
	catch (sql::InvalidArgumentException error) {
		this->database.get()->setPreparedStatement(nullptr);
		this->database.get()->setResultSet(nullptr);

		this->ui->LoginInput->clear();
		this->ui->PasswordInput->clear();

		this->ui->LoginStatus->setStyleSheet("color: rgb(255, 224, 70);");
		this->ui->LoginStatus->setText("Oops! Something went wrong");
		return;
	}

	this->ui->LoginStatus->setStyleSheet("color: rgb(170, 255, 127);");
	this->ui->LoginStatus->setText("Successfully");

	// redirect to menu
}
