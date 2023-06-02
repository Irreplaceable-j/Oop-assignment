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

	return count == m_Size ? true : false;  //삼항연산자를 이용하여 반환값 결정
}
bool Queue::Push(Node* pNode) {
	if (IsFull())  // 큐가 꽉 차있을 경우 더 이상  push하지 않음
		return false;

	if (IsEmpty()) {  // 큐가 비어있을 경우 처음 노드를 삽입할 때
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

	if (IsEmpty())  // 큐가 비어있어 pop을 수행할 수 없을 경우
		return nullptr;

	if (m_pHead == m_pTail) {  // 마지막 노드를 Pop할 때
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
void Node::SetNext(Node* pNext) {   // 다음 노드를 인자로 받아 노드를 연결함
	m_pNext = pNext;
}
int Node::GetData() {
	return m_Data;
}
Node* Node::GetNext() {
	return m_pNext;
}