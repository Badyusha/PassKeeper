#ifndef MODIFY_RECORD_HPP
#define MODIFY_RECORD_HPP

#include "UserCabinet.hpp"
#include <qstandarditemmodel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ModifyRecordClass; };
QT_END_NAMESPACE

class ModifyRecord : public QMainWindow {
	Q_OBJECT

	QStandardItemModel* model;
	Ui::ModifyRecordClass *ui;
	unsigned int userId;

private slots:

public:
	ModifyRecord(unsigned int& userId_, QWidget *parent = nullptr);
	~ModifyRecord();

	void setHeaders();
	void addData(const QString& associatedName, const QString& login,
				 const QString& email, const QString& password, const QString& additionalInfo);
};

#endif