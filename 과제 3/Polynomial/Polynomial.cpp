#include"Polynomial.h"
#include<iostream>

using namespace std;

    // Term class
Term::Term() {
	m_pNext = nullptr;
}
Term::~Term() {

}
void Term::SetCoeff(int coeff) {
	m_Coefficient = coeff;
}
void Term::SetExponent(int exponent) {
	m_Exponent = exponent;
}
int Term::GetCoeff() {
	return m_Coefficient;
}
int Term::GetExponent() {
	return m_Exponent;
}
void Term::SetNext(Term* pNext) {
	m_pNext = pNext;
}
Term* Term::GetNext() {
	return m_pNext;
}

    // Polynomial class
Polynomial::Polynomial() {
	m_pNext = nullptr;
}
Polynomial::~Polynomial() { }

void Polynomial::Insert(Term* pTerm) {
	if (m_pNext == nullptr) {
		m_pNext = pTerm;
		return;
	}

	Term* work = m_pNext;
	Term* wnext = work->GetNext();
		
	if (wnext == nullptr) {  // 항이 하나만 있을 때
		if (pTerm->GetExponent() > work->GetExponent()) {
			pTerm->SetNext(m_pNext);
			m_pNext = pTerm;
		}
		if (pTerm->GetExponent() < work->GetExponent()) {
			work->SetNext(pTerm);
			
		}
	}
	while (wnext != nullptr) {
		if (pTerm->GetExponent() > work->GetExponent()) {
			pTerm->SetNext(m_pNext);
			m_pNext = pTerm;
			return;
		}
		else if (pTerm->GetExponent() > wnext->GetExponent()) {
			pTerm->SetNext(wnext);
			work->SetNext(pTerm);
			return;
		}
		else if (pTerm->GetExponent() < wnext->GetExponent()) {
			work = work->GetNext();
			wnext = wnext->GetNext();
		}
	}
}
void Polynomial::PrintList() {
	Term* work = m_pNext;

	while (work != nullptr) {

		if (work == m_pNext) {  // 첫번째 항일 경우
			int coe = work->GetCoeff();
			int exp = work->GetExponent();
			if (coe == 0) {  // 계수가 0이면 출력하지 않음
				work = work->GetNext();
				continue;
			}
			if (coe == 1 && exp != 0) {
				cout << "x^" << exp;
				work = work->GetNext();
				continue;
			}
			if (coe == -1 && exp != 0) {
				cout << " - x^" << exp;
				work = work->GetNext();
				continue;
			}
			if (exp == 0) {
				cout << coe;
				work = work->GetNext();
				continue;
			}
			if (coe < 0) {
				cout << " - " << -coe << "x^" << exp;
				work = work->GetNext();
				continue;
			}
			cout << coe << "x^" << exp;
			work = work->GetNext();
			continue;
		}
		int coe = work->GetCoeff();
		int exp = work->GetExponent();

		if (coe == 0) {  // 계수가 0이면 출력하지 않음
			work = work->GetNext();
			continue;
		}
		if (coe == 1 && exp != 0) {
			cout << " + " << "x^" << exp;
			work = work->GetNext();
			continue;
		}
		if (coe == -1 && exp != 0) {
			cout << " - x^" << exp;
			work = work->GetNext();
			continue;
		}
		if (exp == 0) {
			cout << " + " << coe ;
			work = work->GetNext();
			continue;
		}
		if (coe < 0) {
			cout << " - " << -coe << "x^" << exp;
			work = work->GetNext();
			continue;
		}
		cout << " + " << coe << "x^" << exp;

		work = work->GetNext();
	}
}
void Polynomial::Add(Polynomial& poly) {

	Term* first = m_pNext;
	Term* second = poly.m_pNext;
	
	while (first != nullptr && second != nullptr) {
		if (first->GetExponent() == second->GetExponent()) {  // 지수가 같으면 계수를 더해서 저장
			first->SetCoeff(first->GetCoeff() + second->GetCoeff());
			first = first->GetNext();
			second = second->GetNext();
		}
		else {
			if (first->GetExponent() < second->GetExponent()) {
				Insert(second);   // 계수가 안맞기 때문에 그냥 더하며 노드를 삽입함
				second = second->GetNext();
			}
			else if (first->GetExponent() > second->GetExponent()) {
				first = first->GetNext();
			}
		}
	}
	if (second != nullptr) {  // 아직 항이 남아있을 때
		while (second != nullptr) {
		Insert(second);
		second = second->GetNext();
		}
	}
}
void Polynomial::Sub(Polynomial& poly) {
	Term* first = m_pNext;
	Term* second = poly.m_pNext;

	while (first != nullptr && second != nullptr) {
		if (first->GetExponent() == second->GetExponent()) {
			first->SetCoeff(first->GetCoeff() - second->GetCoeff());
			first = first->GetNext();
			second = second->GetNext();
		}
		else {
			if (first->GetExponent() < second->GetExponent()) {
				second->SetCoeff(-second->GetCoeff());   //  노드를 추가할 때 -를 붙여서 추가함
				Insert(second);
				second = second->GetNext();
			}
			else if (first->GetExponent() > second->GetExponent()) {
				first = first->GetNext();
			}
		}
	}
	if (second != nullptr) {  // 아직 항이 남아있을 때
		while (second != nullptr) {
			second->SetCoeff(-second->GetCoeff());
			Insert(second);
			second = second->GetNext();
		}
	}
}