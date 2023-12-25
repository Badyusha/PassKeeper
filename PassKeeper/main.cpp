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

    std::string server, username, password, key, iv;

    std::getline(input, server);
    std::getline(input, username);
    std::getline(input, password);
    std::getline(input, key);
    std::getline(input, iv);

    input.close();

    Database* database = new Database(decrypt(server, key, iv).c_str(),
                                      decrypt(username, key, iv).c_str(),
                                      decrypt(password, key, iv).c_str());

    Registration* registartion = new Registration();
    if (database->isConnected()) { registartion->show(); }

    return a.exec();
}
