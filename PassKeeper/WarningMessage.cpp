#include "WarningMessage.hpp"


WarningMessage::WarningMessage(QWidget *parent)
	: QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::WarningMessageClass()), pressedButtonId(WARNING_MESSAGE(-1)) {
	ui->setupUi(this);

	connect(ui->OkButton, &QPushButton::clicked, this, [this]() { emit buttonClicked(WARNING_MESSAGE::OK_BUTTON); this->close(); });
	connect(ui->Close, &QPushButton::clicked, this, [this]() { emit buttonClicked(WARNING_MESSAGE::CLOSE_BUTTON); this->close(); });
}

WarningMessage::~WarningMessage() {
	delete ui;
}


Ui::WarningMessageClass* WarningMessage::getUi() const { return this->ui; }

void WarningMessage::unhandledExceptionError() {
	this->ui->WarningMessage->setText("Something went wrong :(");
	this->ui->ErrorCode->setText("Error code: " + QString::number(CONDITION::ERROR));
}


void WarningMessage::closeAllWindows() {
	for (QWidget* widget : QApplication::topLevelWidgets()) {
		if (widget->isWindow()) { widget->close(); }
	}
}

