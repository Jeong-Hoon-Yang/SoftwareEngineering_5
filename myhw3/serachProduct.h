#pragma once
#include <string>
#include <fstream>
#include "member.h"
#include "product.h"


class SearchProduct { //
private:
	string productname;
public:
	Product showresult(ifstream* in, ofstream* out);
};

class SearchProductUI {
public:
	string getinfo(ifstream* in, ofstream* out);
	void outputresult(ifstream* in, ofstream* out);
};