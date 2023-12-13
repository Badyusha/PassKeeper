#include "WarningMessage.hpp"

WarningMessage::WarningMessage(QWidget *parent)
	: QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::WarningMessageClass()) {
	ui->setupUi(this);
}

WarningMessage::~WarningMessage() {
	delete ui;
}

Ui::WarningMessageClass* WarningMessage::getUi() const { return this->ui; }

void WarningMessage::unhandledExceptionError() {
	this->ui->WarningMessage->setText("Something went wrong :(");
	this->ui->ErrorCode->setText("Error code: " + QString::number(CONDITION::ERROR));
}
