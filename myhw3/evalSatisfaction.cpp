#include <iostream>
#include <fstream>
#include "evalSatisfaction.h"

using namespace std;

evalSatisfaction::evalSatisfaction(ifstream* in, ofstream* out) {
	evalSatisfactionUI ui;

	data = ui.getinfo(in, out);

	ui.outputresult(in, out);
}

DataSet evalSatisfactionUI::getinfo(ifstream* in, ofstream* out) { // input.txt���� ���� ������
	DataSet tmp;
	*in >> tmp.productName >> tmp.satisfaction;
	data = tmp;
	return tmp;
}

void evalSatisfactionUI::outputresult(ifstream* in, ofstream* out) { // output.txt�� ��� �Է�
	*out << "4.4. ��ǰ ���Ÿ����� ��" << endl;

	Product::setPurchaseSatisfaction(data.productName, data.satisfaction, out);
}