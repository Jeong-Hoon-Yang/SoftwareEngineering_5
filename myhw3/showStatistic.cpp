#include <iostream>
#include <fstream>
#include "showStatistic.h"

using namespace std;

showStatistic::showStatistic(ifstream* in, ofstream* out, string mem_id) {
	showStatisticUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showStatisticUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt���� ���� ������
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showStatisticUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt�� ��� �Է�
	*out << "5.1. �Ǹ� ��ǰ ���" << endl;

	Product::getSatisfactionAndTotal(mem_id, out);
}