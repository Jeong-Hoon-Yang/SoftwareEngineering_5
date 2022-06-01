#pragma once
#include <string>
#include <vector>
//#include "transactionInfo.h"

using namespace std;

typedef enum {
	STATE_LOGIN,
	STATE_LOGOUT
} login_state;

class Member {
	string id;
	string password;
	string name;
	int registerNumber;
	login_state loginState=STATE_LOGOUT;

public:
	void storeMemInfo(string id, string password, string name, int registeredNumber);
};

static vector<Member> memberList;