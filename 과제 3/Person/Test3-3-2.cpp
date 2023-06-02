#include"Person.h"
#include<iostream>

using namespace std;

int main()
{
	int age;
	char name[32];
	char studentNum[11];
	char major[32];
	int schoolYear;
	char professorNum[11];

	Student Tama;
	Professor James;

	cout << "학생의 정보를 입력하세요." << endl;
	cout << "이름: ";
	cin >> name;
	cout << "나이: ";
	cin >> age;
	cout << "학년: ";
	cin >> schoolYear;
	cin.ignore();
	cout << "전공: ";
	cin.getline(major, 32);
	cout << "번호: ";
	cin >> studentNum;

	Tama.setName(name);
	Tama.setAge(age);
	Tama.setSchoolYear(schoolYear);
	Tama.setMajor(major);
	Tama.setStudentNum(studentNum);

	for (int i = 0; i < 32; i++) {  // 배열 초기화
		name[i] = '\0';
		major[i] = '\0';
	}

	cout << "교수님의 정보를 입력하세요." << endl;
	cout << "이름: ";
	cin >> name;
	cout << "나이: ";
	cin >> age;
	cin.ignore();
	cout << "전공: ";
	cin.getline(major, 32);
	cout << "번호: ";
	cin >> professorNum;

	James.setNameAge(name, age);
	James.setMajor(major);
	James.setProfessorNum(professorNum);

	cout << endl << "----------학생 인사말----------" << endl;
	Tama.Say();
	cout << endl << "----------교수님 인사말----------" << endl;
	James.Say();

	return 0;
}

