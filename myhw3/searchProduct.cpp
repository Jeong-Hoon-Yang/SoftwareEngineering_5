#include <iostream>
#include <fstream>
#include "serachProduct.h"


using namespace std;

Product SearchProduct::showresult(ifstream* in, ofstream* out) {
	class SearchProductUI ui;
	productname = ui.getinfo(in, out);
	ui.outputresult(in, out);
	return Product::getProductInfoDetails(productname,out);
}


string SearchProductUI::getinfo(ifstream* in, ofstream* out) {
	string productname;
	*in >> productname;
	return productname;
}

void SearchProductUI::outputresult(ifstream* in, ofstream* out) {

	*out << "4.1. 상품 정보 검색" << endl;
}