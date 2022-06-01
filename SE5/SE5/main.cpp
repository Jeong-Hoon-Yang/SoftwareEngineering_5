#include <iostream>
#include <fstream>
#include "member.h"
#include "product.h"
#include "transactionInfo.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

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
				break;
			}
			case 2: { // ȸ�� Ż��
				cout << "ȸ�� Ż��" << endl;
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
				break;
			}
			case 2: { // �α׾ƿ�
				cout << "�α׾ƿ�" << endl;
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
				break;
			}
			case 2: { // ��� ��ǰ ��ȸ
				cout << "��� ��ǰ ��ȸ" << endl;
				break;
			}
			case 3: { // �Ǹ� �Ϸ� ��ǰ ��ȸ
				cout << "�Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;
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
				break;
			}
			case 2: { // ��ǰ ����
				cout << "��ǰ ����" << endl;
				break;
			}
			case 3: { // ��ǰ ���� ���� ��ȸ
				cout << "��ǰ ���� ���� ��ȸ" << endl;
				break;
			}
			case 4: { // ��ǰ ���Ÿ����� ��
				cout << "��ǰ ���Ÿ����� ��" << endl;
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