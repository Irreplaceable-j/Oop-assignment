#include "CSVLoader.h"
#include <iostream>

using namespace std;

int main()
{
	const char* filename = "CSVLoader_Data.txt";

	CSVLoader csv(filename);  //CSVLoader 객체를 생성하고 파일 이름을 인자값으로 전달함

	csv.print();  //파일에서 읽어들인 값들이 저장된 배열을 출력함

	return 0;
}