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


	int count;    //���� ������ ������ ��

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
		else if (!strcmp(command, "print_class"))    // print ��ɾ �����ϴ� �κ�
		{
			cin >> class_name;
			inf.FindClass(class_name);

		}
		else if (!strcmp(command, "exit"))
			break;
		else        //�׿� ��ɾ���� �� �� �ԷµǾ��� ��� ����ó��
		{
			cout << "wrong command";
			continue;
		}
	}

	return 0;

}