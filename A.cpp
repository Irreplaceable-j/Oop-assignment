#include "A.h"
#include <iostream>

using namespace std;

A::A(double v)  //class A�� ������
{
	value = v;
	cout << "Class A is created with " << value << endl;
}

A::~A()  //class A�� �Ҹ���
{
	cout << "Class A is destroyed with " << value;
}