#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"
#include "transactionInfo.h"

using namespace std;

class showPurInfo { // ��Ʈ�� Ŭ����
	string mem_id;
public:
	showPurInfo(ifstream* in, ofstream* out, string mem_id); // ȸ�� ���� ����
};

class showPurInfoUI { // �ٿ���� Ŭ����
	string mem_id;
public:
	string getinfo(ifstream* in, ofstream* out, string mem_id); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out, string mem_id); // ���� ����
};