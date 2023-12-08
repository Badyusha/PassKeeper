#ifndef LIBRARIES_HPP
#define LIBRARIES_HPP

// built-in libs
#include <memory>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <iostream>

// libs to create wins
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

// libs to work with database 
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

// to encrypt data
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/aes.h>

// all ui's
#include "ui_Registration.h"
#include "ui_WarningMessage.h"
#include "ui_ClientMainMenu.h"
#include "ui_RegisterUser.h"




enum CONDITION {
	NO_ERROR = 1,
	UNHANDLED_ERROR = -1
};



#endif