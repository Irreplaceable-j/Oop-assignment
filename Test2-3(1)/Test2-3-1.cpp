#include "Employee.h"
#include <iostream>
#include <string.h>

using namespace std;

struct ifm {
	Employee employee;
	ifm* next = NULL;

	ifm() : employee(NULL, 0, NULL, NULL) {} // 기본 생성자 null값으로 초기화
};

int main()
{
	char input[10];
	char name[10];
	char temp_name[10];
	int age;
	char country[100];
	char job[100];
	int count;    //직원 정보의 개수를 셈
	ifm* head = NULL;
	ifm* work = nullptr;     //각각의 노드들을 가리키면서 유동적으로 해당 정보를 검색하는 포인터
	ifm* creat = nullptr;    // 생성할 리스트를 연결할 구조체를 가리킬 포인터

	while (1)
	{
		cin >> input;

		if (!strcmp(input, "insert"))
		{
			cin >> name >> age >> country >> job;

			count = 0;
			work = head;
			while (work != NULL)     //직원 정보가 10개가 넘어가는지 파악함
			{
				count++;
				work = work->next;
			}
			if (count == 10)
			{
				cout << "over 10 employee" << endl;
				continue;
			}

			ifm* infor = new ifm;   //구조체 동적할당

			infor->employee.change(name, age, country, job);    // 입력한 직원정보를 멤버함수에 전달

			if (head == nullptr)
			{
				head = infor;
				creat = infor;
			}

			else
			{
				creat->next = infor;
				creat = infor;
			}
		}

		else if (!strcmp(input, "find"))
		{
			work = head;
			cin >> temp_name;

			while (1)
			{
				if (work->employee.isNameCorrect(temp_name))  //찾는 이름이 데이터 베이스에 있는지 없는지 확인함
				{
					cout << "=====find=====" << endl;
					work->employee.print();
					break;
				}

				if (work == NULL)    // 찾고자하는 직원의 이름이 없을 경우 예외처리
				{
					cout << "no name!" << endl;
					break;
				}
				work = work->next;
			}
		}
		else if (!strcmp(input, "change"))
		{
			work = head;
			cin >> temp_name >> name >> age >> country >> job;

			while (1)
			{
				if (work->employee.isNameCorrect(temp_name))      //찾는 이름이 데이터 베이스에 있는지 없는지 확인함
				{
					work->employee.change(name, age, country, job);
					break;
				}

				if (work == NULL)    //change하고자 하는 직원 이름이 없을 경우 예외처리
				{
					cout << "no name!" << endl;
					break;
				}
				work = work->next;
			}
		}
		else if (!strcmp(input, "print"))    // print 명령어를 수행하는 부분
		{
			work = head;
			cout << "=====print=====" << endl;
			while (work != NULL)    //링크드 리스트의 끝까지 직원들의 정보 출력
			{
				work->employee.print();
				work = work->next;
			}

		}
		else if (!strcmp(input, "exit"))
			break;
		else        //그외 명령어들이 잘 못 입력되었을 경우 예외처리
		{
			cout << "wrong command";
			continue;
		}
	}
	work = head;
	while (work != NULL)    //동적할당한 메모리 해제
	{
		work = work->next;
		delete[] head;
		head = work;
	}

	return 0;
}