#include "Clock.h"
#include <iostream>
using namespace std;

Clock::Clock()  //생성자를 호출하며 멤버 변수를 0으로 초기화
{
	hour = 0;
	minute = 0;
	second = 0;
}
Clock::~Clock()  //소멸자를 호출하며 시간이 잘 변환되었는지 결과를 보여줌
{
	cout << hour << "시간 " << minute << "분 " << second << "초 입니다";
}

void Clock::increaseHour()   //시간을 증가시키는 함수
{
	hour++;
	if (hour == 24)        //hour가 증가하다가 24가 되었을 때 0으로 초기화함
		hour = 0;
}
void Clock::increaseMinute()  //분을 증가시키는 함수
{
	minute++;
	if (minute == 60)  //minute이 60이 되었을 때 값을 0으로 초기화 하고 hour를 1증가시키는 함수 호출
	{
		minute = 0;
		increaseHour();
	}
}
void Clock::increaseSecond()  //초를 증가시키는 함수
{
	second++;
	if (second == 60)   //second가 60이 되었을 때 0으로 초기화 하고 minute을 1증가시키는 함수를 호출
	{
		second = 0;
		increaseMinute();
	}
}

void Clock::setTime(int second)
{
	for (int i = 0; i < second; i++)  //반복문을 통해 초를 증가 시킴
		increaseSecond();

	setSecond(second % 60);
	second /= 60;
	setMinute(second % 60);
	second /= 60;
	setHour(second);
}

void Clock::setHour(int hour)  //this를 이용하여 매개변수의 저장된 값을 멤버 변수에 저장
{
	this->hour = hour % 24;     //25가 들어왔을 때 24로 나눈 나머지인 1을 저장
} 

void Clock::setMinute(int minute)
{
	this->minute = minute;
}

void Clock::setSecond(int second)
{
	this->second = second;
}