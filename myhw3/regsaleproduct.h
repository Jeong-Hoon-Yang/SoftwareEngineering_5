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

class RegSaleProduct { // 컨트롤 클래스
	productInfo proinfo;
public:
	RegSaleProduct(ifstream* in, ofstream* out,Member &mem); // 회원 가입 진행
};

class RegSaleProductUI { // 바운더리 클래스
	productInfo proinfo;
public:
	productInfo getinfo(ifstream* in, ofstream* out); // 정보 받아옴
	void outputresult(ifstream* in, ofstream* out); // 정보 적음
};