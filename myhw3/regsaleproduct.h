#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"

using namespace std;

struct productInfo {
	string sellerID;
	string productName;
	string productCompany;
	int price;
	int quantity;
};

class RegSaleProduct { // ��Ʈ�� Ŭ����
	productInfo proinfo;
public:
	RegSaleProduct(ifstream* in, ofstream* out,Member &mem); // ȸ�� ���� ����
};

class RegSaleProductUI { // �ٿ���� Ŭ����
	productInfo proinfo;
public:
	productInfo getinfo(ifstream* in, ofstream* out); // ���� �޾ƿ�
	void outputresult(ifstream* in, ofstream* out); // ���� ����
};