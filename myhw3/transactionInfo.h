#pragma once
#include <iostream>
#include <fstream>
#include "member.h"
#include "product.h"

using namespace std;

class TransactionInfo {
	Member seller;
	Member buyer;
	Product product;

public:
	static void getProducts(string mem_id, ofstream* out);
	static void createTransInfo(Member seller, Member buyer, Product product);
	Member getSeller();
	Member getBuyer();
	Product getProduct();
	void setSeller(Member seller);
	void setBuyer(Member buyer);
	void setProduct(Product product);
};

static vector<TransactionInfo> TransactionInfoList;
