#ifndef MODIFY_RECORD_HPP
#define MODIFY_RECORD_HPP

#include "UserCabinet.hpp"
#include <qstandarditemmodel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ModifyRecordClass; };
QT_END_NAMESPACE

class ModifyRecord : public QMainWindow {
	Q_OBJECT

	Ui::ModifyRecordClass *ui;
	unsigned int userId;

private slots:

public:
	ModifyRecord(unsigned int& userId_, QWidget *parent = nullptr);
	~ModifyRecord();

};

#endif