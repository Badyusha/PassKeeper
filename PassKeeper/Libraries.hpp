#ifndef LIBRARIES_HPP
#define LIBRARIES_HPP

// built-in libs
#include <memory>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

// libs to create wins
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

// libs to work with database 
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

// to encrypt data
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

// all ui's
#include "ui_Registration.h"
#include "ui_WarningMessage.h"
#include "ui_RegisterUser.h"
#include "ui_UserCabinet.h"
#include "ui_Record.h"
#include "ui_ShowRecord.h"

// enums
#include "Enums.hpp"



#endif