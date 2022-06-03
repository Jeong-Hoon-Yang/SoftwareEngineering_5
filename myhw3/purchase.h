#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"
#include "transactionInfo.h"

using namespace std;

struct Trans {
	Member seller;
	Member buyer;
	Product product;
};

class Purchase { // ��Ʈ�� Ŭ����
	Trans data;
public:
	Purchase(ifstream* in, ofstream* out, Member presentmem, Product presentproduct); // ȸ�� ���� ����
};

class PurchaseUI { // �ٿ���� Ŭ����
	Trans data;
public:
	Trans getinfo(ifstream* in, ofstream* out, Member presentmem, Product presentproduct); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out); // ���� ����
};