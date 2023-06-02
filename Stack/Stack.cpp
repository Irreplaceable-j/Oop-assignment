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
	if (IsFull())  // 스택이 꽉 차있을 경우 더 이상  push하지 않음
		return false;

	if (IsEmpty()) {  // 스택이 비어있을 경우
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

	if (IsEmpty())  // 스택이 비어있어 pop을 수행할 수 없을 경우
		return nullptr;

	if (m_NumElement == 1) {  // 마지막 노드를 Pop할 때
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
void Node::SetNext(Node* pNext) {   // 다음 노드를 인자로 받아 노드를 연결함
	m_pNext = pNext;
}
int Node::GetData() {
	return m_Data;
}
Node* Node::GetNext() {
	return m_pNext;
}