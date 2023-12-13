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

private slots:
	void on_SignUp_clicked();

public:
	RegisterUser(QWidget *parent = nullptr);
	~RegisterUser();

	void errorLoginingMessage(const QString& errorMessage);
	CONDITION enteredDataIsIncorrect();
};

#endif