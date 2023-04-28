#include "Employee.h"
#include <iostream>
#include <string.h>

using namespace std;

struct ifm {
	Employee employee;
	ifm* next = NULL;

	ifm() : employee(NULL, 0, NULL, NULL) {} // �⺻ ������ null������ �ʱ�ȭ
};

int main()
{
	char input[10];
	char name[10];
	char temp_name[10];
	int age;
	char country[100];
	char job[100];
	int count;    //���� ������ ������ ��
	ifm* head = NULL;
	ifm* work = nullptr;     //������ ������ ����Ű�鼭 ���������� �ش� ������ �˻��ϴ� ������
	ifm* creat = nullptr;    // ������ ����Ʈ�� ������ ����ü�� ����ų ������

	while (1)
	{
		cin >> input;

		if (!strcmp(input, "insert"))
		{
			cin >> name >> age >> country >> job;

			count = 0;
			work = head;
			while (work != NULL)     //���� ������ 10���� �Ѿ���� �ľ���
			{
				count++;
				work = work->next;
			}
			if (count == 10)
			{
				cout << "over 10 employee" << endl;
				continue;
			}

			ifm* infor = new ifm;   //����ü �����Ҵ�

			infor->employee.change(name, age, country, job);    // �Է��� ���������� ����Լ��� ����

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
				if (work->employee.isNameCorrect(temp_name))  //ã�� �̸��� ������ ���̽��� �ִ��� ������ Ȯ����
				{
					cout << "=====find=====" << endl;
					work->employee.print();
					break;
				}

				if (work == NULL)    // ã�����ϴ� ������ �̸��� ���� ��� ����ó��
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
				if (work->employee.isNameCorrect(temp_name))      //ã�� �̸��� ������ ���̽��� �ִ��� ������ Ȯ����
				{
					work->employee.change(name, age, country, job);
					break;
				}

				if (work == NULL)    //change�ϰ��� �ϴ� ���� �̸��� ���� ��� ����ó��
				{
					cout << "no name!" << endl;
					break;
				}
				work = work->next;
			}
		}
		else if (!strcmp(input, "print"))    // print ��ɾ �����ϴ� �κ�
		{
			work = head;
			cout << "=====print=====" << endl;
			while (work != NULL)    //��ũ�� ����Ʈ�� ������ �������� ���� ���
			{
				work->employee.print();
				work = work->next;
			}

		}
		else if (!strcmp(input, "exit"))
			break;
		else        //�׿� ��ɾ���� �� �� �ԷµǾ��� ��� ����ó��
		{
			cout << "wrong command";
			continue;
		}
	}
	work = head;
	while (work != NULL)    //�����Ҵ��� �޸� ����
	{
		work = work->next;
		delete[] head;
		head = work;
	}

	return 0;
}