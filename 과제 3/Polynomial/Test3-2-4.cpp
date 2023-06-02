#define _CRT_SECURE_NO_WARNINGS
#include"Polynomial.h"
#include<iostream>
#include<string>

using namespace std;



int main()
{
	int num[100];
	int j = 0;
	
	string mor[100];
	string mor2[100];

	char str[256];
	char* token;

	cout << "ù��° ���׽� �Է�: ";
	cin >> str;

	token = strtok(str, "+-");

	while (token != NULL) {
		mor[j] = token;
		j++;
		token = strtok(NULL, "+-");
	}

	int idx = 0;
	int coeff, expon;

	for (int i = 0; i < j; i++) {

		if (mor[i][0] == 'x') {
			coeff = 1;
			string exp_str = mor[i].substr(2);
			expon = stoi(exp_str);

			num[idx] = coeff;
			idx++;
			num[idx] = expon;
			idx++;

			continue;
		}
		size_t pos = mor[i].find("x^");

		if (pos == string::npos) {   // "x^"���ڿ��� ���� ��� find()�Լ��� string::npos�� ��ȯ��
			int coefficient = stoi(mor[i]);   // ���ڿ��� ���������� ��ȯ
			int exponent = 0;

			num[idx] = coefficient;
			idx++;
			num[idx] = exponent;
			idx++;

			continue;
		}

		string coe_str = mor[i].substr(0, pos);
		string exp_str = mor[i].substr(pos + 2);

		coeff = stoi(coe_str);   // ���ڿ��� int������ ��ȯ
		expon = stoi(exp_str);

		num[idx] = coeff;
		idx++;
		num[idx] = expon;
		idx++;
	}

	Term* Newt;
	Term* head = nullptr;
	Term* work = nullptr;

	for (int i = 0; i < 2 * j; i++) {

		if (i == 0) {  // ó�� ���� ������ ��
			Newt = new Term;
			head = Newt;
			work = Newt;
			work->SetCoeff(num[i]);
			i++;
			work->SetExponent(num[i]);
			continue;
		}

		Newt = new Term;
		work->SetNext(Newt);
		work = Newt;

		work->SetCoeff(num[i]);
		i++;
		work->SetExponent(num[i]);
	}

	Polynomial first;
	first.Insert(head);

	// ----------------------  �ι�° ���׽� �Է� ----------
	j = 0;
	cout << "�ι�° ���׽� �Է�: ";
	cin >> str;
	token = strtok(str, "+-");

	while (token != NULL) {
		mor2[j] = token;
		j++;
		token = strtok(NULL, "+-");
	}

	idx = 0;

	for (int i = 0; i < j; i++) {

		if (mor2[i][0] == 'x') {
			coeff = 1;
			string exp_str = mor2[i].substr(2);
			expon = stoi(exp_str);

			num[idx] = coeff;
			idx++;
			num[idx] = expon;
			idx++;

			continue;
		}
		size_t pos = mor2[i].find("x^");

		if (pos == string::npos) {   // "x^"���ڿ��� ���� ��� find()�Լ��� string::npos�� ��ȯ��
			int coefficient = stoi(mor2[i]);   // ���ڿ��� ���������� ��ȯ
			int exponent = 0;

			num[idx] = coefficient;
			idx++;
			num[idx] = exponent;
			idx++;

			continue;
		}

		string coeff_str = mor2[i].substr(0, pos);
		string exp_str = mor2[i].substr(pos + 2);

		coeff = stoi(coeff_str);   // ���ڿ��� int������ ��ȯ
		expon = stoi(exp_str);

		num[idx] = coeff;
		idx++;
		num[idx] = expon;
		idx++;
	}

	Term* Newt2;
	head = nullptr;
	work = nullptr;

	for (int i = 0; i < 2 * j; i++) {
		if (i == 0) {  // ó�� ���� ������ ��
			Newt2 = new Term;
			head = Newt2;
			work = Newt2;
			work->SetCoeff(num[i]);
			i++;
			work->SetExponent(num[i]);
			continue;
		}

		Newt2 = new Term;
		work->SetNext(Newt2);
		work = Newt2;

		work->SetCoeff(num[i]);
		i++;
		work->SetExponent(num[i]);
	}

	Polynomial second;
	second.Insert(head);

	first.PrintList();
	second.PrintList();
	
	first.Add(second);                    // ���׽� ����
	cout << "-----Add-----" << endl;
	
	/*
	first.Sub(second);                    // ���׽� ����
	cout << "-----Sub-----" << endl;
	*/

	first.PrintList();



	return 0;
}
