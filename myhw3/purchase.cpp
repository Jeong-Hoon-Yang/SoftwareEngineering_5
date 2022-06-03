#include <iostream>
#include <fstream>
#include "purchase.h"

using namespace std;

Purchase::Purchase(ifstream* in, ofstream* out, Member presentmem, Product presentproduct) {
	PurchaseUI ui;

	data = ui.getinfo(in, out, presentmem, presentproduct);

	ui.outputresult(in, out);
}

Trans PurchaseUI::getinfo(ifstream* in, ofstream* out, Member presentmem, Product presentproduct) { // input.txt에서 정보 가져옴
	Trans tmp;
	Member seller;
	seller = Member::findMember(presentproduct.getSellerID());

	tmp.seller = seller;
	tmp.buyer = presentmem;
	tmp.product= presentproduct;

	data = tmp;

	return tmp;
}

void PurchaseUI::outputresult(ifstream* in, ofstream* out) { // output.txt에 결과 입력
	*out << "4.2. 상품 구매" << endl;

	TransactionInfo::createTransInfo(data.seller, data.buyer, data.product);

	*out << "> " << data.product.getSellerID() << ' ' << data.product.getProductName() << endl << endl;
}