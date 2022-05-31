#pragma once
#include <string>
#include <vector>
#include "transactionInfo.h"

using namespace std;

vector<Member> memberList;

typedef enum {
	STATE_LOGIN,
	STATE_LOGOUT
} login_state;

class Member {
	string id;
	string password;
	string name;
	int registerNumber;
	login_state loginState;

public:
	void storeMemInfo(string id, string password, string name, int registeredNumber);
	Member verifyIdPw(string id, string password);
	void logout(Member& m);
	void deleteInfoRight(Member& m);
	void getTransactionInfoList();
};