#pragma once
#include <string>
#include <vector>
#include "transactionInfo.h"
#include "product.h"

using namespace std;

typedef enum {
	STATE_LOGIN,
	STATE_LOGOUT
} login_state;

class Member {
	string id;
	string password;
	string name;
	int registerNumber;
	login_state loginState;

public:
	static void storeMemInfo(string id, string password, string name, int registeredNumber);
	Member verifyIdPw(string id, string password);
	void logout(Member& m);
	void deleteInfoRight(Member& m);
	vector<TransactionInfo> getTransactionInfoList();
	void addPurchaseInfo(Product product);
	void addSaleProduct(string productName, string productCompany, int price, int quantity);
	vector<TransactionInfo> getSaleProductList();
};

static vector<Member> memberList;