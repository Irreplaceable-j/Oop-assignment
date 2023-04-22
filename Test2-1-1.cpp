#include <iostream>
#include <string.h>   //���ڿ��� ���ϴ� strcmp()�Լ��� ����ϱ� ���� string.h������� ����

using namespace std;

int main()
{
	int stack[128];    
	char arr[10];

	char push[] = "push";       //������ ��ɾ �迭�� �����ϰ� ���ڿ��� ����
	char pop[] = "pop";
	char tp[] = "top";
	char print[] = "print";
	char empty[] = "empty";
	char exit[] = "exit";

	int temp;
	int top = 0;       //top�� ������ stack�� ��ġ�� ��Ÿ��


	while (1)   //exit��ɾ �Է����� �ʴ� �̻� ���ѷ����� ���Ե�
	{
		cin >> arr;

		if (!strcmp(arr, push))   //push��� ��ɾ �Է����� �� �Է°��� �޾� stack�� �����Ŵ
		{
			cin >> temp;
			stack[top] = temp;            
			top++;
		}

		else if (!strcmp(arr, pop))
		{
			if (top == 0)         //������ ������� ��� ����ó��
			{
				cout << "stack is empty";
				continue;
			}

			cout << stack[top - 1] << endl;   //top�� �ε��� ������ top���� 1�� �� �ε������� top�� ����Ǿ�����
			top--;
			
		}

		else if (!strcmp(arr, tp))    //top�� ����� ���� �����
		{
			cout << stack[top - 1] << endl;
		}

		else if (!strcmp(arr, print))    //����Ǿ� �ִ� ��簪�� �����
		{
			for (int i = 0; i < top; i++)
			{
				cout << stack[i] << ' ';
			}
			cout << endl;
		}

		else if (!strcmp(arr, empty))   
		{
			if (top == 0)           //stack�� ��������� top�� 0�� ����Ű�Ƿ� if���� �����Ͽ� 1�� �����
				cout << 1 << endl;

			else
				cout << 0 << endl;
		}

		else if (!strcmp(arr, exit))    //���ѷ����� ��� ���α׷� ����
			break;

		else
			cout << "wrong!!";
	}

	cout << "���α׷� ����";

	return 0;
}