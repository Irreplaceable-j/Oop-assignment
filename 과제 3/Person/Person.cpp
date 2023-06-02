#define _CRT_SECURE_NO_WARNINGS
#include"Person.h"
#include<iostream>
#include<string.h>

using namespace std;

Person::Person() {
	age = 0;
	memset(name, 0, sizeof(name));
}
Person::~Person() {}

// Student 클래스 멤버 함수 정의
Student::Student() {
	memset(studentNum, 0, sizeof(studentNum));
	memset(major, 0, sizeof(major));
	schoolYear = 0;
}
Student::~Student() {}

int Student::getAge() {
	return age;
}
char* Student::getName() {
	return name;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setName(char* name) {
	strcpy(this->name, name);
}
char* Student::getStudentNum() {
	return studentNum;
}
char* Student::getMajor() {
	return major;
}
int Student::getSchoolYear() {
	return schoolYear;
}
void Student::setStudentNum(char* studentNum) {
	strcpy(this->studentNum, studentNum);
}
void Student::setMajor(char* major) {
	strcpy(this->major, major);
}
void Student::setSchoolYear(int year) {
	this->schoolYear = year;
}
void Student::Say() {   // schoolYear에 따라 학년을 소개하도록 switch문 사용
	cout << "My name is " << name <<"." << endl;
	cout << "I'm " << age << " years old and I'm a ";

	switch (schoolYear) {
	case 1:
		cout << "freshman." << endl;
		break;
	case 2:
		cout << "sophomore." << endl;
		break;
	case 3:
		cout << "junior." << endl;
		break;
	case 4:
		cout << "senior." << endl;
		break;
	}
	cout << "I'm majoring in " << major << "." << endl;
	cout << "My number is " << studentNum << "." << endl;
}

// Professor 클래스 멤버 함수 정의
Professor::Professor() {
	memset(professorNum, 0, sizeof(professorNum));
	memset(major, 0, sizeof(major));
}
Professor::~Professor() {}

char* Professor::getProfessorNum() {
	return professorNum;
}
char* Professor::getMajor() {
	return major;
}
void Professor::setNameAge(char* name, int age) {
	strcpy(this->name, name);
	this->age = age;
}
void Professor::setProfessorNum(char* professorNum) {
	strncpy(this->professorNum, professorNum, 10);
	this->professorNum[10] = '\0';
}
void Professor::setMajor(char* major) {
	strncpy(this->major, major, 31);
	this->major[31] = '\0';
}
void Professor::Say() {
	cout << "My name is " << name << "." << endl;
	cout << "I'm " << age << " years old." << endl;
	cout << "I'm majoring in " << major << "." << endl;
	cout << "My number is " << professorNum << "." << endl;
}