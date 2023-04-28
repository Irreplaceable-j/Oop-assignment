#pragma once

class Student
{
private:
	char name[10];
	int age = 0;
	char class_name[100];

public:
	Student(char* name, int age, char* class_name);   //�����ڷ� ��ü�� ������ �� ������ ������ ����

	void print();
	char* REname();       //name�� ��ȯ
	char* REclass_name();  //class_name�� ��ȯ
};

class School
{
private:
	class Student* student_list[100];
	int size = 0;

public:
	~School();   //�����Ҵ��� ��ü�� �����ϱ� ���� �Ҹ���
	void addStudent(char* name, int age, char* class_name);
	void sort_by_name();      //�̸������� �����ϱ� ���� �Լ�
	void print_all();
	void FindClass(char* name);
};
