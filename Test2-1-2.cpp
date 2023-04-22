#include <iostream>

using namespace std;

void mazepath(int** arr, int x, int y, int x1, int y1, int x2, int y2, int count, int** visit)
{
	if (x1 == x2 && y1 == y2)  //목적지인 도착점에 도달한 경우
	{
		cout << count;
		return;
	}

	if (x1 < 0 || y1 < 0 || x1 >= x || y1 >= y)  //미로의 크기를 벗어날 경우
	{
		return;
	}

	if (arr[x1][y1] == 1 || visit[x1][y1] == 1)  //탐색한 경로가 벽(1값)이거나 이미 지나온 경로일 경우
	{
		return;
	}

	visit[x1][y1] = 1; // 현재 위치를 방문한 것으로 표시
	
	mazepath(arr, x, y, x1 - 1, y1, x2, y2, count + 1, visit);  //상방향으로 경로를 탐색하는 재귀함수
	mazepath(arr, x, y, x1, y1 - 1, x2, y2, count + 1, visit);  //왼쪽방향으로 경로를 탐색하는 재귀함수
	mazepath(arr, x, y, x1 + 1, y1, x2, y2, count + 1, visit);  //하방향으로 경로를 탐색하는 재귀함수
	mazepath(arr, x, y, x1, y1 + 1, x2, y2, count + 1, visit);  //오른쪽 방향으로 경로를 탐색하는 재귀함수
	
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

	int** arr = new int* [x];   //메모리를 2차원 배열로 동적할당함
	for (int i = 0; i < x; i++) 
	{
		arr[i] = new int[y];

	}

	int** visit = new int* [x];   //메모리를 2차원 배열로 동적할당함
	for (int i = 0; i < x; i++)
	{
		visit[i] = new int[y];
	}

	for (int i = 0; i < x; i++)  //미로에 0과1을 입력받음
	{
		for (int j = 0; j < y; j++)
		{
			cin >> arr[i][j];
		}
	}

	int x1, x2, y1, y2;
	cin >> y1 >> x1 >> y2 >> x2;  //입력받은 값을 2차원 배열의 인덱스 값으로 입력받기 위해서 x좌표와 y좌표를 각각 반대로 저장

	mazepath(arr, x, y, x1 - 1, y1 - 1, x2 - 1, y2 - 1, 1, visit);  //최단거리를 출력해주는 미로의 경로찾기 함수 

	for (int i = 0; i < x; i++)   //동적할당한 미로가 저장된 배열의 메모리 해제
	{
		delete[] arr[i];
	}

	delete[] arr;

	for (int i = 0; i < x; i++)   //동적할당한 이미 지나온 경로가 저장된 메모리 해제
	{
		delete[] visit[i];
	}

	delete[] visit;


	return 0;
}