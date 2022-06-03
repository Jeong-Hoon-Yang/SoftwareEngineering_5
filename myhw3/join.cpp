#include <iostream>
#include <fstream>
#include "join.h"

using namespace std;

Join::Join(ifstream* in, ofstream* out) {
	class JoinUI joinui;
	memberinfo = joinui.getinfo(in, out); // �ٿ���� Ŭ���¿��� �Է����� ������
										  // +Memebr ��ü�� �����ϱ� ���� ���� ����
	Member::storeMemInfo(memberinfo.id, memberinfo.password, memberinfo.name, memberinfo.registernum);  //ȸ�� ����
	joinui.outputresult(in, out); // output.txt�� ��� �Է�
}

Memberinfo JoinUI::getinfo(ifstream* in, ofstream* out) { // input.txt���� ���� ������
	Memberinfo tmp;
	*in >> tmp.name >> tmp.registernum >> tmp.id >> tmp.password;
	memberinfo = tmp;
	return tmp;
}

void JoinUI::outputresult(ifstream* in, ofstream* out) { // output.txt�� ��� �Է�
	*out << "1.1. ȸ������" << endl;
	*out <<">"<< " " << memberinfo.name << " " << memberinfo.registernum << " " << memberinfo.id << " " << memberinfo.password << endl << endl;
}