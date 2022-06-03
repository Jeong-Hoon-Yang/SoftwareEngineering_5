#pragma once
#include <string>
#include <fstream>
#include "member.h"

using namespace std;

class Withdraw {
public:
	Withdraw(ifstream* in, ofstream* out, Member& mem);
};

class WithdrawUI {
public:
	void outputresult(ifstream* in, ofstream* out);
};