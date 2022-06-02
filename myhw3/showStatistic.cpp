#include <iostream>
#include <fstream>
#include "showStatistic.h"

using namespace std;

showStatistic::showStatistic(ifstream* in, ofstream* out, string mem_id) {
	showStatisticUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showStatisticUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt에서 정보 가져옴
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showStatisticUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt에 결과 입력
	*out << "5.1. 판매 상품 통계" << endl;

	Product::getSatisfactionAndTotal(mem_id, out);
}