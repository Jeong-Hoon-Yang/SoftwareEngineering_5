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

class Join { // ��Ʈ�� Ŭ����
private:
	Memberinfo memberinfo;
public:
	Join(ifstream *in, ofstream* out); // ȸ�� ���� ����
};

class JoinUI { // �ٿ���� Ŭ����
private:
	Memberinfo memberinfo;
public:
	Memberinfo getinfo(ifstream* in, ofstream* out); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out); // ���� ����
};

