#ifndef RECORD_HPP
#define RECORD_HPP

#include "UserCabinet.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class RecordClass; };
QT_END_NAMESPACE

class Record : public QMainWindow {
	Q_OBJECT

	Ui::RecordClass *ui;
	unsigned int userId;

private slots:
	void on_Close_clicked();
public:
	Record(unsigned int& userId_, QWidget *parent = nullptr);
	~Record();

};

#endif