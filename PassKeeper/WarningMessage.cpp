#include "WarningMessage.hpp"

WarningMessage::WarningMessage(QWidget *parent)
	: QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::WarningMessageClass()) {
	ui->setupUi(this);
}

WarningMessage::~WarningMessage() {
	delete ui;
}

Ui::WarningMessageClass* WarningMessage::getUi() const { return this->ui; }
