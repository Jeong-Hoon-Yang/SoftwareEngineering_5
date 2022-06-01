#include <iostream>
#include <vector>
#include "member.h"

using namespace std;

vector<Member> memberList;

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