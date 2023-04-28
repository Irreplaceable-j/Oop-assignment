#include "S_information.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char command[20];
	char name[10];
	int age = 0;
	char class_name[100];


	int count;    //직원 정보의 개수를 셈

	School inf;

	while (1)
	{
		cin >> command;

		if (!strcmp(command, "new_student"))
		{
			cin >> name >> age >> class_name;
			inf.addStudent(name, age, class_name);

		}
		else if (!strcmp(command, "sort_by_name"))
		{
			inf.sort_by_name();
		}
		else if (!strcmp(command, "print_all"))
		{
			inf.print_all();
		}
		else if (!strcmp(command, "print_class"))    // print 명령어를 수행하는 부분
		{
			cin >> class_name;
			inf.FindClass(class_name);

		}
		else if (!strcmp(command, "exit"))
			break;
		else        //그외 명령어들이 잘 못 입력되었을 경우 예외처리
		{
			cout << "wrong command";
			continue;
		}
	}

	return 0;

}