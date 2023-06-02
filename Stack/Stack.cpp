#include"Stack.h"
#include <iostream>

using namespace std;

// Stack class
Stack::Stack() {
	m_pHead = nullptr;
	m_Size = 0;
	m_NumElement = 0;
}
Stack::~Stack() {

}
void Stack::SetSize(int n) {
	m_Size = n;
}
bool Stack::IsEmpty() {
	if (m_NumElement == 0)
		return true;
	else
		return false;
}
bool Stack::IsFull() {
	if (m_NumElement == m_Size)
		return true;
	else
		return false;
}
bool Stack::Push(Node* pNode) {
	if (IsFull())  // ������ �� ������ ��� �� �̻�  push���� ����
		return false;

	if (IsEmpty()) {  // ������ ������� ���
		m_pHead = pNode;
		m_NumElement++;

		return true;
	}
	pNode->SetNext(m_pHead);
	m_pHead = pNode;
	m_NumElement++;

	return true;
}
Node* Stack::Pop() {
	Node* temp = m_pHead;

	if (IsEmpty())  // ������ ����־� pop�� ������ �� ���� ���
		return nullptr;

	if (m_NumElement == 1) {  // ������ ��带 Pop�� ��
		m_NumElement--;
		m_pHead = nullptr;
		return temp;
	}
	m_NumElement--;
	m_pHead = m_pHead->GetNext();
	return temp;
}
void Stack::PrintStack() {
	Node* temp = m_pHead;
	while (temp != nullptr) {
		cout << temp->GetData() << endl;
		temp = temp->GetNext();
	}
}

// Node class
Node::Node() {
	Node* m_pNext = nullptr;
}
Node::~Node() {

}
void Node::SetData(int n) {
	m_Data = n;
}
void Node::SetNext(Node* pNext) {   // ���� ��带 ���ڷ� �޾� ��带 ������
	m_pNext = pNext;
}
int Node::GetData() {
	return m_Data;
}
Node* Node::GetNext() {
	return m_pNext;
}