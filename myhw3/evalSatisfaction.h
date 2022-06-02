#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"

using namespace std;

struct DataSet {
	string productName;
	int satisfaction;
};

class evalSatisfaction { // ��Ʈ�� Ŭ����
	DataSet data;
public:
	evalSatisfaction(ifstream* in, ofstream* out); // ȸ�� ���� ����
};

class evalSatisfactionUI { // �ٿ���� Ŭ����
	DataSet data;
public:
	DataSet getinfo(ifstream* in, ofstream* out); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out); // ���� ����
};