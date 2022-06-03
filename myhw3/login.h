#pragma once
#include <string>
#include <fstream>
#include "member.h"

using namespace std;

struct Logininfo {
	string id;
	string password;
};

class Login { // ��Ʈ�� Ŭ���� 
private:
	Logininfo logininfo;
public:
	Member showresult(ifstream* in, ofstream* out); // �α��� ����
};


class LoginUI { //�ٿ���� Ŭ���� 
private:
	Logininfo logininfo;
public:
	Logininfo getinfo(ifstream* in, ofstream* out); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out); // ���� ����
};

