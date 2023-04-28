#pragma once

class Employee
{
private:
	char name[10];
	int age = 0;
	char country[100];
	char job[100];

public:
	Employee(char* name, int age, char* country, char* job);
	bool isNameCorrect(char* name);
	void print();
	void change(char* name, int age, char* country, char* job);
};
