#include"Matrix.h"
#include<iostream>

using namespace std;

Matrix::Matrix() {         // ��� ���� matrix�迭�� 0���� �ʱ�ȭ
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
        }
    }
}

    // �����ڿ� ���� ���� �޾� ���� ����� �ʱ�ȭ ��
Matrix::Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i) {  
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[0][2] = c;
    matrix[1][0] = d;
    matrix[1][1] = e;
    matrix[1][2] = f;
    matrix[2][0] = g;
    matrix[2][1] = h;
    matrix[2][2] = i;
}

void Matrix::printMatrix() {     // ����� �� ��Ҹ� ����ϴ� �Լ�
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix& Matrix::operator+=(const Matrix& other) {   // +=������ �����ε�, �� ����� ���� ����
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {   // -=������ �����ε�, �� ����� ���� ����
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& other) {    // *=������ �����ε�, ��İ� ����
    Matrix times;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                times.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    return times;
}





