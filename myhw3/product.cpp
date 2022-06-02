#include <iostream>
#include <fstream>
#include <cmath>
#include "product.h"

Product::Product() {

}

Product::Product(string productName) {
	this->productName = productName;
}

void Product::getProductInfo(ofstream* out, string mem_id) {  // case '4 1' && '4 3'
	for (int i = 0; i < productList.size(); i++) {
		cout << productList[i].sellerID << ' ' << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].remainingQuantity << ' ' << productList[i].avgPurchaseSatisfaction << endl;
		*out << "> " << productList[i].sellerID << ' ' << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].remainingQuantity << ' ' << productList[i].avgPurchaseSatisfaction << endl;
	}
	
}

Product Product::getProductInfoDetails(string productname,ofstream *out) {  // case '4 1' && '4 3'
	//cout << sellerID << ' ' << productName << ' ' << productCompany << ' ' << price << ' ' << remainingQuantity << ' ' << avgPurchaseSatisfaction << endl;
	for (int i = 0; i < productList.size(); i++) {
		if (productList[i].productName == productname) {
			cout << productList[i].getSellerID() << ' ' << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].remainingQuantity << ' ' << productList[i].avgPurchaseSatisfaction << endl;
			
			*out<<"> " << productList[i].getSellerID() << ' ' << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].remainingQuantity << ' ' << productList[i].avgPurchaseSatisfaction << endl << endl;
			return productList[i];
		}
	}
	return nouseproduct;
}

void Product::getSoldProductInfoDetails(string mem_id, ofstream* out) {	// case '3 3'
	bool printed = false;
	for (int i = 0; i < productList.size(); i++) {
		if (productList[i].getSellerID() == mem_id && productList[i].remainingQuantity == 0) {
			cout << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].soldQuantity << ' ' << productList[i].avgPurchaseSatisfaction << endl;
			*out << "> " << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].soldQuantity << ' ' << productList[i].avgPurchaseSatisfaction << endl;
			printed = true;
		}
	}
	if(printed) *out << endl;
}

void Product::setPurchaseSatisfaction(string productName, int satis, ofstream* out) {	// case '4 4'
	Product tmp;

	for (int i = 0; i < productList.size(); i++) {
		if (productList[i].productName == productName) {
			tmp = productList[i];
			break;
		}
	}

	tmp.avgPurchaseSatisfaction += satis;
	if (tmp.evaled) {
		tmp.avgPurchaseSatisfaction /= 2;
	}
	else {
		tmp.evaled = true;
	}

	int avgps;
	avgps = floor(tmp.avgPurchaseSatisfaction + 0.5);


	cout << tmp.sellerID << ' ' << tmp.productName << ' ' << avgps << endl;
	*out << "> " << tmp.sellerID << ' ' << tmp.productName << ' ' << avgps << endl << endl;
}

void Product::getSatisfactionAndTotal(string mem_id, ofstream* out) {	// case '5 1'
	bool printed = false;
	for (int i = 0; i < productList.size(); i++) {
		if (productList[i].getSellerID() == mem_id) {
			cout << productList[i].productName << ' ' << productList[i].soldQuantity * productList[i].price << ' ' << productList[i].avgPurchaseSatisfaction << endl;
			*out << "> " << productList[i].productName << ' ' << productList[i].soldQuantity * productList[i].price << ' ' << productList[i].avgPurchaseSatisfaction << endl;
			printed = true;
		}
	}
	if (printed) *out << endl;
}

void Product::getRegisteredProductInfo(string mem_id,ofstream *out) {	// case '3 1' && '3 2'
	for (int i = 0; i < productList.size(); i++) {
		if (productList[i].getSellerID() == mem_id) {
			cout << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].remainingQuantity + productList[i].soldQuantity << endl;
			*out << "> " << productList[i].productName << ' ' << productList[i].productCompany << ' ' << productList[i].price << ' ' << productList[i].remainingQuantity + productList[i].soldQuantity << endl;
		}
	}
	*out << endl;
}

void Product::createProduct(string sellerID, string productName, string productCompany, int price, int quantity, ofstream* out) {	// case '3 1'
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

	productList.push_back(tmp);

	cout << productList.back().productName << ' ' << productList.back().productCompany << ' ' << productList.back().price << ' ' << productList.back().remainingQuantity + productList.back().soldQuantity << endl;
}

void Product::minusQuantity(Product product) {
	for (int i = 0; i < productList.size(); i++) {
		if (productList[i].getProductName() == product.getProductName()) {
			cout << "minus success" << endl;
			cout << productList[i].remainingQuantity << " " << productList[i].soldQuantity << endl;
			productList[i].remainingQuantity--;
			productList[i].soldQuantity++;
			cout << productList[i].remainingQuantity << " " << productList[i].soldQuantity << endl;
		}
	}
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

int Product::getRemainQuantity() {
	return this->remainingQuantity;
}