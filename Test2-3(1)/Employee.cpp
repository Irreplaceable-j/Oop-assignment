#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include <iostream>
#include <string.h>

using namespace std;

Employee::Employee(char* name, int age, char* country, char* job)  
{
    if (name != NULL) {
        strcpy(this->name, name);
    }
    else {
        this->name[0] = '\0'; // 빈 문자열로 초기화
    }
    this->age = age;
    if (country != NULL) {
        strcpy(this->country, country);
    }
    else {
        this->country[0] = '\0'; 
    }
    if (job != NULL) {
        strcpy(this->job, job);
    }
    else {
        this->job[0] = '\0'; 
    }
}

bool Employee::isNameCorrect(char* name)    // 전달받은 인자값과 같은 문자열이 있으면 true를 반환함
{
	if (strcmp(this->name, name) == 0)
		return true;
	else
		return false;
}
void Employee::print()    //
{

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Country: " << country << endl;
	cout << "Job: " << job << endl;
	cout << "----------" << endl;
}
void Employee::change(char* name, int age, char* country, char* job)   // 전달 받은 정보들을 this포인터를 이용해 해당 멤버함수에 저장
{
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->country, country);
	strcpy(this->job, job);
}
