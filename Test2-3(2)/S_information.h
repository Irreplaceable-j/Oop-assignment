#pragma once

class Student
{
private:
	char name[10];
	int age = 0;
	char class_name[100];

public:
	Student(char* name, int age, char* class_name);   //생성자로 객체가 생성될 떄 정보를 변수에 저장

	void print();
	char* REname();       //name값 반환
	char* REclass_name();  //class_name값 반환
};

class School
{
private:
	class Student* student_list[100];
	int size = 0;

public:
	~School();   //동적할당한 객체를 해제하기 위한 소멸자
	void addStudent(char* name, int age, char* class_name);
	void sort_by_name();      //이름순으로 정렬하기 위한 함수
	void print_all();
	void FindClass(char* name);
};
