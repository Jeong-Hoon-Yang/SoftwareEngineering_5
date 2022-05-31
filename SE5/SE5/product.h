#pragma once
#include <vector>
#include "transactionInfo.h"

vector<Product> productList;	// List of Registered Product

class Product {
	string sellerID;
	string productName;
	string productCompany;
	int price;
	int remainingQuantity;
	float avgPurchaseSatisfaction;
	int soldQuantity;
	int evaluationNum;	//Why needs this variable?

public:
	void getProductInfoDetails(); //print_type = 0 : sold, print_type = 1 : buy
	void getSoldProductInfoDetails();
	void setPurchaseSatisfaction(int satis);
	void getSatisfactionAndTotal();
	void getRegisteredProductInfo();
	void createProduct(string sellerID, string productName, string productCompany, int price, int quantity);
};