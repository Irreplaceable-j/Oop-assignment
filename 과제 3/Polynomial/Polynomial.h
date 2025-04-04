#pragma once

class Term
{
private:
	int m_Coefficient;   // ���
	int m_Exponent;      // ����
	Term* m_pNext;

public:
	Term();
	~Term();

	void SetCoeff(int coeff);
	void SetExponent(int exponent);
	int GetCoeff();
	int GetExponent();
	void SetNext(Term* pNext);
	Term* GetNext();
};

class Polynomial
{
private:
	Term* m_pNext;

public:
	Polynomial();
	~Polynomial();

	void Insert(Term* pTerm);
	void PrintList();
	void Add(Polynomial& poly);
	void Sub(Polynomial& poly);
};
