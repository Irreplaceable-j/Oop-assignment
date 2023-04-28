#define _CRT_SECURE_NO_WARNINGS
#include "S_information.h"
#include <iostream>
#include <string.h>

using namespace std;

Student::Student(char* name, int age, char* class_name)
{
    strcpy(this->name, name);
    this->age = age;
    strcpy(this->class_name, class_name);
}
void Student::print()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Class_name: " << class_name << endl;
    cout << "----------" << endl << endl;
}
char* Student::REname()
{
    return name;
}

char* Student::REclass_name()
{
    return class_name;
}

 // school class
School::~School()   //동적할당된 객체의 메모리 해제
{
    for (int i = 0; i < size; i++)
        delete[] student_list[i];
}
void School::addStudent(char* name, int age, char* class_name) 
{
    if (size >= 100) 
    {
        return;   // 배열 크기를 초과한 경우 추가하지 않고 반환
    }

    student_list[size] = new Student(name, age, class_name); // Student 객체 생성
    size++; // 크기 증가
}
void School::sort_by_name()
{
    Student* temp;      //객체에 저장된 정보를 이름순으로 정렬하기 위한 임시 클래스 포인터

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(student_list[j]->REname(), student_list[j + 1]->REname()) > 0)  //이름의 각 문자의 아스키 코드값을 비교하여 1-과 1을 반환
            {
                temp = student_list[j];
                student_list[j] = student_list[j + 1];
                student_list[j + 1] = temp;
            }
        }
    }
}
void School::print_all()
{
    cout << endl << "=====print_all=====" << endl;
    for (int i = 0; i < size; i++)
    {
        student_list[i]->print();
    }
}
void School::FindClass(char* class_name)
{
    int count = 0;

    cout << endl << "=====print_class=====" << endl;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(student_list[i]->REclass_name(), class_name) == 0)    //입력한 반이름과 같은 반 이름을 가지는 학생의 정보를 출력
        {
            student_list[i]->print();
            count++;
        }
    }
    cout << "Number of classmates: " << count << endl << endl;   //해당하는 반의 구성원의 수를 출력함
}
