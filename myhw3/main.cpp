#include <iostream>
#include <fstream>
#include "join.h"
#include "login.h"
#include "logout.h"
#include "withdraw.h"
#include "regsaleproduct.h"
#include "showRegProduct.h"
#include "showSoldProduct.h"
#include "serachProduct.h"
#include "showStatistic.h"
#include "showPurInfo.h"
#include "evalSatisfaction.h"
#include "purchase.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

Member presentmember;
Product presentproduct;

void doTask();
void program_exit();

//FILE* in_fp, * out_fp;

// ���� ������� ���� �ʱ�ȭ
ifstream in_fp(INPUT_FILE_NAME);
ofstream out_fp(OUTPUT_FILE_NAME);

int main() {

	doTask();


	return 0;
}

void doTask() {
	cout << "doTask() start" << endl;
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit) {
		// �Է����Ͽ��� �޴� ���� 2�� �б�
		in_fp >> menu_level_1 >> menu_level_2;
		cout << menu_level_1 << " " << menu_level_2 << endl;

		switch (menu_level_1)
		{
		case 1:
		{ // ȸ�� ����, ȸ�� Ż��
			switch (menu_level_2)
			{
			case 1: { // ȸ�� ����
				cout << "ȸ�� ����" << endl;
				Join Join(&in_fp,&out_fp);
				break;
			}
			case 2: { // ȸ�� Ż��
				cout << "ȸ�� Ż��" << endl;
				//Withdraw Withdraw(&in_fp, &out_fp, presentmember);
				break;
			}
			}
			break;
		}

		case 2:
		{ // �α���, �α׾ƿ�
			switch (menu_level_2) {
			case 1: { // �α���
				cout << "�α���" << endl;
				Login login;
				presentmember = login.showresult(&in_fp, &out_fp);

				break;
			}
			case 2: { // �α׾ƿ�
				cout << "�α׾ƿ�" << endl;
				Logout Logout(&in_fp, &out_fp,presentmember);
				presentmember = nousemember;
				break;
			}
			}
			break;
		}

		case 3:
		{ // �Ǹ� �Ƿ� ���, ��� ��ǰ ��ȸ, �Ǹ� �Ϸ� ��ǰ ��ȸ
			switch (menu_level_2) {
			case 1: { // �Ǹ� �Ƿ� ���
				cout << "�Ǹ� �Ƿ� ���" << endl;
				RegSaleProduct RegSaleProduct(&in_fp, &out_fp,presentmember);
				break;
			}
			case 2: { // ��� ��ǰ ��ȸ
				cout << "��� ��ǰ ��ȸ" << endl;
				showRegProduct showRegProduct(&in_fp, &out_fp, presentmember.getId());
				break;
			}
			case 3: { // �Ǹ� �Ϸ� ��ǰ ��ȸ
				cout << "�Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;
				showSoldProduct showSoldProduct(&in_fp, &out_fp, presentmember.getId());
				break;
			}
			}
			break;
		}

		case 4:
		{ // ��ǰ ���� �˻�, ��ǰ ����, ��ǰ ���� ���� ��ȸ, ��ǰ ���Ÿ����� ��
			switch (menu_level_2) {
			case 1: { // ��ǰ ���� �˻�
				cout << "��ǰ ���� �˻�" << endl;
				SearchProduct searchproduct;
				presentproduct = searchproduct.showresult(&in_fp, &out_fp);
				break;
			}
			case 2: { // ��ǰ ����
				cout << "��ǰ ����" << endl;
				Purchase Purchase(&in_fp, &out_fp, presentmember, presentproduct);
				break;
			}
			case 3: { // ��ǰ ���� ���� ��ȸ
				cout << "��ǰ ���� ���� ��ȸ" << endl;
				showPurInfo showPurInfo(&in_fp, &out_fp, presentmember.getId());
				break;
			}
			case 4: { // ��ǰ ���Ÿ����� ��
				cout << "��ǰ ���Ÿ����� ��" << endl;
				evalSatisfaction evalSatisfaction(&in_fp, &out_fp);
				break;
			}
			}
			break;
		}

		case 5:
		{ // �Ǹ� ��ǰ ���
			switch (menu_level_2) {
			case 1: { // �Ǹ� ��ǰ ���
				cout << "�Ǹ� ��ǰ ���" << endl;
				showStatistic showStatistic(&in_fp, &out_fp, presentmember.getId());
				break;
			}
			}
			break;
		}

		case 6:
		{ // ����
			switch (menu_level_2) {
			case 1: { // ����
				cout << "����" << endl;
				program_exit();
				is_program_exit = 1;
				break;
			}
			}
			break;
		}

		}
	}
}

void program_exit() {
	out_fp << "6.1 ����" << endl;
}