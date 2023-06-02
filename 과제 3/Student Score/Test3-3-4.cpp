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
		cout << "명령어 입력(input, print, exit): ";
		cin >> input;

		if (input == "input") {
			cout << "수학 점수: ";
			cin >> Math;
			cout << "영어 점수: ";
			cin >> English;
			cout << "과학 점수: ";
			cin >> science;
			Score* New = new Score;
			New->SetAvg((Math + English + science) / 3);
			list.Insert(New);
		}
		else if (input == "print") {
			cout << "(오름차순 인쇄: 1, 내림차순 인쇄: 0): ";
			cin >> a;
			if (a == 1) {
				T = true;
			}
			else if(a == 0) {
				T = false;
			}
			else {
				cout << "1과 0 둘 중 하나의 값을 입력하세요!";
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
			cout << "명령어가 잘못되었습니다. 다시 입력하세요!" << endl;
		}
	}

	return 0;
}