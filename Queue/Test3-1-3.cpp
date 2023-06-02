#include "Queue.h"
#include<iostream>

using namespace std;

int main()
{
	Node pNode_1;    // 노드 객체 생성
	Node pNode_2;   
	Node pNode_3;
	Node pNode_4;
	Node pNode_5;
	Node* temp;      //삭제된 데이터 값을 임시 저장

	Queue Data;    
	int a = 5;    

	Data.SetSize(a);               //size 설정
	cout << "Data 크기: 5" << endl;

	cout << "IsEmpty?" << endl;  // IsEmpty함수 테스트
	if (Data.IsEmpty()) {
		cout << "데이터가 비어있습니다." << endl;
	}
	else
		cout << "데이터가 존재합니다." << endl;

	pNode_1.SetData(10);      // 노드에 데이터 저장
	pNode_2.SetData(20);
	pNode_3.SetData(30);
	pNode_4.SetData(40);
	pNode_5.SetData(50);

	Data.Push(&pNode_3);             // 큐를 꽉 채우지 않고 일부만 저장
	cout << "pNode_3 저장" << endl;
	Data.Push(&pNode_5);
	cout << "pNode_5 저장" << endl;
	Data.Push(&pNode_2);
	cout << "pNode_2 저장" << endl;

	cout << "IsFull?" << endl;
	Data.PrintQueue();

	if (Data.IsFull()) {
		cout << "데이터가 꽉 차있습니다." << endl;
	}
	else
		cout << "데이터가 더 저장될 수 있습니다." << endl;

	Data.Push(&pNode_4);                  // 사이즈의 크기만큼 노드 연결
	cout << "pNode_4 저장" << endl;
	Data.Push(&pNode_1);
	cout << "pNode_1 저장" << endl;

	cout << "IsFull?" << endl;       
	Data.PrintQueue();
	if (Data.IsFull()) {
		cout << "데이터가 꽉 차있습니다." << endl;
	}
	else
		cout << "데이터가 더 저장될 수 있습니다." << endl;

	temp = Data.Pop();           // 큐방식으로 데이서 삭제 (FIFO)
	cout << temp->GetData() << "제거" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "제거" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "제거" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "제거" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "제거" << endl;

	cout << "IsEmpty?" << endl;    // 모든 노드를 삭제한 후 큐가 비어있는지 확인
	if (Data.IsEmpty()) {
		cout << "데이터가 비어있습니다." << endl;
	}
	else
		cout << "데이터가 존재합니다." << endl;

	return 0;
}