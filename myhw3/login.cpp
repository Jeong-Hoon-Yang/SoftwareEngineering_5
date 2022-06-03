#include <iostream>
#include <fstream>
#include "login.h"

using namespace std;


Member Login::showresult(ifstream* in, ofstream* out) {
	class LoginUI loginui;
	//class Member member;
	logininfo = loginui.getinfo(in, out); // 입력정보 가져옴
	loginui.outputresult(in, out); // output에 결과 입력 없는 경우 없어서 그냥 여기다 넣음
	return Member::verifyIdPw(logininfo.id, logininfo.password); 
	     // id,pw확인 후 맞으면 멤버 리턴
}

Logininfo LoginUI::getinfo(ifstream* in, ofstream* out) {
	Logininfo tmp;
	*in >> tmp.id >> tmp.password; // 입력 정보 받아옴 

	logininfo = tmp;
	return tmp;
}

void LoginUI::outputresult(ifstream* in, ofstream* out) {// output.txt.에 결과 입력
	*out << "2.1. 로그인" << endl;
	*out << ">" << " " << logininfo.id << " " << logininfo.password << endl << endl;
}

