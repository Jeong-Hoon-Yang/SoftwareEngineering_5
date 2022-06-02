#include <iostream>
#include <fstream>
#include "withdraw.h"

using namespace std;

Withdraw::Withdraw(ifstream* in, ofstream* out, Member& mem) {
	class WithdrawUI ui; // 바운더리 클래스 생성
	mem.deleteInfoRight(mem);
	ui.outputresult(in, out);
}


void WithdrawUI::outputresult(ifstream* in, ofstream* out) {
	*out << "1.2. 회원탈퇴" << endl << endl;
}