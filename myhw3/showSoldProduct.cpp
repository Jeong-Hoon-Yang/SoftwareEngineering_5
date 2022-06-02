#include <iostream>
#include <fstream>
#include "showSoldProduct.h"

using namespace std;

showSoldProduct::showSoldProduct(ifstream* in, ofstream* out, string mem_id) {
	showSoldProductUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showSoldProductUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt에서 정보 가져옴
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showSoldProductUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt에 결과 입력
	Product::getSoldProductInfoDetails(mem_id, out);
}