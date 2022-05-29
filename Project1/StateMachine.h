#include <iostream>
#include <string>
#define NUMBER_OF_TABLE_ENTRIES 100     // event-action table�� ���� entry ����
#define MAX_NUMBER_OF_ACTIONS   3       // transition �� ����Ǵ� �ִ� action ����

using namespace std;
//���� ����� �κ�
#include<iostream>
#include<fstream>

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// State ������ ����
typedef enum {
    STATE_LOGOUT,
    STATE_LOGIN,
    STATE_INQUIRY_PRODUCT,
    STATE_COMPLETION_PURCHASE,
    STATE_INQUIRY_PURCHASE_LIST,
    STATE_END
} State;


// Event ������ ����
typedef enum {
    EVENT_JOIN,
    EVENT_WITHDRAW,
    EVENT_LOGIN,
    EVENT_LOGOUT,
    EVENT_SALE_REGISTRATION,
    EVENT_INQUIRY_REGISTRATION_PRODUCT,
    EVENT_INQUIRY_SALES_COMPLETED_PRODUCT,
    EVENT_INQUIRY_SALES_STATICS,
    EVENT_SEARCHE_PRODUCT,
    EVENT_PURCHASE_PRODUCT,
    EVENT_INQUIRY_PURCHASE_LIST,
    EVENT_EVALUATE_PURCHASE_SATISFACTION_DEGREE,
    EVENT_QUIT
} Event;

// ���� �ڵ��Ǹű⸦ ���� StateMachine Ŭ���� ����
class StateMachine
{
private:
    State curState;     // ���� ����
    //string inputValue1, inputValue2, inputValue3, inputValue4;
    // ���� ����� ��������
    ifstream fin;
    ofstream fout;

    // event-action table structure ����
    typedef struct {
        State curState;             // ���� ����
        Event event;                // ����ڷκ��� �߻��� �̺�Ʈ
        int number_of_actions;                                      // �ش� transition�� ����Ǵ� action �Լ��� ����
        void (StateMachine::* action[MAX_NUMBER_OF_ACTIONS])();   // action �Լ� �������� �迭
        // string action_parameter[MAX_NUMBER_OF_ACTIONS];                 // action �Լ��� �Ű����� �迭
        State nextState;            // transition �Ŀ� ����� ���� ����
    } EventActionTable;

    // vending machine���� ����� event-action table �ʱ�ȭ
    EventActionTable table[NUMBER_OF_TABLE_ENTRIES]{
        {STATE_LOGOUT,	        EVENT_JOIN,	           1,  {&StateMachine::join},	         STATE_LOGOUT},
        {STATE_LOGOUT,	        EVENT_LOGIN,	       1,  {&StateMachine::login},	         STATE_LOGIN},
        {STATE_LOGIN,	        EVENT_SALE_REGISTRATION,    1,  {&StateMachine::saleRegistration},	         STATE_LOGIN},
        {STATE_LOGIN,EVENT_INQUIRY_REGISTRATION_PRODUCT,    1,  {&StateMachine::inquiryRegistrationProduct}, STATE_LOGIN},
        {STATE_LOGIN,EVENT_INQUIRY_SALES_COMPLETED_PRODUCT,    1,  {&StateMachine::inquirySalesCompletedProduct},  STATE_LOGIN},
        {STATE_LOGIN,EVENT_INQUIRY_SALES_STATICS,    1,  {&StateMachine::inquirySalesStatistics},  STATE_LOGIN},
        
        //��ǰ �˻� �� ����
        {STATE_LOGIN,	        EVENT_SEARCHE_PRODUCT,    1,  {&StateMachine::searchProduct},	         STATE_INQUIRY_PRODUCT},
        {STATE_INQUIRY_PRODUCT,	        EVENT_PURCHASE_PRODUCT,    1,  {&StateMachine::purchaseProduct},	         STATE_COMPLETION_PURCHASE},
        {STATE_COMPLETION_PURCHASE,	        EVENT_INQUIRY_PURCHASE_LIST,    1,  {&StateMachine::inquiryProductPurchaseList},	         STATE_INQUIRY_PURCHASE_LIST},
        {STATE_INQUIRY_PURCHASE_LIST,	        EVENT_EVALUATE_PURCHASE_SATISFACTION_DEGREE,    1,  {&StateMachine::evaluatePurchaseSatisfactionDegree},	         STATE_LOGIN},
        {STATE_LOGIN,	        EVENT_INQUIRY_PURCHASE_LIST,    1,  {&StateMachine::inquiryProductPurchaseList},	         STATE_INQUIRY_PURCHASE_LIST},

        //�α׾ƿ��̺�Ʈ
        {STATE_LOGIN,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        {STATE_INQUIRY_PRODUCT,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        {STATE_COMPLETION_PURCHASE,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        { STATE_INQUIRY_PURCHASE_LIST,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        //ȸ��Ż���̺�Ʈ
        {STATE_LOGIN,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        {STATE_INQUIRY_PRODUCT,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        {STATE_COMPLETION_PURCHASE,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        {STATE_INQUIRY_PURCHASE_LIST,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        //�����̺�Ʈ
        {STATE_LOGOUT,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_LOGIN,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_INQUIRY_PRODUCT,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_COMPLETION_PURCHASE,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_INQUIRY_PURCHASE_LIST,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
       
    };

    //�̺�Ʈ
    void join(); //ȸ������
    void login();            // �α���
    void logout();                                //�α׾ƿ�
    void withdraw();                         // ȸ��Ż��
    void saleRegistration();                     //�Ǹ��Ƿ����
    void inquiryRegistrationProduct();            //��ϻ�ǰ��ȸ
    void inquirySalesCompletedProduct();          //�ǸſϷ��ǰ��ȸ
    void inquirySalesStatistics();            //�Ǹ����
    void searchProduct();                     //��ǰ�˻�
    void purchaseProduct();                   //��ǰ����
    void inquiryProductPurchaseList();        //��ǰ ���� ���� ��ȸ
    void evaluatePurchaseSatisfactionDegree();    //���Ÿ�������
    void exit();
    /*
    void join(string name, string  registrationNumber, string id, string password); //ȸ������
    void login(string id, string password, string dummy1, string dummy2);            // �α���
    void logout(string dummy1, string dummy2, string dummy3, string dummy4);                                //�α׾ƿ�
    void withdraw(string dummy1, string dummy2, string dummy3, string dummy4);                         // ȸ��Ż��
    void saleRegistration(string productName, string productionCompany, string price, string amount);                     //�Ǹ��Ƿ����
    void inquiryRegistrationProduct(string dummy1, string dummy2, string dummy3, string dummy4);            //��ϻ�ǰ��ȸ
    void inquirySalesCompletedProduct(string dummy1, string dummy2, string dummy3, string dummy4);          //�ǸſϷ��ǰ��ȸ
    void inquirySalesStatistics(string dummy1, string dummy2, string dummy3, string dummy4);            //�Ǹ����
    void searchProduct(string productName, string dummy1, string dummy2, string dummy3);                     //��ǰ�˻�
    void purchaseProduct(string dummy1, string dummy2, string dummy3, string dummy4);                   //��ǰ����
    void inquiryProductPurchaseList(string dummy1, string dummy2, string dummy3, string dummy4);        //��ǰ ���� ���� ��ȸ
    void evaluatePurchaseSatisfactionDegree(string inputStr1, string dummy1, string dummy2, string dummy3);    //���Ÿ�������
    void exit(string dummy1, string dummy2, string dummy3, string dummy4);                              //����
    */
    Event doTask();             //�޴� �о�ͼ� �̺�Ʈ �߻���Ű��.
    void readInputValue();
    void program_exit();
    Event getNextEvent();       // ����ڷκ��� ���� �̺�Ʈ�� �Է¹���
    
    string getCurrentStateString();     // ���� ���¿� �ش��ϴ� ���ڿ��� �����ؼ� ��ȯ��


public:
    
    void run();               // state machine ���� 
};







