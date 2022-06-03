#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"

using namespace std;

class showSoldProduct { // 컨트롤 클래스
	string mem_id;
public:
	showSoldProduct(ifstream* in, ofstream* out, string mem_id); // 회원 가입 진행
};

class showSoldProductUI { // 바운더리 클래스
	string mem_id;
public:
	string getinfo(ifstream* in, ofstream* out, string mem_id); // 정보 받아옴
	void outputresult(ifstream* in, ofstream* out, string mem_id); // 정보 적음
};