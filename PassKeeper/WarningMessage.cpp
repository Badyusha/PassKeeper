#include "WarningMessage.hpp"

WarningMessage::WarningMessage(QWidget *parent, const int& pressedButton_)
	: QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::WarningMessageClass()) {
	ui->setupUi(this);
	this->pressedButton = pressedButton_;
	connect(this->ui->OkButton, SIGNAL(clicked()), this, SLOT(on_OkButton_clicked()));
	connect(this->ui->Close, SIGNAL(clicked()), this, SLOT(on_Close_clicked()));
}

WarningMessage::~WarningMessage() {
	delete ui;
}


int WarningMessage::getPressedButton() const { return this->pressedButton; }


void WarningMessage::on_OkButton_clicked() {
	this->close();
	this->pressedButton = WARNING_MESSAGE::OK_BUTTON;
}

void WarningMessage::on_Close_clicked() {
	this->close();
	this->pressedButton = WARNING_MESSAGE::CLOSE_BUTTON;
}


Ui::WarningMessageClass* WarningMessage::getUi() const { return this->ui; }

void WarningMessage::unhandledExceptionError() {
	this->ui->WarningMessage->setText("Something went wrong :(");
	this->ui->ErrorCode->setText("Error code: " + QString::number(CONDITION::ERROR));
}
