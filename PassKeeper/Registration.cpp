#include "Registration.hpp"

Registration::Registration(Database* database_, QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint) ,ui(new Ui::RegistrationClass())
{
    ui->setupUi(this);
	ui->PasswordInput->setEchoMode(QLineEdit::Password);
	this->database = std::make_unique<Database>(*database_);
}

Registration::~Registration() { delete this->ui; }


Database* Registration::getDatabase() const { return this->database.get(); }


void Registration::on_SignIn_clicked() {
	this->database.get()->getConnection()->setSchema("PassKeeper");

	this->database.get()->setPreparedStatement(this->database.get()->getConnection()->prepareStatement("select Login, Password from UsersTable where Login = ?;"));

	std::string login = this->ui->LoginInput->text().toLocal8Bit().constData();
	this->database.get()->getPreparedStatement()->setString(1, login);

	this->database.get()->setResultSet(this->database.get()->getPreparedStatement()->executeQuery());

	this->database.get()->getResultSet()->next();
	try {
		if (this->database.get()->getResultSet()->getString(1) == login &&
			this->database.get()->getResultSet()->getString(2) == hashEncrypt(this->ui->PasswordInput->text().toLocal8Bit().constData())) {

			this->ui->LoginStatus->setStyleSheet("color: rgb(170, 255, 127);");
			this->ui->LoginStatus->setText("Successfully");
			// redirect to the menu
			return;
		}
	}
	catch (sql::InvalidArgumentException error) {
		this->database.get()->setPreparedStatement(nullptr);
		this->database.get()->setResultSet(nullptr);
		
		this->ui->LoginInput->clear();
		this->ui->PasswordInput->clear();

		this->ui->LoginStatus->setStyleSheet("color: rgb(255, 224, 70);");
		this->ui->LoginStatus->setText("Incorrect login or password");
	}
}

void Registration::on_SignUp_clicked() {
	RegisterUser* registerUser = new RegisterUser(this->getDatabase());
	registerUser->show();
	hide();
}
