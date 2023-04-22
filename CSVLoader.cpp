#define _CRT_SECURE_NO_WARNINGS   //strtok에 관한 오류를 방지해줌
#include "CSVLoader.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

CSVLoader::CSVLoader()   //생성자를 호출하고 각 변수들을 초기화 해줌
{
    data = NULL;
    cols = 0;
    rows = 0;

}

CSVLoader::CSVLoader(const char* path)  
{
    parse(path);  //파일의 이름을 인자로 전달하여 parse함수 호출
}

CSVLoader::~CSVLoader()
{   
    for (int i = 0; i < rows; i++)  // 동적으로 할당된 2차원 배열 해제
    {
        delete[] data[i];
    }
    delete[] data;
}

float** CSVLoader::getData() const  //멤버 함수가 객체의 상태를 변경하지 않음
{
    return data;   //외부에서 멤버함수에 접근하지 못하기 때문에 함수를 통해서 멤버 함수에 접근함
}

int CSVLoader::getRows() const
{
    return rows;
}

int CSVLoader::getCols() const
{
    return cols;
}

void CSVLoader::parse(const char* path)
{
	ifstream file(path);  //입력 스트림 객체 생성

	if (!file)
	{
		cout << "Failed to open file";
		return;
	}

	char line[128];  //파일에서 읽어온 문자열을 저장할 배열
    char* temp;    //','로 구분된 문자열의 주소를 저장할 포인터
    int COLS = 0;
    int ROWS = 0;

    while (file.getline(line, 128))
    {
        for (int com = 0; line[com] != '\0'; com++)  //파일의 열의 개수를 셈
        {
            if (line[com] == ',')
                cols++;
        }
        cols++;
        rows++;  //파일을 한번 읽었기 때문에 행의 수도 한번 증가시킴
        break;
    }

    while (file.getline(line, 128))  //파일의 행의 개수를 셈
    {
        rows++;
    }
    
    data = new float* [rows];       //2차원 배열 동적할당
    for (int i = 0; i < rows; i++)
    {
        data[i] = new float[cols];
    }
    
    file.clear();  // eofbit와 같은 상태 플래그를 초기화합니다.
    file.seekg(0, ios::beg);  // 파일 포인터를 맨 처음으로 이동시킵니다.
    
	while (file.getline(line, 128))
	{
        if (strlen(line) > MAX_BUFFER_SIZE)  //버퍼의 최대 크기를 넘긴 경우 무시하고 다음 데이터 부터 입력받음
        {
            cout << "over max buffer";
            continue;
        }
  
        COLS = 0;  //파일을 한줄 읽을 때 마다 열 수를 초기화함
      
        temp = strtok(line, ",\n");   //첫번째 호출 시에는 문자열의 주소를 넘기고 ','와 '\n'을 구분자로 인식하여 문자열을 잘라서 저장함
                                      //사실상 문자열의 마지막에는 \0문자가 저장되어 있기 때문에 \n문자를 읽어들이진 않음 (형식적인 코드)

        while (temp != NULL)   //문자열의 끝까지 탐색하면 temp에는 NULL값이 저장되어 while문은 빠져나옴
        {
            data[ROWS][COLS] = stof(temp);  //temp에 저장된 문자열을 float형으로 변환하여 배열에 저장

            temp = strtok(NULL, ",\n");   //다음 문자열을 저장함
            COLS++;
        }

        ROWS++;
    }

    file.close();  //열었던 파일 스트림을 close해줌
}

void CSVLoader::print(void)   //저장된 배열을 출력하는 함수
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}