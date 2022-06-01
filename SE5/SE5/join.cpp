#include <iostream>
#include <fstream>
#include "join.h"

using namespace std;

Join::Join(ifstream* in, ofstream* out) {
	class JoinUI joinui;
	memberinfo = joinui.getinfo(in, out); // 바운더리 클래승에서 입력정보 가져옴
										  // +Memebr 객체에 전달하기 위해 정보 저장
	Member::storeMemInfo(memberinfo.id, memberinfo.password, memberinfo.name, memberinfo.registernum);  //회원 가입
	joinui.outputresult(in, out); // output.txt에 결과 입력
}

Memberinfo JoinUI::getinfo(ifstream* in, ofstream* out) { // input.txt에서 정보 가져옴
	Memberinfo tmp;
	*in >> tmp.name >> tmp.registernum >> tmp.id >> tmp.password;
	memberinfo = tmp;
	return tmp;
}

void JoinUI::outputresult(ifstream* in, ofstream* out) { // output.txt에 결과 입력
	*out << "1.1. 회원가입" << endl;
	*out << memberinfo.name << " " << memberinfo.registernum << " " << memberinfo.id << " " << memberinfo.password << endl;
}