#include <iostream>
#include <fstream>
#include "evalSatisfaction.h"

using namespace std;

evalSatisfaction::evalSatisfaction(ifstream* in, ofstream* out) {
	evalSatisfactionUI ui;

	data = ui.getinfo(in, out);

	ui.outputresult(in, out);
}

DataSet evalSatisfactionUI::getinfo(ifstream* in, ofstream* out) { // input.txt에서 정보 가져옴
	DataSet tmp;
	*in >> tmp.productName >> tmp.satisfaction;
	data = tmp;
	return tmp;
}

void evalSatisfactionUI::outputresult(ifstream* in, ofstream* out) { // output.txt에 결과 입력
	*out << "4.4. 상품 구매만족도 평가" << endl;

	Product::setPurchaseSatisfaction(data.productName, data.satisfaction, out);
}