#include <iostream>
#include <fstream>
#include "showPurInfo.h"

using namespace std;

showPurInfo::showPurInfo(ifstream* in, ofstream* out, string mem_id) {
	showPurInfoUI ui;

	this->mem_id = ui.getinfo(in, out, mem_id);

	ui.outputresult(in, out, mem_id);
}

string showPurInfoUI::getinfo(ifstream* in, ofstream* out, string mem_id) { // input.txt���� ���� ������
	string tmp;
	tmp = mem_id;
	return tmp;
}

void showPurInfoUI::outputresult(ifstream* in, ofstream* out, string mem_id) { // output.txt�� ��� �Է�
	*out << "4.3 ��ǰ ���� ���� ��ȸ" << endl;

	TransactionInfo::getProducts(mem_id, out);
}