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

class Purchase { // 컨트롤 클래스
	Trans data;
public:
	Purchase(ifstream* in, ofstream* out, Member presentmem, Product presentproduct); // 회원 가입 진행
};

class PurchaseUI { // 바운더리 클래스
	Trans data;
public:
	Trans getinfo(ifstream* in, ofstream* out, Member presentmem, Product presentproduct); // 정보 받아옴
	void outputresult(ifstream* in, ofstream* out); // 정보 적음
};