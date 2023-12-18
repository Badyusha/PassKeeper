#include "UserCabinet.hpp"

UserCabinet::UserCabinet(const uint64_t& id_, QWidget *parent)
			: QMainWindow(parent), ui(new Ui::UserCabinetClass())
{
	ui->setupUi(this);
	this->id = id_;
}

UserCabinet::~UserCabinet() { delete ui; }

Ui::UserCabinetClass* UserCabinet::getUi() const { return this->ui; }
