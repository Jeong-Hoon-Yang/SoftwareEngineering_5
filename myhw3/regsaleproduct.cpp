#include <iostream>
#include <fstream>
#include "regsaleproduct.h"

using namespace std;

RegSaleProduct::RegSaleProduct(ifstream* in, ofstream* out,Member &mem) {
	RegSaleProductUI ui;
	proinfo = ui.getinfo(in, out);
	Product::createProduct(mem.getId(), proinfo.productName, proinfo.productCompany, proinfo.price, proinfo.quantity,out);
	
	ui.outputresult(in, out); // output.txt에 결과 입력
}

productInfo RegSaleProductUI::getinfo(ifstream* in, ofstream* out) { // input.txt에서 정보 가져옴
	productInfo tmp;
	*in >> tmp.productName >> tmp.productCompany >> tmp.price >> tmp.quantity;
	proinfo = tmp;
	return tmp;
}

void RegSaleProductUI::outputresult(ifstream* in, ofstream* out) { // output.txt에 결과 입력
	*out << "3.1. 판매 의류 등록" << endl;
	*out << "> " << proinfo.productName << " " << proinfo.productCompany << " " << proinfo.price << " " << proinfo.quantity << endl << endl;
}