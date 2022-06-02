#include <iostream>
#include <fstream>
#include "logout.h"

using namespace std;


Logout::Logout(ifstream* in, ofstream* out, Member& mem) {
	class LogoutUI logoutui; // �ٿ���� Ŭ���� ����
	mem.logout(mem); // �α׾ƿ� ����.
	logoutui.outputresult(in, out, mem);  // output�� ��� �Է�
}


void LogoutUI::outputresult(ifstream* in, ofstream* out,Member &mem) {
	*out << "2.2. �α׾ƿ�" << endl;
	*out << "> " << mem.getId() << endl << endl;
}