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

class evalSatisfaction { // 컨트롤 클래스
	DataSet data;
public:
	evalSatisfaction(ifstream* in, ofstream* out); // 회원 가입 진행
};

class evalSatisfactionUI { // 바운더리 클래스
	DataSet data;
public:
	DataSet getinfo(ifstream* in, ofstream* out); // 정보 받아옴
	void outputresult(ifstream* in, ofstream* out); // 정보 적음
};