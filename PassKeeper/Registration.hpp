#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include "RegisterUser.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class RegistrationClass; };
QT_END_NAMESPACE

class Registration : public QWidget {
    Q_OBJECT

    Ui::RegistrationClass* ui;
    std::unique_ptr<Database> database;

private slots:
    void on_SignIn_clicked();
    void on_SignUp_clicked();

public:
    Registration(Database* database_, QWidget *parent = nullptr);
    ~Registration();

    Database* getDatabase() const;
};

#endif