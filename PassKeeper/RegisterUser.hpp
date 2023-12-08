#ifndef REGISTERUSER_HPP
#define REGISTERUSER_HPP

#include <QWidget>
#include "Database.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class RegisterUserClass; };
QT_END_NAMESPACE

class RegisterUser : public QWidget
{
	Q_OBJECT

	Ui::RegisterUserClass *ui;
	std::unique_ptr<Database> database;

private slots:
	void on_SignUp_clicked();

public:
	RegisterUser(Database* database, QWidget *parent = nullptr);
	~RegisterUser();

	void errorLoginingMessage(const QString& errorMessage);

};

#endif