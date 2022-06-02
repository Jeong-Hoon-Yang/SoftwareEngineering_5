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
	bool evaled = false;

public:
	Product();
	Product(string productName);
	static Product getProductInfoDetails(string productname,ofstream *out);
	static void getProductInfo(ofstream* out, string mem_id);
	static void getSoldProductInfoDetails(string mem_id, ofstream* out);
	static void setPurchaseSatisfaction(string productName, int satis, ofstream* out);
	static void getSatisfactionAndTotal(string mem_id, ofstream* out);
	static void getRegisteredProductInfo(string mem_id,ofstream *out);
	static void createProduct(string sellerID, string productName, string productCompany, int price, int quantity, ofstream* out);
	void setSellerID(string id);
	void setProductName(string name);
	void setProductCompany(string company);
	void setPrice(int price);
	string getSellerID();
	string getProductName();
	string getProductCompany();
	int getPrice();
	static void minusQuantity(Product product);
	int getRemainQuantity();
};

static vector<Product> productList;	// List of Registered Product
static Product nouseproduct("nouse");