#include "StudentScore.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	double Math;
	double English;
	double science;
	bool T;
	int a;
	string input;
	StudentScoreList list;

	while(true) {
		cout << "��ɾ� �Է�(input, print, exit): ";
		cin >> input;

		if (input == "input") {
			cout << "���� ����: ";
			cin >> Math;
			cout << "���� ����: ";
			cin >> English;
			cout << "���� ����: ";
			cin >> science;
			Score* New = new Score;
			New->SetAvg((Math + English + science) / 3);
			list.Insert(New);
		}
		else if (input == "print") {
			cout << "(�������� �μ�: 1, �������� �μ�: 0): ";
			cin >> a;
			if (a == 1) {
				T = true;
			}
			else if(a == 0) {
				T = false;
			}
			else {
				cout << "1�� 0 �� �� �ϳ��� ���� �Է��ϼ���!";
				cout << endl;
				continue;
			}
			list.PrintList(T);
			cout << endl;
		}
		else if (input == "exit") {
			break;
		}
		else {
			cout << "��ɾ �߸��Ǿ����ϴ�. �ٽ� �Է��ϼ���!" << endl;
		}
	}

	return 0;
}