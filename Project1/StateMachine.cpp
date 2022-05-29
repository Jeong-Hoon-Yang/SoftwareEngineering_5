#include <string>
#include "StateMachine.h"

/*
	�Լ� �̸� : StateMachine::run()
	���	  : STATE_END ���°� �� ������ event-action ���̺� ���ǵ� ��Ģ�� ����ڿ� ���� �߻��Ǵ� �̺�Ʈ�� ���� state machine�� ���۽�Ŵ
	���� ���� : ����
	��ȯ��    : ����
*/
void StateMachine::run()
{
	fin.open(INPUT_FILE_NAME);
	fout.open(OUTPUT_FILE_NAME);

	int i, j;
	Event curEvent;		// ���� �̺�Ʈ

	curState = STATE_LOGOUT;				// ���� �ʱ�ȭ
	while (curState != STATE_END)		// EVENT_QUIT�� �Էµ� ������ �ݺ� ������
	{
		//curEvent = getNextEvent();		// ���� �̺�Ʈ�� �Է¹���
		curEvent = doTask();
		for (i = 0; i < NUMBER_OF_TABLE_ENTRIES; i++)   // ���̺� ���ǵ� ����ü ��(transition ����)�� ���� ����
		{
			if (curState == table[i].curState)			// ���� ���¿� ��ġ�ϴ��� �˻�
			{
				if (curEvent == table[i].event)			// �Էµ� ���� �̺�Ʈ�� ��ġ�ϴ��� �˻�
				{
					// �ش� transition�� �߻��� �� �����ؾ� �� action �Լ����� �����Ŵ
					for (j = 0; j < table[i].number_of_actions; j++)
						(this->*table[i].action[j])();

					curState = table[i].nextState;		// ���̺� ���ǵ� ���� ���·� ���� ���¸� ������
					break;
				}
			}
		}
		cout << endl << endl;
	}
}


Event StateMachine::doTask()
{
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	if (fin.is_open()) {
		while (!fin.eof())
		{
			// �Է����Ͽ��� �޴� ���� 2���� �б�
			fin >> menu_level_1 >> menu_level_2;
			// �޴� ���� �� �ش� ���� ����
			switch (menu_level_1)
			{
			case 1:
			{
				switch (menu_level_2)
				{
					case 1:   // "1.1. ȸ�����ԡ� �޴� �κ�
					{
						return EVENT_JOIN;
						break;
					}
					case 2:   // "1.2. ȸ��Ż�� �޴� �κ�
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
					case 1:   // "2.1. �α��Ρ� �޴� �κ�
					{
						return EVENT_LOGIN;
						break;
					}
					case 2:   // "2.2. �α׾ƿ��� �޴� �κ�
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
					case 1:   // "3.1 �Ǹ� �Ƿ� ��ϡ� �޴� �κ�
					{
						return EVENT_SALE_REGISTRATION;
						break;
					}
					case 2:   // "3.2. ��� ��ǰ ��ȸ�� �޴� �κ�
					{
						return EVENT_INQUIRY_REGISTRATION_PRODUCT;
						break;
					}
					case 3:   // "3.3. �ǸſϷ��ǰ ��ȸ�� �޴� �κ�
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
					case 1:   // "4.1. ��ǰ�����˻��� �޴� �κ�
					{
						return EVENT_SEARCHE_PRODUCT;
						break;
					}
					case 2:   // "4.2. ��ǰ���š� �޴� �κ�
					{
						return EVENT_PURCHASE_PRODUCT;
						break;
					}
					case 3:   // "4.3 ��ǰ ���� ������ �޴� �κ�
					{
						return EVENT_INQUIRY_PURCHASE_LIST;
						break;
					}
					case 4:   // "4.4 ��ǰ ���� �������� �޴� �κ�
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
					case 1:   // "5.1 �Ǹ� ��ǰ ��衰 �޴� �κ�
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
					case 1:   // "6.1. ���ᡰ �޴� �κ�
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
	�Լ� �̸� : StateMachine::getNextEvent()
	���	  : ����ڷκ��� ���� �̺�Ʈ�� �Է¹���
	���� ���� : ����
	��ȯ��    : Event -> �Է¹��� �̺�Ʈ ��

Event StateMachine::getNextEvent()
{
	Event selectedEvent;       // ��ȯ�� �̺�Ʈ
	int inputEvent;				// ����ڷκ��� �Է¹��� �̺�Ʈ

	// �Է� �ȳ� �޼��� ���
	cout << "[���� ���� : " << getCurrentStateString() << "]" << endl;
	cout << "1. Deposit a 100 won coin" << endl;
	cout << "2. Press the refund button" << endl;
	cout << "3. Press the beverage button you want" << endl;
	cout << "4. Quit" << endl;
	cout << "Select an event # : ";

	// ����ڷκ��� �̺�Ʈ �Է¹���
	cin >> inputEvent;

	// �Է� ���� ���� ��ȯ�� �̺�Ʈ ���� ������
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
	�Լ� �̸� : StateMachine::join()
	���	  : LED ȭ�鿡 ���� ���Ե� �ݾ��� ǥ����
	���� ���� : displayedMoneyAmount -> ȭ�鿡 ��µ� �ݾ�
	��ȯ��    : ����
*/
void StateMachine::join()
{
	cout << "ȸ�������Դϴ�." << endl;
}


/*
	�Լ� �̸� : StateMachine::refundCoins()
	���	  : ��ȯ ��ư�� ������ �� ���Ե� �ݾ��� ��ȯ��
	���� ���� : refundedMoneyAmount -> ��ȯ�� �ݾ�
	��ȯ��    : ����
*/
void StateMachine::login()
{
	cout << "�α����Դϴ�." << endl;
}



/*
	�Լ� �̸� : StateMachine::withdraw(string)
	���	  : ���� ��ư�� ������ �Ѱų� ���� ���� ������.
	���� ���� : lightOn -> 1: on, 0: off
	��ȯ��    : ����
*/
void StateMachine::logout()
{
	cout << "�α׾ƿ��Դϴ�." << endl;
}



/*
	�Լ� �̸� : StateMachine::withdraw(string)
	���	  : ������ ���Ḧ �ܺη� ������.
	���� ���� : �Ű������� �ʿ� ������ �ٸ� �Լ��� �Ű������� ���߱� ���� �����ϰ� ���ǵ�(dummy parameter)
	��ȯ��    : ����
*/
void StateMachine::withdraw()
{
	cout << "ȸ��Ż���Դϴ�." << endl;
}


/*
	�Լ� �̸� : StateMachine::saleRegistration(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/
void StateMachine::saleRegistration()
{
	cout << "�Ǹŵ���Դϴ�." << endl;
}

/*
	�Լ� �̸� : StateMachine::inquiryRegistrationProduct(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/
void StateMachine::inquiryRegistrationProduct()
{
	cout << "��� ��ǰ ��ȸ�Դϴ�." << endl;
}

/*
	�Լ� �̸� : StateMachine::inquirySalesCompletedProduct(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/
void StateMachine::inquirySalesCompletedProduct()
{
	cout << "�ǸſϷ�Ȼ�ǰ��ȸ�Դϴ�." << endl;
}

/*
	�Լ� �̸� : StateMachine::inquirySalesStatistics(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/

void StateMachine::inquirySalesStatistics()
{
	cout << "�Ǹ������ȸ�Դϴ�." << endl;
}

/*
	�Լ� �̸� : StateMachine::searchProduct(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/

void StateMachine::searchProduct()
{
	cout << "��ǰ�˻��Դϴ�." << endl;
}

/*
	�Լ� �̸� : StateMachine::purchaseProduct(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/

void StateMachine::purchaseProduct()
{
	cout << "��ǰ �����Դϴ�." << endl;
}


/*
	�Լ� �̸� : StateMachine::inquiryProductPurchaseList(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/

void StateMachine::inquiryProductPurchaseList()
{
	cout << "��ǰ���Ÿ���Ʈ��ȸ�Դϴ�." << endl;
}

/*
	�Լ� �̸� : StateMachine::evaluatePurchaseSatisfactionDegree(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/

void StateMachine::evaluatePurchaseSatisfactionDegree()
{
	cout << "��ǰ���Ÿ��������Դϴ�." << endl;
}



/*
	�Լ� �̸� : StateMachine::exit(string)
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/

void StateMachine::exit()
{
	cout << "�����Դϴ�." << endl;
}
/*
	�Լ� �̸� : StateMachine::getCurrentStateString()
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
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
