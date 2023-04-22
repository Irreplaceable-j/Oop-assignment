#include <iostream>
#include <string.h>   //문자열을 비교하는 strcmp()함수를 사용하기 위해 string.h헤더파일 선언

using namespace std;

int main()
{
	int stack[128];    
	char arr[10];

	char push[] = "push";       //각각의 명령어를 배열에 저장하고 문자열을 비교함
	char pop[] = "pop";
	char tp[] = "top";
	char print[] = "print";
	char empty[] = "empty";
	char exit[] = "exit";

	int temp;
	int top = 0;       //top은 형식적 stack의 위치를 나타냄


	while (1)   //exit명령어를 입력하지 않는 이상 무한루프롤 돌게됨
	{
		cin >> arr;

		if (!strcmp(arr, push))   //push라는 명령어를 입력했을 때 입력값을 받아 stack에 저장시킴
		{
			cin >> temp;
			stack[top] = temp;            
			top++;
		}

		else if (!strcmp(arr, pop))
		{
			if (top == 0)         //스택이 비어있을 경우 예외처리
			{
				cout << "stack is empty";
				continue;
			}

			cout << stack[top - 1] << endl;   //top은 인덱스 값으로 top에서 1을 뺀 인덱스값에 top이 저장되어있음
			top--;
			
		}

		else if (!strcmp(arr, tp))    //top에 저장된 값을 출력함
		{
			cout << stack[top - 1] << endl;
		}

		else if (!strcmp(arr, print))    //저장되어 있는 모든값을 출력함
		{
			for (int i = 0; i < top; i++)
			{
				cout << stack[i] << ' ';
			}
			cout << endl;
		}

		else if (!strcmp(arr, empty))   
		{
			if (top == 0)           //stack이 비어있으면 top은 0을 가리키므로 if문을 만족하여 1을 출력함
				cout << 1 << endl;

			else
				cout << 0 << endl;
		}

		else if (!strcmp(arr, exit))    //무한루프를 벗어나 프로그램 종료
			break;

		else
			cout << "wrong!!";
	}

	cout << "프로그램 종료";

	return 0;
}