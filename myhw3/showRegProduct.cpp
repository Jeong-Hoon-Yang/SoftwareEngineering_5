#include <iostream>
#include <fstream>
#include "showRegProduct.h"

using namespace std;

showRegProduct::showRegProduct(ifstream* in, ofstream* out, string mem_id) {
	showRegProductUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showRegProductUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt���� ���� ������
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showRegProductUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt�� ��� �Է�
	*out << "3.2. ��� ��ǰ ��ȸ" << endl;

	Product::getRegisteredProductInfo(mem_id,out);
}