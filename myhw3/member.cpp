#include <iostream>
#include "member.h"
//#include "transcationInfo.h"

using namespace std;

Member::Member() {

}

Member::Member(string id, string password, int resgisterNumber, string name) {
	this->id = id;
	this->password = password;
	this->registerNumber = registerNumber;
	this->name = name;
}

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
	return nousemember;
}

void Member::deleteInfoRight(Member& m) {
	for (auto it = memberList.begin(); it != memberList.end(); it++) {
		if (it->id == m.id) {
			cout << m.id << endl;
			for (auto pit = productList.begin(); pit != productList.end(); pit++) {
				if (pit->getSellerID() == m.id) {
					productList.erase(pit);
				}
			}
			memberList.erase(it);

			return;
		}
	}
}

Member Member::findMember(string id) {
	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i].id == id) return memberList[i];
	}
	return nousemember;
}
void Member::logout(Member& m) {
	m.loginState = STATE_LOGOUT;
	cout << m.id << endl;
}

string Member::getId() {
	return this->id;
}