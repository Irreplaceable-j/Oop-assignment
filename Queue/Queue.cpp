#include "Queue.h"
#include <iostream>

using namespace std;

// Queue class
Queue::Queue() {
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_Size = 0;
	m_NumElement = 0;
}
Queue::~Queue() {

}
void Queue::SetSize(int n) {
	m_Size = n;
}
bool Queue::IsEmpty() {
	if (m_pHead == nullptr && m_pTail == nullptr)
		return true;
	else
		return false;
}
bool Queue::IsFull() {
	int count = 0;
	Node* temp = m_pHead;
	while (temp != nullptr) {
		count++;
		temp = temp->GetNext();
	}

	return count == m_Size ? true : false;  //���׿����ڸ� �̿��Ͽ� ��ȯ�� ����
}
bool Queue::Push(Node* pNode) {
	if (IsFull())  // ť�� �� ������ ��� �� �̻�  push���� ����
		return false;

	if (IsEmpty()) {  // ť�� ������� ��� ó�� ��带 ������ ��
		m_pHead = pNode;
		m_pTail = pNode;
	}
	else {
		m_pTail->SetNext(pNode);
		m_pTail = pNode;
	}

	m_NumElement++;
	return true;
}
Node* Queue::Pop() {
	Node* temp = m_pHead;

	if (IsEmpty())  // ť�� ����־� pop�� ������ �� ���� ���
		return nullptr;

	if (m_pHead == m_pTail) {  // ������ ��带 Pop�� ��
		m_pHead = nullptr;
		m_pTail = nullptr;
		return temp;
	}
	
	m_pHead = m_pHead->GetNext();
	return temp;
}
void Queue::PrintQueue() {
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