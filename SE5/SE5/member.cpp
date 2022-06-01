#include <iostream>
#include "member.h"

void Member::storeMemInfo(string id, string password, string name, int registerNumber) {
	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i].id == id) {	// ID is already registered then return function
			cout << "already registered ID" << endl;
			return;
		}
	}

	Member tmp;

	tmp.id = id;
	tmp.password = password;
	tmp.name = name;
	tmp.registerNumber = registerNumber;
	tmp.loginState = STATE_LOGOUT;

	memberList.push_back(tmp);

	cout << tmp.name << ' ' << tmp.registerNumber << ' ' << tmp.id << ' ' << tmp.password << endl;
}

Member Member::verifyIdPw(string id, string password) {
	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i].id == id && memberList[i].password == password) {
			memberList[i].loginState = STATE_LOGIN;
			cout << memberList[i].id << ' ' << memberList[i].password << endl;
			return memberList[i];
		}
	}
}

void Member::logout(Member& m) {
	m.loginState == STATE_LOGOUT;
	cout << m.id << endl;
}

void Member::deleteInfoRight(Member& m) {
	for (auto it = memberList.begin(); it != memberList.end(); it++) {
		if (it->id == m.id) {
			cout << m.id << endl;
			memberList.erase(it);
			// add here
			// 등록한 상품들의 수량을 0으로 만드는 함수
			return;
		}
	}
}

vector<TransactionInfo> Member::getTransactionInfoList() {	
	vector<TransactionInfo> tList;
	for (int i = 0; i < TransactionInfoList.size(); i++) {
		if (TransactionInfoList[i].getBuyer().id == this->id) {
			tList.push_back(TransactionInfoList[i]);
		}
	}
	
	return tList;
}

void Member::addPurchaseInfo(Product product) {	// 구매내역 추가
	Member tmp;

	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i].id == product.getSellerID()) {
			tmp = memberList[i];
		}
	}

	TransactionInfo::createTransInfo(tmp, *this, product);
}

void Member::addSaleProduct(string productName, string productCompany, int price, int quantity) {	// 판매 의류 등록
	Product::createProduct(this->id, productName, productCompany, price, quantity);
}

vector<TransactionInfo> Member::getSaleProductList() {	// 판매 의류 조회
	vector<TransactionInfo> tList;
	for (int i = 0; i < TransactionInfoList.size(); i++) {
		if (TransactionInfoList[i].getSeller().id == this->id) {
			tList.push_back(TransactionInfoList[i]);
		}
	}

	return tList;
}