#pragma once
#include <vector>
#include <string>

using namespace std;

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
	static void createProduct(string sellerID, string productName, string productCompany, int price, int quantity);
	void setSellerID(string id);
	void setProductName(string name);
	void setProductCompany(string company);
	void setPrice(int price);
	string getSellerID();
	string getProductName();
	string getProductCompany();
	int getPrice();
};

static vector<Product> productList;	// List of Registered Product