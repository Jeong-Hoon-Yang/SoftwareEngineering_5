#pragma once
#include <string>
#include <fstream>
#include "member.h"

using namespace std;

class Logout {
public:
	Logout(ifstream* in, ofstream* out, Member& mem); // 로그아웃 진행
};

class LogoutUI {
public:
	void outputresult(ifstream* in, ofstream* out, Member& mem); // output 에 결과 입력
};