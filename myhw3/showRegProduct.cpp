#include <iostream>
#include <fstream>
#include "showRegProduct.h"

using namespace std;

showRegProduct::showRegProduct(ifstream* in, ofstream* out, string mem_id) {
	showRegProductUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showRegProductUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt에서 정보 가져옴
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showRegProductUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt에 결과 입력
	*out << "3.2. 등록 상품 조회" << endl;

	Product::getRegisteredProductInfo(mem_id,out);
}