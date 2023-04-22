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
	CSVLoader(const char* path);  //CSV ���� �̸��� ���ڷ� �޴� ������
	~CSVLoader();   

	float** getData() const;   //data ��� ������ ���� ��ȯ�ϴ� �Լ�
	int getRows() const;         //rows ��� ������ ���� ��ȯ�ϴ� �Լ�
	int getCols() const;       //cols ��� ������ ���� ��ȯ�ϴ� �Լ�

	void parse(const char* path); 
	void print(void);              //data �迭�� ���� ����ϴ� �Լ�

private:
	float** data;   
	int cols;       
	int rows;      

};
