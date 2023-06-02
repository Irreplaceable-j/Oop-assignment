#include"Matrix.h"
#include<iostream>

using namespace std;

Matrix::Matrix() {         // 멤버 변수 matrix배열을 0으로 초기화
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = 0;
        }
    }
}

    // 생성자에 인자 값을 받아 직접 행렬을 초기화 함
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

void Matrix::printMatrix() {     // 행렬의 각 요소를 출력하는 함수
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix& Matrix::operator+=(const Matrix& other) {   // +=연산자 오버로딩, 두 행렬의 덧셈 연산
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {   // -=연산자 오버로딩, 두 행렬의 뺄셈 연산
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& other) {    // *=연산자 오버로딩, 행렬곱 연산
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





