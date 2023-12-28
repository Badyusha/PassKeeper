#include "Functions.hpp"


int connectToDatabase(const std::string& server, const std::string& username, const std::string& password,
						sql::Driver*& driver, sql::Connection*& con) {
	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e) {
		WarningMessage* warning = new WarningMessage();
		warning->getUi()->WarningMessage->setText("Unable to connect to the database!");
		warning->getUi()->ErrorCode->setText("Error code: " + QString::number(e.getErrorCode()));
		warning->show();
		return e.getErrorCode();
	}
	return CONDITION::NO_ERROR;
}


std::string hashEncrypt(const std::string& input) {
    // Создаем объект контекста для хэширования SHA-1
    SHA_CTX sha1Context;
    SHA1_Init(&sha1Context);

    // Обновляем контекст хэширования с данными
    SHA1_Update(&sha1Context, input.c_str(), input.length());

    // Получаем финальный хэш
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1_Final(hash, &sha1Context);

    // Преобразуем бинарный хэш в строку
    char hexString[SHA_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
        std::sprintf(hexString + 2 * i, "%02x", hash[i]);
    }

    return hexString;
}



// Utility function to convert binary data to hex string
std::string bin2hex(const std::string& input) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (unsigned char c : input) {
        oss << std::setw(2) << static_cast<int>(c);
    }
    return oss.str();
}

// Utility function to convert hex string to binary data
std::string hex2bin(const std::string& input) {
    std::string result;
    for (size_t i = 0; i < input.length(); i += 2) {
        result.push_back(static_cast<char>(std::stoi(input.substr(i, 2), nullptr, 16)));
    }
    return result;
}

// Encryption function
std::string encrypt(const std::string& plaintext, const std::string& key, const std::string& iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        std::cerr << "Error creating context\n";
        return "";
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, reinterpret_cast<const unsigned char*>(key.c_str()), reinterpret_cast<const unsigned char*>(iv.c_str())) != 1) {
        std::cerr << "Error initializing encryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    int len;
    int ciphertext_len;
    std::string ciphertext(plaintext.size() + AES_BLOCK_SIZE, '\0');

    if (EVP_EncryptUpdate(ctx, reinterpret_cast<unsigned char*>(&ciphertext[0]), &len, reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size()) != 1) {
        std::cerr << "Error updating encryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(&ciphertext[0] + len), &len) != 1) {
        std::cerr << "Error finalizing encryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return bin2hex(ciphertext.substr(0, ciphertext_len));
}

// Decryption function
std::string decrypt(const std::string& ciphertext, const std::string& key, const std::string& iv) {
    std::string ciphertext_bin = hex2bin(ciphertext);

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        std::cerr << "Error creating context\n";
        return "";
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, reinterpret_cast<const unsigned char*>(key.c_str()), reinterpret_cast<const unsigned char*>(iv.c_str())) != 1) {
        std::cerr << "Error initializing decryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    int len;
    int plaintext_len;
    std::string plaintext(ciphertext_bin.size(), '\0');

    if (EVP_DecryptUpdate(ctx, reinterpret_cast<unsigned char*>(&plaintext[0]), &len, reinterpret_cast<const unsigned char*>(ciphertext_bin.c_str()), ciphertext_bin.size()) != 1) {
        std::cerr << "Error updating decryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(&plaintext[0] + len), &len) != 1) {
        std::cerr << "Error finalizing decryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintext.substr(0, plaintext_len);
}

std::pair<std::string, std::string> getKeyNiv() {
    std::ifstream input("DBSI.txt", std::ios::in);
    if (!input.is_open()) {
        input.close();
        WarningMessage* warning = new WarningMessage();
        warning->getUi()->WarningMessage->setText("Cannot get server info to connect to the database!");
        warning->getUi()->ErrorCode->setText("Error code: " + QString::number(CONDITION::ERROR));
        warning->show();
        return {};
    }

    std::string key, iv;
    getline(input, key);
    getline(input, key);
    getline(input, key);
    getline(input, key);
    getline(input, iv);

    return { key, iv };
}

void encryptKeeperRecordData(std::string& keeperName, std::string& login, std::string& email,
                             std::string& password, std::string& additionalInfo)
{
    std::pair<std::string, std::string> keyNiv = getKeyNiv();

    if (keyNiv.first == "") { return; }

    keeperName = encrypt(keeperName, keyNiv.first, keyNiv.second);
    password = encrypt(password, keyNiv.first, keyNiv.second);

    if (!login.empty()) { login = encrypt(login, keyNiv.first, keyNiv.second); }
    if (!email.empty()) { email = encrypt(email, keyNiv.first, keyNiv.second); }
    if (!additionalInfo.empty()) { additionalInfo = encrypt(additionalInfo, keyNiv.first, keyNiv.second); }
}

void decryptKeeperRecordData(std::string& keeperName, std::string& login, std::string& email,
                             std::string& password, std::string& additionalInfo)
{
    std::pair<std::string, std::string> keyNiv = getKeyNiv();

    if (keyNiv.first == "") { return; }

    keeperName = decrypt(keeperName, keyNiv.first, keyNiv.second);
    password = decrypt(password, keyNiv.first, keyNiv.second);
    login = decrypt(login, keyNiv.first, keyNiv.second);
    email = decrypt(email, keyNiv.first, keyNiv.second);
    additionalInfo = decrypt(additionalInfo, keyNiv.first, keyNiv.second);
}
