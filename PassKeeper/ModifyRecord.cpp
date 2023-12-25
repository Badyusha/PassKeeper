#include "ModifyRecord.hpp"

ModifyRecord::ModifyRecord(QWidget *parent)
			 : QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::ModifyRecordClass())
{
	ui->setupUi(this);
}

ModifyRecord::~ModifyRecord() {	delete ui; }
