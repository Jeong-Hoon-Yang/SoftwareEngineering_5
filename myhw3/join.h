#pragma once
#include <string>
#include <fstream>
#include "member.h"

using namespace std;

struct Memberinfo {
	string name;
	int registernum=0;
	string id;
	string password;
};

class Join { // 컨트롤 클래스
private:
	Memberinfo memberinfo;
public:
	Join(ifstream *in, ofstream* out); // 회원 가입 진행
};

class JoinUI { // 바운더리 클래스
private:
	Memberinfo memberinfo;
public:
	Memberinfo getinfo(ifstream* in, ofstream* out); // 정보 받아옴
	void outputresult(ifstream* in, ofstream* out); // 정보 적음
};