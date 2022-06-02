#include <iostream>
#include "product.h"

void Product::getProductInfoDetails() {  // case '4 1' && '4 3'
	cout << sellerID << ' ' << productName << ' ' << productCompany << ' ' << price << ' ' << remainingQuantity << ' ' << avgPurchaseSatisfaction << endl;
}

void Product::getSoldProductInfoDetails() {	// case '3 3'
	cout << productName << ' ' << productCompany << ' ' << price << ' ' << soldQuantity << ' ' << avgPurchaseSatisfaction << endl;
}

void Product::setPurchaseSatisfaction(int satis) {	// case '4 4'
	avgPurchaseSatisfaction += satis;
	avgPurchaseSatisfaction /= 2;

	cout << sellerID << ' ' << productName << ' ' << avgPurchaseSatisfaction << endl;
}

void Product::getSatisfactionAndTotal() {	// case '5 1'
	cout << productName << ' ' << price * soldQuantity << ' ' << avgPurchaseSatisfaction << endl;
}

void Product::getRegisteredProductInfo() {	// case '3 1' && '3 2'
	cout << productName << ' ' << productCompany << ' ' << price << ' ' << remainingQuantity + soldQuantity << endl;
}

void Product::createProduct(string sellerID, string productName, string productCompany, int price, int quantity) {	// case '3 1'
	for (int i = 0; i < productList.size(); i++) {
		if (productList[i].productName == productName) {	// productName is already registered then return function
			cout << "already registered product" << endl;
			return;
		}
	}

	Product tmp;

	tmp.sellerID = sellerID;
	tmp.productName = productName;
	tmp.productCompany = productCompany;
	tmp.price = price;
	tmp.remainingQuantity = quantity;
	tmp.avgPurchaseSatisfaction = 0;
	tmp.soldQuantity = 0;
	tmp.evaluationNum = 0;
	tmp.getRegisteredProductInfo();

	productList.push_back(tmp);
}

void Product::setSellerID(string id) {
	this->sellerID = id;
}

void Product::setProductName(string name) {
	this->productName = name;
}

void Product::setProductCompany(string company) {
	this->productCompany = company;
}

void Product::setPrice(int price) {
	this->price = price;
}

string Product::getSellerID() {
	return this->sellerID;
}

string Product::getProductName() {
	return this->productName;
}

string Product::getProductCompany() {
	return this->productCompany;
}

int Product::getPrice() {
	return this->price;
}