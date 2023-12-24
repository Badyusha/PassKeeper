#include "Registration.hpp"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::ifstream input("DBSI.txt", std::ios::in);
    if (!input.is_open()) {
        input.close();
        WarningMessage* warning = new WarningMessage();
        warning->getUi()->WarningMessage->setText("Cannot get server info to connect to the database!");
        warning->getUi()->ErrorCode->setText("Error code: " + QString::number(CONDITION::ERROR));
        warning->show();
        return a.exec();
    }

    std::string server, username, password, key;

    getline(input, server);
    getline(input, username);
    getline(input, password);
    getline(input, key);

    input.close();

    Database* database = new Database(decryptDBSI(server, key).c_str(),
                                      decryptDBSI(username, key).c_str(),
                                      decryptDBSI(password, key).c_str());

    Registration* registartion = new Registration();
    if (database->isConnected()) { registartion->show(); }

    return a.exec();
}
