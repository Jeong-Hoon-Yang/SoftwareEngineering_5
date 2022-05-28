#include <string>
#include "StateMachine.h"

/*
	함수 이름 : StateMachine::run()
	기능	  : STATE_END 상태가 될 때까지 event-action 테이블에 정의된 규칙과 사용자에 의해 발생되는 이벤트에 따라 state machine을 동작시킴
	전달 인자 : 없음
	반환값    : 없음
*/
void StateMachine::run()
{
	fin.open(INPUT_FILE_NAME);
	fout.open(OUTPUT_FILE_NAME);

	int i, j;
	Event curEvent;		// 현재 이벤트

	curState = STATE_LOGOUT;				// 상태 초기화
	while (curState != STATE_END)		// EVENT_QUIT이 입력될 때까지 반복 수행함
	{
		//curEvent = getNextEvent();		// 다음 이벤트를 입력받음
		curEvent = doTask();
		for (i = 0; i < NUMBER_OF_TABLE_ENTRIES; i++)   // 테이블에 정의된 전각체 행(transition 내용)에 대해 비교함
		{
			if (curState == table[i].curState)			// 현재 상태와 일치하는지 검사
			{
				if (curEvent == table[i].event)			// 입력된 현재 이벤트와 일치하는지 검사
				{
					// 해당 transition이 발생할 때 수행해야 할 action 함수들을 실행시킴
					for (j = 0; j < table[i].number_of_actions; j++)
						(this->*table[i].action[j])();

					curState = table[i].nextState;		// 테이블에 정의된 다음 상태로 현재 상태를 변경함
					break;
				}
			}
		}
		cout << endl << endl;
	}
}


Event StateMachine::doTask()
{
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	if (fin.is_open()) {
		while (!fin.eof())
		{
			// 입력파일에서 메뉴 숫자 2개를 읽기
			fin >> menu_level_1 >> menu_level_2;
			// 메뉴 구분 및 해당 연산 수행
			switch (menu_level_1)
			{
			case 1:
			{
				switch (menu_level_2)
				{
					case 1:   // "1.1. 회원가입“ 메뉴 부분
					{
						return EVENT_JOIN;
						break;
					}
					case 2:   // "1.2. 회원탈퇴“ 메뉴 부분
					{
						return EVENT_WITHDRAW;
						break;
					}
				}
			}
			case 2:
			{
				switch (menu_level_2)
				{
					case 1:   // "2.1. 로그인“ 메뉴 부분
					{
						return EVENT_LOGIN;
						break;
					}
					case 2:   // "2.2. 로그아웃“ 메뉴 부분
					{ 
						return EVENT_LOGOUT;
						break;
					}
				}
			}
			case 3:
			{
				switch (menu_level_2)
				{
					case 1:   // "3.1 판매 의류 등록“ 메뉴 부분
					{
						return EVENT_SALE_REGISTRATION;
						break;
					}
					case 2:   // "3.2. 등록 상품 조회“ 메뉴 부분
					{
						return EVENT_INQUIRY_REGISTRATION_PRODUCT;
						break;
					}
					case 3:   // "3.3. 판매완료상품 조회“ 메뉴 부분
					{
						return EVENT_INQUIRY_SALES_COMPLETED_PRODUCT;
						break;
					}
				}
			}
			case 4:
			{
				switch (menu_level_2)
				{
					case 1:   // "4.1. 상품정보검색“ 메뉴 부분
					{
						return EVENT_SEARCHE_PRODUCT;
						break;
					}
					case 2:   // "4.2. 상품구매“ 메뉴 부분
					{
						return EVENT_PURCHASE_PRODUCT;
						break;
					}
					case 3:   // "4.3 상품 구매 내역“ 메뉴 부분
					{
						return EVENT_INQUIRY_PURCHASE_LIST;
						break;
					}
					case 4:   // "4.4 상품 구매 만족도“ 메뉴 부분
					{
						return EVENT_EVALUATE_PURCHASE_SATISFACTION_DEGREE;
						break;
					}
				}
			}
			case 5:
			{
				switch (menu_level_2)
				{
					case 1:   // "5.1 판매 상품 통계“ 메뉴 부분
					{
						return EVENT_INQUIRY_SALES_STATICS;
						break;
					}
				}
			}
			case 6:
			{
				switch (menu_level_2)
				{
					case 1:   // "6.1. 종료“ 메뉴 부분
					{
						fin.close();
						fout.close();
						return EVENT_QUIT;
						break;
					}

				}

			}
			default:
				fin.close();
				fout.close();
				return EVENT_QUIT;
			}
			
		}
	}
}



/*
	함수 이름 : StateMachine::getNextEvent()
	기능	  : 사용자로부터 다음 이벤트를 입력받음
	전달 인자 : 없음
	반환값    : Event -> 입력받은 이벤트 값

Event StateMachine::getNextEvent()
{
	Event selectedEvent;       // 반환할 이벤트
	int inputEvent;				// 사용자로부터 입력받은 이벤트

	// 입력 안내 메세지 출력
	cout << "[현재 상태 : " << getCurrentStateString() << "]" << endl;
	cout << "1. Deposit a 100 won coin" << endl;
	cout << "2. Press the refund button" << endl;
	cout << "3. Press the beverage button you want" << endl;
	cout << "4. Quit" << endl;
	cout << "Select an event # : ";

	// 사용자로부터 이벤트 입력받음
	cin >> inputEvent;

	// 입력 값에 따라 반환할 이벤트 값을 결정함
	switch (inputEvent)
	{
	case 1:
		selectedEvent = EVENT_JOIN;
		break;
	case 2:
		
		break;
	case 3:
		
		break;
	case 4:
	default:
		selectedEvent = EVENT_QUIT;
		curState = STATE_END;
	}

	return selectedEvent;
}
*/
/*
	함수 이름 : StateMachine::join()
	기능	  : LED 화면에 현재 투입된 금액을 표시함
	전달 인자 : displayedMoneyAmount -> 화면에 출력될 금액
	반환값    : 없음
*/
void StateMachine::join()
{
	cout << "회원가입입니다." << endl;
}


/*
	함수 이름 : StateMachine::refundCoins()
	기능	  : 반환 버튼을 눌렀을 때 투입된 금액을 반환함
	전달 인자 : refundedMoneyAmount -> 반환될 금액
	반환값    : 없음
*/
void StateMachine::login()
{
	cout << "로그인입니다." << endl;
}



/*
	함수 이름 : StateMachine::withdraw(string)
	기능	  : 음료 버튼에 조명을 켜거나 끄는 동작 수행함.
	전달 인자 : lightOn -> 1: on, 0: off
	반환값    : 없음
*/
void StateMachine::logout()
{
	cout << "로그아웃입니다." << endl;
}



/*
	함수 이름 : StateMachine::withdraw(string)
	기능	  : 선택한 음료를 외부로 내보냄.
	전달 인자 : 매개변수는 필요 없지만 다른 함수와 매개변수를 맞추기 위해 동일하게 정의됨(dummy parameter)
	반환값    : 없음
*/
void StateMachine::withdraw()
{
	cout << "회원탈퇴입니다." << endl;
}


/*
	함수 이름 : StateMachine::saleRegistration(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/
void StateMachine::saleRegistration()
{
	cout << "판매등록입니다." << endl;
}

/*
	함수 이름 : StateMachine::inquiryRegistrationProduct(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/
void StateMachine::inquiryRegistrationProduct()
{
	cout << "등록 상품 조회입니다." << endl;
}

/*
	함수 이름 : StateMachine::inquirySalesCompletedProduct(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/
void StateMachine::inquirySalesCompletedProduct()
{
	cout << "판매완료된상품조회입니다." << endl;
}

/*
	함수 이름 : StateMachine::inquirySalesStatistics(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/

void StateMachine::inquirySalesStatistics()
{
	cout << "판매통계조회입니다." << endl;
}

/*
	함수 이름 : StateMachine::searchProduct(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/

void StateMachine::searchProduct()
{
	cout << "상품검색입니다." << endl;
}

/*
	함수 이름 : StateMachine::purchaseProduct(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/

void StateMachine::purchaseProduct()
{
	cout << "상품 구매입니다." << endl;
}


/*
	함수 이름 : StateMachine::inquiryProductPurchaseList(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/

void StateMachine::inquiryProductPurchaseList()
{
	cout << "상품구매리스트조회입니다." << endl;
}

/*
	함수 이름 : StateMachine::evaluatePurchaseSatisfactionDegree(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/

void StateMachine::evaluatePurchaseSatisfactionDegree()
{
	cout << "상품구매만족도평가입니다." << endl;
}



/*
	함수 이름 : StateMachine::exit(string)
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/

void StateMachine::exit()
{
	cout << "종료입니다." << endl;
}
/*
	함수 이름 : StateMachine::getCurrentStateString()
	기능	  : 현재 상태에 해당하는 출력용 문자열을 생성해서 반환함
	전달 인자 : 없음
	반환값    : string -> 출력용 상태 문자열
*/
string StateMachine::getCurrentStateString()
{
	string returnedString;

	switch (curState)
	{
	case STATE_LOGIN:
		returnedString = "STATE_LOGIN";
		break;
	case STATE_LOGOUT:
		returnedString = "STATE_LOGOUT";
		break;

	}
	return returnedString;
}
