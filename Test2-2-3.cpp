#include "CSVLoader.h"
#include <iostream>

using namespace std;

int main()
{
	const char* filename = "CSVLoader_Data.txt";

	CSVLoader csv(filename);  //CSVLoader ��ü�� �����ϰ� ���� �̸��� ���ڰ����� ������

	csv.print();  //���Ͽ��� �о���� ������ ����� �迭�� �����

	return 0;
}