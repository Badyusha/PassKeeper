#ifndef USERCABINET_HPP
#define USERCABINET_HPP

#include "ui_UserCabinet.h"
#include "Registration.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class UserCabinetClass; };
QT_END_NAMESPACE

class UserCabinet : public QMainWindow {
	Q_OBJECT

	Ui::UserCabinetClass *ui;
	unsigned int id;

private slots:
	void on_actionQuit_triggered();
	void on_actionDeleteAccount_triggered();
	void onButtonClicked(const WARNING_MESSAGE& buttonId);

public:
	UserCabinet() : id(0), ui(nullptr) {}
	UserCabinet(const unsigned int& id_, QWidget *parent = nullptr);
	~UserCabinet();

	Ui::UserCabinetClass* getUi() const;
	int getRecordsCount();
	CONDITION deleteUserFromTable(const char* query);
};

#endif