#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"

using namespace std;

class showRegProduct { // ��Ʈ�� Ŭ����
	string mem_id;
public:
	showRegProduct(ifstream* in, ofstream* out, string mem_id); // ȸ�� ���� ����
};

class showRegProductUI { // �ٿ���� Ŭ����
	string mem_id;
public:
	string getinfo(ifstream* in, ofstream* out, string mem_id); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out, string mem_id); // ���� ����
};