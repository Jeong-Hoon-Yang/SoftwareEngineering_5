#pragma once
#include <string>
#include <fstream>
#include "member.h"

using namespace std;

class Logout {
public:
	Logout(ifstream* in, ofstream* out, Member& mem); // �α׾ƿ� ����
};

class LogoutUI {
public:
	void outputresult(ifstream* in, ofstream* out, Member& mem); // output �� ��� �Է�
};