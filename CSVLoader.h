#pragma once

#include <fstream>
#include <string>

using namespace std;

class CSVLoader
{
public:
	static constexpr unsigned int MAX_BUFFER_SIZE = 128;

public:
	CSVLoader();
	CSVLoader(const char* path);  //CSV 파일 이름을 인자로 받는 생성자
	~CSVLoader();   

	float** getData() const;   //data 멤버 변수의 값을 반환하는 함수
	int getRows() const;         //rows 멤버 변수의 값을 반환하는 함수
	int getCols() const;       //cols 멤버 변수의 값을 반환하는 함수

	void parse(const char* path); 
	void print(void);              //data 배열의 값을 출력하는 함수

private:
	float** data;   
	int cols;       
	int rows;      

};
