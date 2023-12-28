#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Libraries.hpp"
#include "WarningMessage.hpp"

int connectToDatabase(const std::string& server, const std::string& username, const std::string& password,
						sql::Driver*& driver, sql::Connection*& con);

std::string hashEncrypt(const std::string& data);


std::string encrypt(const std::string& plain_text, const std::string& key, const std::string& iv);

std::string decrypt(const std::string& cipher_text, const std::string& key, const std::string& iv);

std::pair<std::string, std::string> getKeyNiv();

// std::string getEncryptionKey();


void encryptKeeperRecordData(std::string& keeperName, std::string& login, std::string& email,
							 std::string& password, std::string& additionalInfo);

void decryptKeeperRecordData(std::string& keeperName, std::string& login, std::string& email,
							 std::string& password, std::string& additionalInfo);


#endif