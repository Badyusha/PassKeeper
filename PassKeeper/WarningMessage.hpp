#ifndef WARNINGMESSAGE_HPP
#define WARNINGMESSAGE_HPP

#include "Libraries.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class WarningMessageClass; };
QT_END_NAMESPACE

class WarningMessage : public QMainWindow
{
	Q_OBJECT

	Ui::WarningMessageClass *ui;

private slots:

public:
	WarningMessage(QWidget *parent = nullptr);
	~WarningMessage();

	Ui::WarningMessageClass* getUi() const;
};

#endif

