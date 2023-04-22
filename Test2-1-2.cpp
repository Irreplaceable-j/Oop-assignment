#include <iostream>

using namespace std;

void mazepath(int** arr, int x, int y, int x1, int y1, int x2, int y2, int count, int** visit)
{
	if (x1 == x2 && y1 == y2)  //�������� �������� ������ ���
	{
		cout << count;
		return;
	}

	if (x1 < 0 || y1 < 0 || x1 >= x || y1 >= y)  //�̷��� ũ�⸦ ��� ���
	{
		return;
	}

	if (arr[x1][y1] == 1 || visit[x1][y1] == 1)  //Ž���� ��ΰ� ��(1��)�̰ų� �̹� ������ ����� ���
	{
		return;
	}

	visit[x1][y1] = 1; // ���� ��ġ�� �湮�� ������ ǥ��
	
	mazepath(arr, x, y, x1 - 1, y1, x2, y2, count + 1, visit);  //��������� ��θ� Ž���ϴ� ����Լ�
	mazepath(arr, x, y, x1, y1 - 1, x2, y2, count + 1, visit);  //���ʹ������� ��θ� Ž���ϴ� ����Լ�
	mazepath(arr, x, y, x1 + 1, y1, x2, y2, count + 1, visit);  //�Ϲ������� ��θ� Ž���ϴ� ����Լ�
	mazepath(arr, x, y, x1, y1 + 1, x2, y2, count + 1, visit);  //������ �������� ��θ� Ž���ϴ� ����Լ�
	
}

int main()
{
	int x, y;
	cin >> x >> y;

	if ((x < 1 || x > 30) || (y < 1 || y > 30))
	{
		cout << "wrong value!";
		return 0;
	}

	int** arr = new int* [x];   //�޸𸮸� 2���� �迭�� �����Ҵ���
	for (int i = 0; i < x; i++) 
	{
		arr[i] = new int[y];

	}

	int** visit = new int* [x];   //�޸𸮸� 2���� �迭�� �����Ҵ���
	for (int i = 0; i < x; i++)
	{
		visit[i] = new int[y];
	}

	for (int i = 0; i < x; i++)  //�̷ο� 0��1�� �Է¹���
	{
		for (int j = 0; j < y; j++)
		{
			cin >> arr[i][j];
		}
	}

	int x1, x2, y1, y2;
	cin >> y1 >> x1 >> y2 >> x2;  //�Է¹��� ���� 2���� �迭�� �ε��� ������ �Է¹ޱ� ���ؼ� x��ǥ�� y��ǥ�� ���� �ݴ�� ����

	mazepath(arr, x, y, x1 - 1, y1 - 1, x2 - 1, y2 - 1, 1, visit);  //�ִܰŸ��� ������ִ� �̷��� ���ã�� �Լ� 

	for (int i = 0; i < x; i++)   //�����Ҵ��� �̷ΰ� ����� �迭�� �޸� ����
	{
		delete[] arr[i];
	}

	delete[] arr;

	for (int i = 0; i < x; i++)   //�����Ҵ��� �̹� ������ ��ΰ� ����� �޸� ����
	{
		delete[] visit[i];
	}

	delete[] visit;


	return 0;
}