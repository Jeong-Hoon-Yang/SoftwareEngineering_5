#include "transactionInfo.h"


Product* TransactionInfo::getProducts() {
	return &this->product;
}

void TransactionInfo::createTransInfo(Member seller, Member buyer, Product product) {
	TransactionInfo tmp;
	tmp.seller = seller;
	tmp.buyer = buyer;
	tmp.product = product;

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
