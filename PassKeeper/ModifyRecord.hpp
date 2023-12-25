#ifndef MODIFY_RECORD_HPP
#define MODIFY_RECORD_HPP

#include <QMainWindow>
#include "ui_ModifyRecord.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ModifyRecordClass; };
QT_END_NAMESPACE

class ModifyRecord : public QMainWindow {
	Q_OBJECT

	Ui::ModifyRecordClass *ui;

private slots:

public:
	ModifyRecord(QWidget *parent = nullptr);
	~ModifyRecord();

};

#endif