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

	cout << "�л��� ������ �Է��ϼ���." << endl;
	cout << "�̸�: ";
	cin >> name;
	cout << "����: ";
	cin >> age;
	cout << "�г�: ";
	cin >> schoolYear;
	cin.ignore();
	cout << "����: ";
	cin.getline(major, 32);
	cout << "��ȣ: ";
	cin >> studentNum;

	Tama.setName(name);
	Tama.setAge(age);
	Tama.setSchoolYear(schoolYear);
	Tama.setMajor(major);
	Tama.setStudentNum(studentNum);

	for (int i = 0; i < 32; i++) {  // �迭 �ʱ�ȭ
		name[i] = '\0';
		major[i] = '\0';
	}

	cout << "�������� ������ �Է��ϼ���." << endl;
	cout << "�̸�: ";
	cin >> name;
	cout << "����: ";
	cin >> age;
	cin.ignore();
	cout << "����: ";
	cin.getline(major, 32);
	cout << "��ȣ: ";
	cin >> professorNum;

	James.setNameAge(name, age);
	James.setMajor(major);
	James.setProfessorNum(professorNum);

	cout << endl << "----------�л� �λ縻----------" << endl;
	Tama.Say();
	cout << endl << "----------������ �λ縻----------" << endl;
	James.Say();

	return 0;
}

