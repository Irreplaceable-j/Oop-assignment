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
        this->name[0] = '\0'; // �� ���ڿ��� �ʱ�ȭ
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

bool Employee::isNameCorrect(char* name)    // ���޹��� ���ڰ��� ���� ���ڿ��� ������ true�� ��ȯ��
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
void Employee::change(char* name, int age, char* country, char* job)   // ���� ���� �������� this�����͸� �̿��� �ش� ����Լ��� ����
{
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->country, country);
	strcpy(this->job, job);
}
