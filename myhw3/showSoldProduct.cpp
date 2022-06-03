#include <iostream>
#include <fstream>
#include "showSoldProduct.h"

using namespace std;

showSoldProduct::showSoldProduct(ifstream* in, ofstream* out, string mem_id) {
	showSoldProductUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showSoldProductUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt���� ���� ������
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showSoldProductUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt�� ��� �Է�
	Product::getSoldProductInfoDetails(mem_id, out);
}