#include <iostream>
#include <fstream>
#include "login.h"

using namespace std;


Member Login::showresult(ifstream* in, ofstream* out) {
	class LoginUI loginui;
	//class Member member;
	logininfo = loginui.getinfo(in, out); // �Է����� ������
	loginui.outputresult(in, out); // output�� ��� �Է� ���� ��� ��� �׳� ����� ����
	return Member::verifyIdPw(logininfo.id, logininfo.password); 
	     // id,pwȮ�� �� ������ ��� ����
}

Logininfo LoginUI::getinfo(ifstream* in, ofstream* out) {
	Logininfo tmp;
	*in >> tmp.id >> tmp.password; // �Է� ���� �޾ƿ� 

	logininfo = tmp;
	return tmp;
}

void LoginUI::outputresult(ifstream* in, ofstream* out) {// output.txt.�� ��� �Է�
	*out << "2.1. �α���" << endl;
	*out << ">" << " " << logininfo.id << " " << logininfo.password << endl << endl;
}

