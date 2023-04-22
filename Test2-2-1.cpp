#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

struct Node
{
	struct Node* pNext = NULL;
	struct Node* low = NULL;      //��ø�� ����� ù��° ��带 ����Ŵ
	struct Node* Criteria = NULL;   //��ø���� ���س�带 ����Ŵ
	char str[20] = { '\0' };
};

int main()
{
	char a[100000];     
	char* arr = a;

	char temp[20];    //���ڿ��� �߶� ������ �迭
	int data[10];     //�Է¹��� �ε����� ���������� ������ �迭
	char index[20];   

	int i = 0;
	int j = 0;
	arr++;

	cin.getline(a, 100000);   //���鹮�ڱ��� �Է¹���

	Node* pHead = NULL;
	Node* pWork = NULL;
	Node* pNew = new Node;

	char* end = NULL;      //���ڿ��� ������ ']'��ȣ�� �Ǵ��� ������ 

	if (pHead == NULL)     //ó�� ��带 ������ ���
	{
		pHead = pNew;
		pWork = pNew;
	}

	else      //��带 �����ϰ� �������� ������ pWork�� ���� �������� ������ ��带 ����Ŵ
	{
		pWork->pNext = pNew;
		pWork = pNew;

	}

	while (*arr != '\0')    //�Է��� ���ڿ��� ������ ���� ������ �ݺ�
	{
		if (*arr == ',')    //,�� ���ð�� ���ݱ��� �о� ���� ���ڿ��� temp�� ����
		{
			temp[i] = '\0';
			i = 0;

			if (pWork->Criteria != NULL)   //���� �迭���� ��ø�Ǿ� �Ļ��� �迭�� ���
			{
				strcpy(pWork->str, temp);  //���� ���� pNew�� ���ڿ� ����

				Node* pNew = new Node;
			
				pNew->Criteria = (pWork->Criteria); //��ø�迭�� �Ļ��Ǵ� ���� ��带 ����Ű�� ��
			
				pWork->pNext = pNew;
				pWork = pNew;
				arr++;
				continue;

			}

			strcpy(pWork->str, temp);  //���� ���� pNew�� ���ڿ� ����

			Node* pNew = new Node;

			pWork->pNext = pNew;   //��� ����
			pWork = pNew;

			arr++;
			continue;
		}

		if (*arr == '[')   //��ø�迭�� ����� ���� '['���ڰ� ������ ���س�带 �����ϰ� �Ļ��Ǵ� ��带 ����
		{
			Node* pNew = new Node;

			pWork->low = pNew;
			pNew->Criteria = pWork;   //�Ļ��� ������ Criteria�� �Ļ��� ���۵� ���� ��带 ����Ŵ
			pWork = pNew;
			arr++;
			continue;
		}

		if (*arr == ' ')   //���鹮�ڴ� �ǳʶ�
		{
			arr++;
			continue;
		}

		if (*arr == ']')   
		{
			temp[i] = '\0';
			i = 0;

			strcpy(pWork->str, temp);  //���� ���� pNew�� ���ڿ� ����

			end = arr;  //arr�� ���� �ּҰ��� �ӽ� ������ ����
			end++;
			
			if (*end == '\0')  //���ڿ��� �������� ']'��ȣ������ ���� ��带 �������� ����
			{
				arr++;
				continue;
			}

			Node* pNew = new Node;

			pWork = pWork->Criteria;  //��ø�迭�� �Ļ��Ǵ� ���� ��带 pWork�� ����Ű�� �ϰ� pWork�� pNext�� ���� ��带 ����ų �� �ְ� ��
			pNew->Criteria = pWork->Criteria;  //3��ø �̻��� �� ���� ����� ���س�� �ּҰ��� ���� ��忡�� ��������
			
			pWork->pNext = pNew;
			pWork = pNew;

			arr += 2;   //]�ڿ� ,�� ���� ���� �̹� ���ڿ��� ��忡 �����߱� ������ ���� ���ڿ��� ,�� ���ö� ��带 �����ϰ� ��
			continue;      //]���� ,�� �ǳʶٰ� ��
		}

		temp[i] = *arr;  //���ڿ� ����
		i++;
		arr++;
	}

	pWork = pHead;  //�� ó�� ���� ���ư�

	while (1)   
	{
		cout << "�Է�: ";

		cin.getline(index, 20);  //���鹮�ڵ� ���ڿ��� �ϳ��� �Է¹���

		if (strcmp(index, "exit") == 0)
		{
			break;
		}

		pWork = pHead;  //�� ó�� ���� ���ư�

		for (int t = 0; t < 10; t++)   //�ε����� ������ �迭�� ��� ������ �ʱ�ȭ
		{
			data[t] = -1;
		}

		j = 0;

		if (strcmp(index, "arr") == 0)
		{
			cout << a << endl;      
			continue;
		}

		for (i = 0; i < strlen(index); i++)   //�Է��� �迭�� �ε����� ������
		{
			if (index[i] >= '0' && index[i] <= '9')
			{
				data[j] = index[i] - '0';   //���������� ����
				j++;
			}
		}

		for (int h = 0; h < j; h++)   //�ε����� ���ڿ� ���
		{
	
			for (int k = 0; k < data[h]; k++)  //�ε��� ��ŭ ��带 Ž��
			{
	
				if (pWork != NULL) 
				{
					pWork = pWork->pNext;
				}
				else        //pWork�� NULL�� ��� ó�� ���� ���, ���� �޽��� ��� �Ǵ� ���α׷� ���� ��)
				{
					break;
				}
			}

			if (data[h + 1] < 0)  //���� ���� �ε������� ���
			{
				
				if (pWork->low != NULL)  //�Ļ��Ǵ� ��尡 ���� ��� [ ]�� �̿��Ͽ� �ش� ������ ��ü �����
				{
					pWork = pWork->low;
					cout << '[';
					cout << pWork->str;          //�ϴ� �ѹ� �������
					while (pWork->pNext != NULL)
					{
						cout << ", ";
						pWork = pWork->pNext;
						cout << pWork->str;
					}
					cout << ']' << endl;
					continue;
				}

				else if (pWork->low == NULL)   //�Ļ��Ǵ� ��尡 ���� ���� ����� ��� �ش� ���ڿ� ���
				{
					cout << pWork->str << endl;
					continue;
				}
			}
			
			else if (data[h + 1] >= 0)    //���� ���� �ε����� ���� ��� ��带 Ÿ�� �Ʒ��� ��
			{
				pWork = pWork->low;
			}
		}
	}

	pWork = pHead;

	while (!(pWork->pNext == NULL && pWork->Criteria == NULL))  //������ ����Ű�� ��尡 ���� ���� ��嵵 ���� �� ���� �޸� ����
	{
		if (pWork->low != NULL)     //�Ļ��Ǵ� ��尡 ���� ��� 
		{
			pWork = pHead->low;    
			pHead->low = NULL;    //�Ļ��Ǵ� ���� �Ѿ���� ���� ����� low���� NULL�� �ʱ�ȭ ��
			pHead = pWork;
		}

		pWork = pHead->pNext;
		delete pHead;
		pHead = pWork;

		if (pWork->pNext == NULL)          //������ ����Ű�� ��尡 ����
		{
			if (pWork->Criteria != NULL)   //���� ��忡�� �Ļ��� ����� ��� 
			{
				pWork = pHead->Criteria;   //���� ���� ���ư��� ���� ��� ����
				delete pHead;
				pHead = pWork;
			}
		}
	}
	delete pWork;   //������ ��� ����
	
	return 0;
}