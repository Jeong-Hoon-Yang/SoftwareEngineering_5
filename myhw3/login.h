#pragma once
#include <string>
#include <fstream>
#include "member.h"

using namespace std;

struct Logininfo {
	string id;
	string password;
};

class Login { // 컨트롤 클래스 
private:
	Logininfo logininfo;
public:
	Member showresult(ifstream* in, ofstream* out); // 로그인 진행
};


class LoginUI { //바운더리 클래스 
private:
	Logininfo logininfo;
public:
	Logininfo getinfo(ifstream* in, ofstream* out); // 정보 받아옴
	void outputresult(ifstream* in, ofstream* out); // 정보 적음
};

