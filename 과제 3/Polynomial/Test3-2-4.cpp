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

	cout << "첫번째 다항식 입력: ";
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

		if (pos == string::npos) {   // "x^"문자열이 없을 경우 find()함수는 string::npos를 반환함
			int coefficient = stoi(mor[i]);   // 문자열을 정수형으로 변환
			int exponent = 0;

			num[idx] = coefficient;
			idx++;
			num[idx] = exponent;
			idx++;

			continue;
		}

		string coe_str = mor[i].substr(0, pos);
		string exp_str = mor[i].substr(pos + 2);

		coeff = stoi(coe_str);   // 문자열을 int형으로 변환
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

		if (i == 0) {  // 처음 항을 생성할 때
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

	// ----------------------  두번째 다항식 입력 ----------
	j = 0;
	cout << "두번째 다항식 입력: ";
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

		if (pos == string::npos) {   // "x^"문자열이 없을 경우 find()함수는 string::npos를 반환함
			int coefficient = stoi(mor2[i]);   // 문자열을 정수형으로 변환
			int exponent = 0;

			num[idx] = coefficient;
			idx++;
			num[idx] = exponent;
			idx++;

			continue;
		}

		string coeff_str = mor2[i].substr(0, pos);
		string exp_str = mor2[i].substr(pos + 2);

		coeff = stoi(coeff_str);   // 문자열을 int형으로 변환
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
		if (i == 0) {  // 처음 항을 생성할 때
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
	
	first.Add(second);                    // 다항식 덧셈
	cout << "-----Add-----" << endl;
	
	/*
	first.Sub(second);                    // 다항식 뺄셈
	cout << "-----Sub-----" << endl;
	*/

	first.PrintList();



	return 0;
}
