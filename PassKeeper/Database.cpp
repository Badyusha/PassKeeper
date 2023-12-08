#include "Database.hpp"

Database::~Database() {
	delete this->con;
	delete this->pstmt;
	delete this->result;
}

Database::Database(const char* server_, const char* username_, const char* password_, const bool& connected_,
				   const sql::PreparedStatement* pstmt_, const sql::ResultSet* result_)
{
	this->server = server_;
	this->username = username_;
	this->password = password_;
	this->connected = connected_;

	int errorCode = connectToDatabase(this->server, this->username, this->password, this->driver, this->con);

	if (errorCode == CONDITION::NO_ERROR) { this->connected = true; }
}