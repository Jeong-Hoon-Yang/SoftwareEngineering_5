#include <iostream>
#include <fstream>
#include "showPurInfo.h"

using namespace std;

showPurInfo::showPurInfo(ifstream* in, ofstream* out, string mem_id) {
	showPurInfoUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showPurInfoUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt에서 정보 가져옴
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showPurInfoUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt에 결과 입력
	*out << "4.3 상품 구매 내역 조회" << endl;

	TransactionInfo::getProducts(mem_id, out);
}