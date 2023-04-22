#pragma once    //중복 include 방지
#include <iostream>

using namespace std;

class A   //A클래스 정의
{
private:
	double value;

public:
	A(double v);  //생성자 함수 선언
	~A();          //소멸자 함수 선언
};
