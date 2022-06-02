#include <iostream>
#include <fstream>
#include "logout.h"

using namespace std;


Logout::Logout(ifstream* in, ofstream* out, Member& mem) {
	class LogoutUI logoutui; // 바운더리 클래스 생성
	mem.logout(mem); // 로그아웃 실행.
	logoutui.outputresult(in, out, mem);  // output에 결과 입력
}


void LogoutUI::outputresult(ifstream* in, ofstream* out,Member &mem) {
	*out << "2.2. 로그아웃" << endl;
	*out << "> " << mem.getId() << endl << endl;
}