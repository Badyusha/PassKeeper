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
	uint64_t id;

private slots:
	

public:
	UserCabinet() : id(0), ui(nullptr) {}
	UserCabinet(const uint64_t& id_, QWidget *parent = nullptr);
	~UserCabinet();

	Ui::UserCabinetClass* getUi() const;

};

#endif