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


std::string encrypt(const std::string& plaintext, const std::string& key) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, reinterpret_cast<const unsigned char*>(key.c_str()), nullptr);

    std::string ciphertext;
    ciphertext.resize(plaintext.size() + AES_BLOCK_SIZE, '\0');

    int len = 0;
    EVP_EncryptUpdate(ctx, reinterpret_cast<unsigned char*>(&ciphertext[0]), &len,
        reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size());

    int ciphertextLen = len;

    EVP_EncryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(&ciphertext[len]), &len);
    ciphertextLen += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext.substr(0, ciphertextLen);
}

std::string decrypt(const std::string& ciphertext, const std::string& key) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, reinterpret_cast<const unsigned char*>(key.c_str()), nullptr);

    std::string plaintext;
    plaintext.resize(ciphertext.size(), '\0');

    int len = 0;
    EVP_DecryptUpdate(ctx, reinterpret_cast<unsigned char*>(&plaintext[0]), &len,
        reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());

    int plaintextLen = len;

    EVP_DecryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(&plaintext[len]), &len);
    plaintextLen += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext.substr(0, plaintextLen);
}


