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
StudentScoreList::~StudentScoreList() {  // 맨 뒤에서부터 동적할당한 메모리 해제
	Score* work;
	while (m_pTail != nullptr) {
		work = m_pTail;
		m_pTail = m_pTail->GetPrev();
		delete work;
	}
}

void StudentScoreList::Insert(Score* pScore) {   // 점수 오름차순으로 정렬
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
		else if (m_pHead->GetAvr() > pScore->GetAvr()) {  // 가장 처음에 점수 노드를 삽입해야 하는 경우
			pScore->SetPrev(m_pHead);
			m_pHead->SetPrev(pScore);
			m_pHead = pScore;
			break;
		}
		else if (work == m_pTail && work->GetAvr() < pScore->GetAvr()) {  // 삽입할 노드가 가장 큰 점수 일 때
			m_pTail->SetNext(pScore);
			pScore->SetPrev(m_pTail);
			m_pTail = pScore;
			break;
		}
		else if (work->GetAvr() < pScore->GetAvr()) {  // 현재 노드보다 삽입할 노드의 점수가 클 때 다음 노드로 넘어감
			work = work->GetNext();
			continue;
		}
		else if(work->GetAvr() >= pScore->GetAvr()){  // 중간에 점수를 삽입하는 경우
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
		temp = m_pHead;   // 앞에서 부터 오름차순으로 점수 출력
		while (temp != nullptr) {
			cout << temp->GetAvr() << " ";
			temp = temp->GetNext();
		}
	}
	else {
		temp = m_pTail;   // 뒤에서 부터 내림차순으로 점수 출력
		while (temp != nullptr) {
			cout << temp->GetAvr() << " ";
			temp = temp->GetPrev();
		}
	}
}

