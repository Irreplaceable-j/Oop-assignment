#pragma once

class Matrix {

private:
	double matrix[3][3];

public:
    Matrix();
    Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i);
 
    void printMatrix();
     
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator*(const Matrix& other);
};
