#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Functions.hpp"

static class Database {
	const char* server;
	const char* username;
	const char* password;

	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;

	bool connected;

public:
	Database() : server("Undefinied"), username("Undefinied"), password("Undefinied"),
				 driver(nullptr), con(nullptr), pstmt(nullptr), result(nullptr), connected(false) {};
	Database(const char* server_, const char* username_, const char* password_, const bool& connected_ = false,
			 const sql::PreparedStatement* pstmt_ = nullptr, const sql::ResultSet* result_ = nullptr);
	~Database();



	void setServer(const char* server_) { this->server = server_; }
	void setUsername(const char* username_) { this->username = username_; }
	void setPassword(const char* password_) { this->password = password_; }

	void setDriver(sql::Driver* driver_) { this->driver = driver_; }
	void setConnection(sql::Connection* con_) { this->con = con_; }
	void setPreparedStatement(sql::PreparedStatement* pstmt_) { this->pstmt = pstmt_; }
	void setResultSet(sql::ResultSet* result_) { this->result = result_; }



	const char* getServer() const { return this->server; }
	const char* getUsername() const { return this->username; }
	const char* getPassword() const { return this->password; }

	sql::Driver* getDriver() const { return this->driver; }
	sql::Connection* getConnection() const { return this->con; }
	sql::PreparedStatement* getPreparedStatement() const { return this->pstmt; }
	sql::ResultSet* getResultSet() const { return this->result; }

	bool isConnected() const { return this->connected; }
};

#endif