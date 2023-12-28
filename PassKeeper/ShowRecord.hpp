#ifndef SHOWRECORD_HPP
#define SHOWRECORD_HPP

#include "UserCabinet.hpp"
#include <qstandarditemmodel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ShowRecordClass; };
QT_END_NAMESPACE

class ShowRecord : public QMainWindow {
	Q_OBJECT

	Ui::ShowRecordClass *ui;
	QStandardItemModel* model;
	unsigned int userId;

private slots:

public:
	ShowRecord(const unsigned int& userId, QWidget *parent = nullptr);
	~ShowRecord();

	void addData(const QString& associatedName, const QString& login, const QString& email,
				 const QString& password, const QString& additionalInfo);
	void setHeaders();
	void getDataFromTable();
};

#endif