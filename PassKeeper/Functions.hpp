#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Libraries.hpp"
#include "WarningMessage.hpp"

int connectToDatabase(const std::string& server, const std::string& username, const std::string& password,
						sql::Driver*& driver, sql::Connection*& con);

std::string hashEncrypt(const std::string& data);



std::string encrypt(const std::string& plain_text, const std::string& key);

std::string decrypt(const std::string& cipher_text, const std::string& key);


#endif