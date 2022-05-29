#include <iostream>
#include <string>
#define NUMBER_OF_TABLE_ENTRIES 100     // event-action table의 현재 entry 갯수
#define MAX_NUMBER_OF_ACTIONS   3       // transition 시 실행되는 최대 action 갯수

using namespace std;
//파일 입출력 부분
#include<iostream>
#include<fstream>

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// State 열거형 정의
typedef enum {
    STATE_LOGOUT,
    STATE_LOGIN,
    STATE_INQUIRY_PRODUCT,
    STATE_COMPLETION_PURCHASE,
    STATE_INQUIRY_PURCHASE_LIST,
    STATE_END
} State;


// Event 열거형 정의
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

// 음료 자동판매기를 위한 StateMachine 클래스 정의
class StateMachine
{
private:
    State curState;     // 현재 상태
    //string inputValue1, inputValue2, inputValue3, inputValue4;
    // 파일 입출력 변수선언
    ifstream fin;
    ofstream fout;

    // event-action table structure 정의
    typedef struct {
        State curState;             // 현재 상태
        Event event;                // 사용자로부터 발생된 이벤트
        int number_of_actions;                                      // 해당 transition에 실행되는 action 함수의 갯수
        void (StateMachine::* action[MAX_NUMBER_OF_ACTIONS])();   // action 함수 포인터의 배열
        // string action_parameter[MAX_NUMBER_OF_ACTIONS];                 // action 함수의 매개변수 배열
        State nextState;            // transition 후에 변경될 다음 상태
    } EventActionTable;

    // vending machine에서 사용할 event-action table 초기화
    EventActionTable table[NUMBER_OF_TABLE_ENTRIES]{
        {STATE_LOGOUT,	        EVENT_JOIN,	           1,  {&StateMachine::join},	         STATE_LOGOUT},
        {STATE_LOGOUT,	        EVENT_LOGIN,	       1,  {&StateMachine::login},	         STATE_LOGIN},
        {STATE_LOGIN,	        EVENT_SALE_REGISTRATION,    1,  {&StateMachine::saleRegistration},	         STATE_LOGIN},
        {STATE_LOGIN,EVENT_INQUIRY_REGISTRATION_PRODUCT,    1,  {&StateMachine::inquiryRegistrationProduct}, STATE_LOGIN},
        {STATE_LOGIN,EVENT_INQUIRY_SALES_COMPLETED_PRODUCT,    1,  {&StateMachine::inquirySalesCompletedProduct},  STATE_LOGIN},
        {STATE_LOGIN,EVENT_INQUIRY_SALES_STATICS,    1,  {&StateMachine::inquirySalesStatistics},  STATE_LOGIN},
        
        //상품 검색 및 구매
        {STATE_LOGIN,	        EVENT_SEARCHE_PRODUCT,    1,  {&StateMachine::searchProduct},	         STATE_INQUIRY_PRODUCT},
        {STATE_INQUIRY_PRODUCT,	        EVENT_PURCHASE_PRODUCT,    1,  {&StateMachine::purchaseProduct},	         STATE_COMPLETION_PURCHASE},
        {STATE_COMPLETION_PURCHASE,	        EVENT_INQUIRY_PURCHASE_LIST,    1,  {&StateMachine::inquiryProductPurchaseList},	         STATE_INQUIRY_PURCHASE_LIST},
        {STATE_INQUIRY_PURCHASE_LIST,	        EVENT_EVALUATE_PURCHASE_SATISFACTION_DEGREE,    1,  {&StateMachine::evaluatePurchaseSatisfactionDegree},	         STATE_LOGIN},
        {STATE_LOGIN,	        EVENT_INQUIRY_PURCHASE_LIST,    1,  {&StateMachine::inquiryProductPurchaseList},	         STATE_INQUIRY_PURCHASE_LIST},

        //로그아웃이벤트
        {STATE_LOGIN,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        {STATE_INQUIRY_PRODUCT,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        {STATE_COMPLETION_PURCHASE,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        { STATE_INQUIRY_PURCHASE_LIST,	        EVENT_LOGOUT,	           1,  {&StateMachine::logout},	         STATE_LOGOUT},
        //회원탈퇴이벤트
        {STATE_LOGIN,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        {STATE_INQUIRY_PRODUCT,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        {STATE_COMPLETION_PURCHASE,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        {STATE_INQUIRY_PURCHASE_LIST,	        EVENT_WITHDRAW,	           1,  {&StateMachine::withdraw},	         STATE_LOGOUT},
        //종료이벤트
        {STATE_LOGOUT,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_LOGIN,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_INQUIRY_PRODUCT,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_COMPLETION_PURCHASE,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
        {STATE_INQUIRY_PURCHASE_LIST,	        EVENT_QUIT,             1 ,       {&StateMachine::exit},	        STATE_END},
       
    };

    //이벤트
    void join(); //회원가입
    void login();            // 로그인
    void logout();                                //로그아웃
    void withdraw();                         // 회원탈퇴
    void saleRegistration();                     //판매의류등록
    void inquiryRegistrationProduct();            //등록상품조회
    void inquirySalesCompletedProduct();          //판매완료상품조회
    void inquirySalesStatistics();            //판매통계
    void searchProduct();                     //상품검색
    void purchaseProduct();                   //상품구매
    void inquiryProductPurchaseList();        //상품 구매 내역 조회
    void evaluatePurchaseSatisfactionDegree();    //구매만족도평가
    void exit();
    /*
    void join(string name, string  registrationNumber, string id, string password); //회원가입
    void login(string id, string password, string dummy1, string dummy2);            // 로그인
    void logout(string dummy1, string dummy2, string dummy3, string dummy4);                                //로그아웃
    void withdraw(string dummy1, string dummy2, string dummy3, string dummy4);                         // 회원탈퇴
    void saleRegistration(string productName, string productionCompany, string price, string amount);                     //판매의류등록
    void inquiryRegistrationProduct(string dummy1, string dummy2, string dummy3, string dummy4);            //등록상품조회
    void inquirySalesCompletedProduct(string dummy1, string dummy2, string dummy3, string dummy4);          //판매완료상품조회
    void inquirySalesStatistics(string dummy1, string dummy2, string dummy3, string dummy4);            //판매통계
    void searchProduct(string productName, string dummy1, string dummy2, string dummy3);                     //상품검색
    void purchaseProduct(string dummy1, string dummy2, string dummy3, string dummy4);                   //상품구매
    void inquiryProductPurchaseList(string dummy1, string dummy2, string dummy3, string dummy4);        //상품 구매 내역 조회
    void evaluatePurchaseSatisfactionDegree(string inputStr1, string dummy1, string dummy2, string dummy3);    //구매만족도평가
    void exit(string dummy1, string dummy2, string dummy3, string dummy4);                              //종료
    */
    Event doTask();             //메뉴 읽어와서 이벤트 발생시키기.
    void readInputValue();
    void program_exit();
    Event getNextEvent();       // 사용자로부터 다음 이벤트를 입력받음
    
    string getCurrentStateString();     // 현재 상태에 해당하는 문자열을 생성해서 반환함


public:
    
    void run();               // state machine 실행 
};







