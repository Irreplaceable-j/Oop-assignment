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
School::~School()   //�����Ҵ�� ��ü�� �޸� ����
{
    for (int i = 0; i < size; i++)
        delete[] student_list[i];
}
void School::addStudent(char* name, int age, char* class_name) 
{
    if (size >= 100) 
    {
        return;   // �迭 ũ�⸦ �ʰ��� ��� �߰����� �ʰ� ��ȯ
    }

    student_list[size] = new Student(name, age, class_name); // Student ��ü ����
    size++; // ũ�� ����
}
void School::sort_by_name()
{
    Student* temp;      //��ü�� ����� ������ �̸������� �����ϱ� ���� �ӽ� Ŭ���� ������

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(student_list[j]->REname(), student_list[j + 1]->REname()) > 0)  //�̸��� �� ������ �ƽ�Ű �ڵ尪�� ���Ͽ� 1-�� 1�� ��ȯ
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
        if (strcmp(student_list[i]->REclass_name(), class_name) == 0)    //�Է��� ���̸��� ���� �� �̸��� ������ �л��� ������ ���
        {
            student_list[i]->print();
            count++;
        }
    }
    cout << "Number of classmates: " << count << endl << endl;   //�ش��ϴ� ���� �������� ���� �����
}
