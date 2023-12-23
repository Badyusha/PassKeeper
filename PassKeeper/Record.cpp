#include "Record.hpp"

Record::Record(unsigned int& userId_, QWidget *parent)
	   : QMainWindow(parent, Qt::FramelessWindowHint) , ui(new Ui::RecordClass()), userId(userId_)
{
	ui->setupUi(this);
}

Record::~Record() {	delete ui; }

void Record::on_Close_clicked() {
	this->close();
	UserCabinet* userCab = new UserCabinet(this->userId);
	userCab->show();
}
