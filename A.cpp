#include "A.h"
#include <iostream>

using namespace std;

A::A(double v)  //class A의 생성자
{
	value = v;
	cout << "Class A is created with " << value << endl;
}

A::~A()  //class A의 소멸자
{
	cout << "Class A is destroyed with " << value;
}