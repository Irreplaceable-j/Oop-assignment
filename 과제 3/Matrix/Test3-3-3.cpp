#include"Matrix.h"
#include<iostream>

using namespace std;

int main() {
    Matrix m1(1, 2, 3, 4, 5, 6, 7, 8, 9);   // Ŭ���� ��ü�� �����ϰ� ���� �ʱ�ȭ ��Ŵ
    Matrix m2(9, 8, 7, 6, 5, 4, 3, 2, 1);
    Matrix m3(9, 8, 7, 8, 9, 7, 7, 8, 9);

    cout << "Matrix m1:" << endl;        // �� �ʱ�ȭ ����� Ȯ��
    m1.printMatrix();

    cout << "Matrix m2:" << endl;
    m2.printMatrix();

    cout << "Matrix m3:" << endl;
    m3.printMatrix();

    m1 += m2;         // += ������ ����
    cout << "Matrix m1 += m2:" << endl;
    m1.printMatrix();

    m1 -= m3;        // -= ������ ����
    cout << "Matrix m1 -= m3:" << endl;
    m1.printMatrix();

    Matrix m4 = m1 * m2;         // *= ������ ����
    cout << "Matrix m1 * m2:" << endl;
    m4.printMatrix();

    return 0;
}