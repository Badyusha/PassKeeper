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
	WARNING_MESSAGE pressedButtonId;

private slots:
	
signals:
	void buttonClicked(const WARNING_MESSAGE& buttonId);

public:
	WarningMessage(QWidget *parent = nullptr);
	~WarningMessage();

	Ui::WarningMessageClass* getUi() const;
	void unhandledExceptionError();

	static void closeAllWindows();
};

#endif

