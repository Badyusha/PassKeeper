#ifndef WARNINGMESSAGE_HPP
#define WARNINGMESSAGE_HPP

#include "Registration.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class WarningMessageClass; };
QT_END_NAMESPACE

class WarningMessage : public QMainWindow
{
	Q_OBJECT

	Ui::WarningMessageClass *ui;
	int pressedButton;

private slots:
	void on_OkButton_clicked();
	void on_Close_clicked();

public:
	WarningMessage(QWidget *parent = nullptr, const int& pressedButton_ = 0);
	~WarningMessage();

	int getPressedButton() const;

	Ui::WarningMessageClass* getUi() const;
	void unhandledExceptionError();
};

#endif

