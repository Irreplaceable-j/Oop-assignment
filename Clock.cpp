#include "Clock.h"
#include <iostream>
using namespace std;

Clock::Clock()  //�����ڸ� ȣ���ϸ� ��� ������ 0���� �ʱ�ȭ
{
	hour = 0;
	minute = 0;
	second = 0;
}
Clock::~Clock()  //�Ҹ��ڸ� ȣ���ϸ� �ð��� �� ��ȯ�Ǿ����� ����� ������
{
	cout << hour << "�ð� " << minute << "�� " << second << "�� �Դϴ�";
}

void Clock::increaseHour()   //�ð��� ������Ű�� �Լ�
{
	hour++;
	if (hour == 24)        //hour�� �����ϴٰ� 24�� �Ǿ��� �� 0���� �ʱ�ȭ��
		hour = 0;
}
void Clock::increaseMinute()  //���� ������Ű�� �Լ�
{
	minute++;
	if (minute == 60)  //minute�� 60�� �Ǿ��� �� ���� 0���� �ʱ�ȭ �ϰ� hour�� 1������Ű�� �Լ� ȣ��
	{
		minute = 0;
		increaseHour();
	}
}
void Clock::increaseSecond()  //�ʸ� ������Ű�� �Լ�
{
	second++;
	if (second == 60)   //second�� 60�� �Ǿ��� �� 0���� �ʱ�ȭ �ϰ� minute�� 1������Ű�� �Լ��� ȣ��
	{
		second = 0;
		increaseMinute();
	}
}

void Clock::setTime(int second)
{
	for (int i = 0; i < second; i++)  //�ݺ����� ���� �ʸ� ���� ��Ŵ
		increaseSecond();

	setSecond(second % 60);
	second /= 60;
	setMinute(second % 60);
	second /= 60;
	setHour(second);
}

void Clock::setHour(int hour)  //this�� �̿��Ͽ� �Ű������� ����� ���� ��� ������ ����
{
	this->hour = hour % 24;     //25�� ������ �� 24�� ���� �������� 1�� ����
} 

void Clock::setMinute(int minute)
{
	this->minute = minute;
}

void Clock::setSecond(int second)
{
	this->second = second;
}