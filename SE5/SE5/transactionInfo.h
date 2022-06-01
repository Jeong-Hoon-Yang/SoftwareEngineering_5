#pragma once
#include <vector>
#include "member.h"
#include "product.h"

using namespace std;

class TransactionInfo {
	Member seller;
	Member buyer;
	Product product;

public:
	Product* getProducts();
	static void createTransInfo(Member sellor, Member buyer, Product product);
	Member getSeller();
	Member getBuyer();
	void setSeller(Member seller);
	void setBuyer(Member buyer);
	void setProduct(Product product);
};

static vector<TransactionInfo> TransactionInfoList;