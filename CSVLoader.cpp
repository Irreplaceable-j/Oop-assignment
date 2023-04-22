#define _CRT_SECURE_NO_WARNINGS   //strtok�� ���� ������ ��������
#include "CSVLoader.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

CSVLoader::CSVLoader()   //�����ڸ� ȣ���ϰ� �� �������� �ʱ�ȭ ����
{
    data = NULL;
    cols = 0;
    rows = 0;

}

CSVLoader::CSVLoader(const char* path)  
{
    parse(path);  //������ �̸��� ���ڷ� �����Ͽ� parse�Լ� ȣ��
}

CSVLoader::~CSVLoader()
{   
    for (int i = 0; i < rows; i++)  // �������� �Ҵ�� 2���� �迭 ����
    {
        delete[] data[i];
    }
    delete[] data;
}

float** CSVLoader::getData() const  //��� �Լ��� ��ü�� ���¸� �������� ����
{
    return data;   //�ܺο��� ����Լ��� �������� ���ϱ� ������ �Լ��� ���ؼ� ��� �Լ��� ������
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
	ifstream file(path);  //�Է� ��Ʈ�� ��ü ����

	if (!file)
	{
		cout << "Failed to open file";
		return;
	}

	char line[128];  //���Ͽ��� �о�� ���ڿ��� ������ �迭
    char* temp;    //','�� ���е� ���ڿ��� �ּҸ� ������ ������
    int COLS = 0;
    int ROWS = 0;

    while (file.getline(line, 128))
    {
        for (int com = 0; line[com] != '\0'; com++)  //������ ���� ������ ��
        {
            if (line[com] == ',')
                cols++;
        }
        cols++;
        rows++;  //������ �ѹ� �о��� ������ ���� ���� �ѹ� ������Ŵ
        break;
    }

    while (file.getline(line, 128))  //������ ���� ������ ��
    {
        rows++;
    }
    
    data = new float* [rows];       //2���� �迭 �����Ҵ�
    for (int i = 0; i < rows; i++)
    {
        data[i] = new float[cols];
    }
    
    file.clear();  // eofbit�� ���� ���� �÷��׸� �ʱ�ȭ�մϴ�.
    file.seekg(0, ios::beg);  // ���� �����͸� �� ó������ �̵���ŵ�ϴ�.
    
	while (file.getline(line, 128))
	{
        if (strlen(line) > MAX_BUFFER_SIZE)  //������ �ִ� ũ�⸦ �ѱ� ��� �����ϰ� ���� ������ ���� �Է¹���
        {
            cout << "over max buffer";
            continue;
        }
  
        COLS = 0;  //������ ���� ���� �� ���� �� ���� �ʱ�ȭ��
      
        temp = strtok(line, ",\n");   //ù��° ȣ�� �ÿ��� ���ڿ��� �ּҸ� �ѱ�� ','�� '\n'�� �����ڷ� �ν��Ͽ� ���ڿ��� �߶� ������
                                      //��ǻ� ���ڿ��� ���������� \0���ڰ� ����Ǿ� �ֱ� ������ \n���ڸ� �о������ ���� (�������� �ڵ�)

        while (temp != NULL)   //���ڿ��� ������ Ž���ϸ� temp���� NULL���� ����Ǿ� while���� ��������
        {
            data[ROWS][COLS] = stof(temp);  //temp�� ����� ���ڿ��� float������ ��ȯ�Ͽ� �迭�� ����

            temp = strtok(NULL, ",\n");   //���� ���ڿ��� ������
            COLS++;
        }

        ROWS++;
    }

    file.close();  //������ ���� ��Ʈ���� close����
}

void CSVLoader::print(void)   //����� �迭�� ����ϴ� �Լ�
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