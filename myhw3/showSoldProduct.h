#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"

using namespace std;

class showSoldProduct { // ��Ʈ�� Ŭ����
	string mem_id;
public:
	showSoldProduct(ifstream* in, ofstream* out, string mem_id); // ȸ�� ���� ����
};

class showSoldProductUI { // �ٿ���� Ŭ����
	string mem_id;
public:
	string getinfo(ifstream* in, ofstream* out, string mem_id); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out, string mem_id); // ���� ����
};