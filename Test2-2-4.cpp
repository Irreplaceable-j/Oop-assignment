#include "Clock.h"
#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	cin >> num;

	Clock clock;    //Clock 클래스의 객체 clock을 선언
	clock.setTime(num);  //클래스의 setTime함수 호출하고 num값을 인자로 전달함
	
	cout << num << "초는 ";

	return 0;
}