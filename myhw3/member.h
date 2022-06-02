#pragma once
#include <vector>
#include <string>
#include "product.h"

using namespace std;

//class TranscationInfo;

typedef enum {
	STATE_LOGIN,
	STATE_LOGOUT
} login_state;

class Member {
	string id;
	string password;
	string name;
	int registerNumber;
	login_state loginState=STATE_LOGOUT;

public:
	Member();
	Member(string id, string password, int registerNumber, string name);
	static void storeMemInfo(string id, string password, string name, int registeredNumber);
	static Member verifyIdPw(string id, string password);
	void logout(Member& m);
	void deleteInfoRight(Member& m);
	//vector<TransactionInfo> getTransactionInfoList();
	static Member findMember(string id);
	void addPurchaseInfo(Product product);
	void addSaleProduct(string productName, string ProductCompany, int price, int quantity);
	//vector<TransactionInfo> getSaleProductList();
	void setId(string id);
	void setPassword(string password);
	void setName(string name);
	string getId();
	string getPassword();
	string getName();
};

static vector<Member> memberList;
static Member nousemember("nouse", "nouse", -1, "nouse");