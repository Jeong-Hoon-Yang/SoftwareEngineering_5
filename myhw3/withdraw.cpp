#include <iostream>
#include <fstream>
#include "withdraw.h"

using namespace std;

Withdraw::Withdraw(ifstream* in, ofstream* out, Member& mem) {
	class WithdrawUI ui; // �ٿ���� Ŭ���� ����
	mem.deleteInfoRight(mem);
	ui.outputresult(in, out);
}


void WithdrawUI::outputresult(ifstream* in, ofstream* out) {
	*out << "1.2. ȸ��Ż��" << endl << endl;
}