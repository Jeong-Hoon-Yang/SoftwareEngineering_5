#pragma once
#include "member.h"
#include "product.h"

class TransactionInfo {
	Member seller;
	Member buyer;
	Product product;

public:
	Product* getProducts();
	void createTransInfo();
};