#include "Queue.h"
#include<iostream>

using namespace std;

int main()
{
	Node pNode_1;    // ��� ��ü ����
	Node pNode_2;   
	Node pNode_3;
	Node pNode_4;
	Node pNode_5;
	Node* temp;      //������ ������ ���� �ӽ� ����

	Queue Data;    
	int a = 5;    

	Data.SetSize(a);               //size ����
	cout << "Data ũ��: 5" << endl;

	cout << "IsEmpty?" << endl;  // IsEmpty�Լ� �׽�Ʈ
	if (Data.IsEmpty()) {
		cout << "�����Ͱ� ����ֽ��ϴ�." << endl;
	}
	else
		cout << "�����Ͱ� �����մϴ�." << endl;

	pNode_1.SetData(10);      // ��忡 ������ ����
	pNode_2.SetData(20);
	pNode_3.SetData(30);
	pNode_4.SetData(40);
	pNode_5.SetData(50);

	Data.Push(&pNode_3);             // ť�� �� ä���� �ʰ� �Ϻθ� ����
	cout << "pNode_3 ����" << endl;
	Data.Push(&pNode_5);
	cout << "pNode_5 ����" << endl;
	Data.Push(&pNode_2);
	cout << "pNode_2 ����" << endl;

	cout << "IsFull?" << endl;
	Data.PrintQueue();

	if (Data.IsFull()) {
		cout << "�����Ͱ� �� ���ֽ��ϴ�." << endl;
	}
	else
		cout << "�����Ͱ� �� ����� �� �ֽ��ϴ�." << endl;

	Data.Push(&pNode_4);                  // �������� ũ�⸸ŭ ��� ����
	cout << "pNode_4 ����" << endl;
	Data.Push(&pNode_1);
	cout << "pNode_1 ����" << endl;

	cout << "IsFull?" << endl;       
	Data.PrintQueue();
	if (Data.IsFull()) {
		cout << "�����Ͱ� �� ���ֽ��ϴ�." << endl;
	}
	else
		cout << "�����Ͱ� �� ����� �� �ֽ��ϴ�." << endl;

	temp = Data.Pop();           // ť������� ���̼� ���� (FIFO)
	cout << temp->GetData() << "����" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "����" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "����" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "����" << endl;
	temp = Data.Pop();
	cout << temp->GetData() << "����" << endl;

	cout << "IsEmpty?" << endl;    // ��� ��带 ������ �� ť�� ����ִ��� Ȯ��
	if (Data.IsEmpty()) {
		cout << "�����Ͱ� ����ֽ��ϴ�." << endl;
	}
	else
		cout << "�����Ͱ� �����մϴ�." << endl;

	return 0;
}