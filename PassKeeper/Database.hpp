#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Functions.hpp"

class Database {
	const char* server;
	const char* username;
	const char* password;

	bool connected;

	inline static sql::Driver* driver = nullptr;
	inline static sql::Connection* con = nullptr;
	inline static sql::ResultSet* result = nullptr;
	inline static sql::PreparedStatement* pstmt = nullptr;

public:
	Database() : server("Undefinied"), username("Undefinied"), password("Undefinied"), connected(false) {};
	Database(const char* server_, const char* username_, const char* password_, const bool& connected_ = false,
			 const sql::PreparedStatement* pstmt_ = nullptr, const sql::ResultSet* result_ = nullptr);
	~Database();



	void setServer(const char* server_) { this->server = server_; }
	void setUsername(const char* username_) { this->username = username_; }
	void setPassword(const char* password_) { this->password = password_; }

	static void setDriver(sql::Driver* driver_) { driver = driver_; }
	static void setConnection(sql::Connection* con_) { con = con_; }
	static void setResultSet(sql::ResultSet* result_) { result = result_; }
	static void setPreparedStatement(sql::PreparedStatement* pstmt_) { pstmt = pstmt_; }


	
	const char* getServer() const { return this->server; }
	const char* getUsername() const { return this->username; }
	const char* getPassword() const { return this->password; }

	static sql::Driver* getDriver() { return driver; }
	static sql::Connection* getConnection() { return con; }
	static sql::ResultSet* getResultSet() { return result; }
	static sql::PreparedStatement* getPreparedStatement() { return pstmt; }

	bool isConnected() const { return this->connected; }
};

#endif