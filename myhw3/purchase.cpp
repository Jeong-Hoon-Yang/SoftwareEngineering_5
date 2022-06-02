#include <iostream>
#include <fstream>
#include "purchase.h"

using namespace std;

Purchase::Purchase(ifstream* in, ofstream* out, Member presentmem, Product presentproduct) {
	PurchaseUI ui;

	data = ui.getinfo(in, out, presentmem, presentproduct);

	ui.outputresult(in, out);
}

Trans PurchaseUI::getinfo(ifstream* in, ofstream* out, Member presentmem, Product presentproduct) { // input.txt���� ���� ������
	Trans tmp;
	Member seller;
	seller = Member::findMember(presentproduct.getSellerID());

	tmp.seller = seller;
	tmp.buyer = presentmem;
	tmp.product= presentproduct;

	data = tmp;

	return tmp;
}

void PurchaseUI::outputresult(ifstream* in, ofstream* out) { // output.txt�� ��� �Է�
	*out << "4.2. ��ǰ ����" << endl;

	TransactionInfo::createTransInfo(data.seller, data.buyer, data.product);

	*out << "> " << data.product.getSellerID() << ' ' << data.product.getProductName() << endl << endl;
}