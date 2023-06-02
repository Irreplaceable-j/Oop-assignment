#include "StudentScore.h"
#include<iostream>

using namespace std;

Score::Score() {
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0;
}
Score::~Score() {

}
void Score::SetAvg(double avg) {
	m_Avg = avg;
}
void Score::SetNext(Score* pNext) {
	m_pNext = pNext;
}
void Score::SetPrev(Score* pPrev) {
	m_pPrev = pPrev;
}
double Score::GetAvr() {
	return m_Avg;
}
Score* Score::GetNext() {
	return m_pNext;
}
Score* Score::GetPrev() {
	return m_pPrev;
}


StudentScoreList::StudentScoreList() {
	m_pHead = nullptr;
	m_pTail = nullptr;
}
StudentScoreList::~StudentScoreList() {  // �� �ڿ������� �����Ҵ��� �޸� ����
	Score* work;
	while (m_pTail != nullptr) {
		work = m_pTail;
		m_pTail = m_pTail->GetPrev();
		delete work;
	}
}

void StudentScoreList::Insert(Score* pScore) {   // ���� ������������ ����
	Score* work;
	work = m_pHead;

	if (m_pHead == nullptr) {
		m_pHead = pScore;
		m_pTail = pScore;
		return;
	}
	while (work != nullptr) {
		if (m_pHead == nullptr) {
			m_pHead = pScore;
			m_pTail = pScore;
			break;
		}
		else if (m_pHead->GetAvr() > pScore->GetAvr()) {  // ���� ó���� ���� ��带 �����ؾ� �ϴ� ���
			pScore->SetPrev(m_pHead);
			m_pHead->SetPrev(pScore);
			m_pHead = pScore;
			break;
		}
		else if (work == m_pTail && work->GetAvr() < pScore->GetAvr()) {  // ������ ��尡 ���� ū ���� �� ��
			m_pTail->SetNext(pScore);
			pScore->SetPrev(m_pTail);
			m_pTail = pScore;
			break;
		}
		else if (work->GetAvr() < pScore->GetAvr()) {  // ���� ��庸�� ������ ����� ������ Ŭ �� ���� ���� �Ѿ
			work = work->GetNext();
			continue;
		}
		else if(work->GetAvr() >= pScore->GetAvr()){  // �߰��� ������ �����ϴ� ���
			pScore->SetNext(work);
			work = work->GetPrev();
			work->SetNext(pScore);
			pScore->SetPrev(work);
			work = pScore->GetNext();
			work->SetPrev(pScore);
			break;
		}
	}
}
void StudentScoreList::PrintList(bool isAscending) {
	Score* temp;
	
	if (isAscending) {
		temp = m_pHead;   // �տ��� ���� ������������ ���� ���
		while (temp != nullptr) {
			cout << temp->GetAvr() << " ";
			temp = temp->GetNext();
		}
	}
	else {
		temp = m_pTail;   // �ڿ��� ���� ������������ ���� ���
		while (temp != nullptr) {
			cout << temp->GetAvr() << " ";
			temp = temp->GetPrev();
		}
	}
}

