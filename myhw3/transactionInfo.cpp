#include "transactionInfo.h"

using namespace std;

void TransactionInfo::getProducts(string mem_id, ofstream* out) {
	bool printed = false;
	for (int i = 0; i < TransactionInfoList.size(); i++) {
		if (TransactionInfoList[i].getBuyer().getId() == mem_id) {
			Product::getProductInfo(out, TransactionInfoList[i].getProduct().getSellerID());
			printed = true;
		}
	}
	if (printed) *out << endl;
}

void TransactionInfo::createTransInfo(Member seller, Member buyer, Product product) {
	TransactionInfo tmp;
	tmp.seller = seller;
	tmp.buyer = buyer;
	tmp.product = product;

	Product::minusQuantity(product);
	TransactionInfoList.push_back(tmp);
}

Member TransactionInfo::getSeller() {
	return this->seller;
}

Member TransactionInfo::getBuyer() {
	return this->buyer;
}

Product TransactionInfo::getProduct() {
	return this->product;
}

void TransactionInfo::setSeller(Member seller) {
	this->seller = seller;
}

void TransactionInfo::setBuyer(Member buyer) {
	this->buyer = buyer;
}

void TransactionInfo::setProduct(Product product) {
	this->product = product;
}