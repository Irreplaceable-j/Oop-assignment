#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

struct Node
{
	struct Node* pNext = NULL;
	struct Node* low = NULL;      //중첩된 노드의 첫번째 노드를 가리킴
	struct Node* Criteria = NULL;   //중첩전의 기준노드를 가리킴
	char str[20] = { '\0' };
};

int main()
{
	char a[100000];     
	char* arr = a;

	char temp[20];    //문자열을 잘라서 저장할 배열
	int data[10];     //입력받은 인덱스를 정수형으로 저장할 배열
	char index[20];   

	int i = 0;
	int j = 0;
	arr++;

	cin.getline(a, 100000);   //공백문자까지 입력받음

	Node* pHead = NULL;
	Node* pWork = NULL;
	Node* pNew = new Node;

	char* end = NULL;      //문자열의 마지막 ']'기호를 판단할 포인터 

	if (pHead == NULL)     //처음 노드를 생성할 경우
	{
		pHead = pNew;
		pWork = pNew;
	}

	else      //노드를 생성하고 이전노드와 연결후 pWork가 가장 마지막에 생성한 노드를 가리킴
	{
		pWork->pNext = pNew;
		pWork = pNew;

	}

	while (*arr != '\0')    //입력한 문자열의 끝까지 읽을 때까지 반복
	{
		if (*arr == ',')    //,가 나올경우 지금까지 읽어 들인 문자열을 temp에 저장
		{
			temp[i] = '\0';
			i = 0;

			if (pWork->Criteria != NULL)   //원래 배열에서 중첩되어 파생된 배열일 경우
			{
				strcpy(pWork->str, temp);  //새로 만든 pNew에 문자열 저장

				Node* pNew = new Node;
			
				pNew->Criteria = (pWork->Criteria); //중첩배열이 파생되는 기준 노드를 가리키게 함
			
				pWork->pNext = pNew;
				pWork = pNew;
				arr++;
				continue;

			}

			strcpy(pWork->str, temp);  //새로 만든 pNew에 문자열 저장

			Node* pNew = new Node;

			pWork->pNext = pNew;   //노드 연결
			pWork = pNew;

			arr++;
			continue;
		}

		if (*arr == '[')   //중첩배열을 만들기 위해 '['문자가 있으면 기준노드를 설정하고 파생되는 노드를 생성
		{
			Node* pNew = new Node;

			pWork->low = pNew;
			pNew->Criteria = pWork;   //파생된 노드들의 Criteria는 파생이 시작된 기준 노드를 가리킴
			pWork = pNew;
			arr++;
			continue;
		}

		if (*arr == ' ')   //공백문자는 건너뜀
		{
			arr++;
			continue;
		}

		if (*arr == ']')   
		{
			temp[i] = '\0';
			i = 0;

			strcpy(pWork->str, temp);  //새로 만든 pNew에 문자열 저장

			end = arr;  //arr의 현재 주소값을 임시 변수에 저장
			end++;
			
			if (*end == '\0')  //문자열의 마지막에 ']'기호가있을 때는 노드를 생성하지 않음
			{
				arr++;
				continue;
			}

			Node* pNew = new Node;

			pWork = pWork->Criteria;  //중첩배열이 파생되는 기준 노드를 pWork가 가리키게 하고 pWork의 pNext가 다음 노드를 가리킬 수 있게 함
			pNew->Criteria = pWork->Criteria;  //3중첩 이상일 때 이전 노드의 기준노드 주소값을 다음 노드에도 저장해줌
			
			pWork->pNext = pNew;
			pWork = pNew;

			arr += 2;   //]뒤에 ,가 왔을 때는 이미 문자열을 노드에 저장했기 때문에 다음 문자열의 ,가 나올때 노드를 생성하게 함
			continue;      //]뒤의 ,를 건너뛰게 함
		}

		temp[i] = *arr;  //문자열 저장
		i++;
		arr++;
	}

	pWork = pHead;  //맨 처음 노드로 돌아감

	while (1)   
	{
		cout << "입력: ";

		cin.getline(index, 20);  //공백문자도 문자열중 하나로 입력받음

		if (strcmp(index, "exit") == 0)
		{
			break;
		}

		pWork = pHead;  //맨 처음 노드로 돌아감

		for (int t = 0; t < 10; t++)   //인덱스를 저장할 배열을 모두 음수로 초기화
		{
			data[t] = -1;
		}

		j = 0;

		if (strcmp(index, "arr") == 0)
		{
			cout << a << endl;      
			continue;
		}

		for (i = 0; i < strlen(index); i++)   //입력한 배열의 인덱스를 저장함
		{
			if (index[i] >= '0' && index[i] <= '9')
			{
				data[j] = index[i] - '0';   //정수형으로 저장
				j++;
			}
		}

		for (int h = 0; h < j; h++)   //인덱스의 문자열 출력
		{
	
			for (int k = 0; k < data[h]; k++)  //인덱스 만큼 노드를 탐색
			{
	
				if (pWork != NULL) 
				{
					pWork = pWork->pNext;
				}
				else        //pWork가 NULL인 경우 처리 예를 들어, 오류 메시지 출력 또는 프로그램 종료 등)
				{
					break;
				}
			}

			if (data[h + 1] < 0)  //다음 하위 인덱스없을 경우
			{
				
				if (pWork->low != NULL)  //파생되는 노드가 있을 경우 [ ]를 이용하여 해당 노드들을 전체 출력함
				{
					pWork = pWork->low;
					cout << '[';
					cout << pWork->str;          //일단 한번 출력해줌
					while (pWork->pNext != NULL)
					{
						cout << ", ";
						pWork = pWork->pNext;
						cout << pWork->str;
					}
					cout << ']' << endl;
					continue;
				}

				else if (pWork->low == NULL)   //파생되는 노드가 없고 단일 노드일 경우 해당 문자열 출력
				{
					cout << pWork->str << endl;
					continue;
				}
			}
			
			else if (data[h + 1] >= 0)    //다음 하위 인덱스가 있을 경우 노드를 타고 아래로 감
			{
				pWork = pWork->low;
			}
		}
	}

	pWork = pHead;

	while (!(pWork->pNext == NULL && pWork->Criteria == NULL))  //다음을 가리키는 노드가 없고 기준 노드도 없을 때 까지 메모리 해제
	{
		if (pWork->low != NULL)     //파생되는 노드가 있을 경우 
		{
			pWork = pHead->low;    
			pHead->low = NULL;    //파생되는 노드로 넘어갔을때 이전 노드의 low값은 NULL로 초기화 함
			pHead = pWork;
		}

		pWork = pHead->pNext;
		delete pHead;
		pHead = pWork;

		if (pWork->pNext == NULL)          //다음을 가리키는 노드가 없고
		{
			if (pWork->Criteria != NULL)   //기준 노드에서 파생된 노드일 경우 
			{
				pWork = pHead->Criteria;   //기준 노드로 돌아가고 이전 노드 삭제
				delete pHead;
				pHead = pWork;
			}
		}
	}
	delete pWork;   //마지막 노드 삭제
	
	return 0;
}