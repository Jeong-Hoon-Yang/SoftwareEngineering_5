#pragma once
#include "member.h"
#include "product.h"

class TransactionInfo {
	Member seller;
	Member buyer;
	Product product;

public:
	Product* getProducts();
	static void createTransInfo(Member seller, Member buyer, Product product);
	Member getSeller();
	Member getBuyer();
	Product getProduct();
	void setSeller(Member seller);
	void setBuyer(Member buyer);
	void setProduct(Product product);
};

static vector<TransactionInfo> TransactionInfoList;