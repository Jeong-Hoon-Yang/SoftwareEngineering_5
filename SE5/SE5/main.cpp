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

// 파일 입출력을 위한 초기화
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
		// 입력파일에서 메뉴 숫자 2개 읽기
		in_fp >> menu_level_1 >> menu_level_2;
		cout << menu_level_1 << " " << menu_level_2 << endl;

		switch (menu_level_1)
		{
		case 1:
		{ // 회원 가입, 회원 탈퇴
			switch (menu_level_2)
			{
			case 1: { // 회원 가입
				cout << "회원 가입" << endl;
				break;
			}
			case 2: { // 회원 탈퇴
				cout << "회원 탈퇴" << endl;
				break;
			}
			}
			break;
		}

		case 2:
		{ // 로그인, 로그아웃
			switch (menu_level_2) {
			case 1: { // 로그인
				cout << "로그인" << endl;
				break;
			}
			case 2: { // 로그아웃
				cout << "로그아웃" << endl;
				break;
			}
			}
			break;
		}

		case 3:
		{ // 판매 의류 등록, 등록 상품 조회, 판매 완료 상품 조회
			switch (menu_level_2) {
			case 1: { // 판매 의류 등록
				cout << "판매 의류 등록" << endl;
				break;
			}
			case 2: { // 등록 상품 조회
				cout << "등록 상품 조회" << endl;
				break;
			}
			case 3: { // 판매 완료 상품 조회
				cout << "판매 완료 상품 조회" << endl;
				break;
			}
			}
			break;
		}

		case 4:
		{ // 상품 정보 검색, 상품 구매, 상품 구매 내역 조회, 상품 구매만족도 평가
			switch (menu_level_2) {
			case 1: { // 상품 정보 검색
				cout << "상품 정보 검색" << endl;
				break;
			}
			case 2: { // 상품 구매
				cout << "상품 구매" << endl;
				break;
			}
			case 3: { // 상품 구매 내역 조회
				cout << "상품 구매 내역 조회" << endl;
				break;
			}
			case 4: { // 상품 구매만족도 평가
				cout << "상품 구매만족도 평가" << endl;
				break;
			}
			}
			break;
		}

		case 5:
		{ // 판매 상품 통계
			switch (menu_level_2) {
			case 1: { // 판매 상품 통계
				cout << "판매 상품 통계" << endl;
				break;
			}
			}
			break;
		}

		case 6:
		{ // 종료
			switch (menu_level_2) {
			case 1: { // 종료
				cout << "종료" << endl;
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
	out_fp << "6.1 종료" << endl;
}