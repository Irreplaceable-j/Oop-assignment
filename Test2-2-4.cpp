#include "Clock.h"
#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	cin >> num;

	Clock clock;    //Clock Ŭ������ ��ü clock�� ����
	clock.setTime(num);  //Ŭ������ setTime�Լ� ȣ���ϰ� num���� ���ڷ� ������
	
	cout << num << "�ʴ� ";

	return 0;
}