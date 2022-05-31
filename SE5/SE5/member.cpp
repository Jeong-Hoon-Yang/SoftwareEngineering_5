#include <iostream>
#include "member.h"

void Member::storeMemInfo(string id, string password, string name, int registerNumber) {
	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i].id == id) {	// ID is already registered then return function
			cout << "already registered ID" << endl;
			return;
		}
	}

	Member tmp;

	tmp.id = id;
	tmp.password = password;
	tmp.name = name;
	tmp.registerNumber = registerNumber;
	tmp.loginState = STATE_LOGOUT;

	memberList.push_back(tmp);

	cout << tmp.name << ' ' << tmp.registerNumber << ' ' << tmp.id << ' ' << tmp.password << endl;
}

Member Member::verifyIdPw(string id, string password) {
	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i].id == id && memberList[i].password == password) {
			memberList[i].loginState = STATE_LOGIN;
			cout << memberList[i].id << ' ' << memberList[i].password << endl;
			return memberList[i];
		}
	}
}

void Member::logout(Member& m) {
	m.loginState == STATE_LOGOUT;
	cout << m.id << endl;
}

void Member::deleteInfoRight(Member& m) {
	for (auto it = memberList.begin(); it != memberList.end(); it++) {
		if (it->id == m.id) {
			cout << m.id << endl;
			memberList.erase(it);
			// add here
			// 등록한 상품들의 수량을 0으로 만드는 함수
			return;
		}
	}
}

void Member::getTransactionInfoList() {

}

/*
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
	void storeMemInfo();
	void verifyIdPw();
	void logout();
	void deleteInfoRight();
	void getTransactionInfoList();
};
*/