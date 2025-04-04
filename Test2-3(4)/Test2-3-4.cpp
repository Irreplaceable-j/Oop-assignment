#include"Matrix_Class.h"
#include <iostream>

using namespace ooplinalg;

void print(Matrix& we, char* str)
{
	std::cout << "------" << str << "------" << std::endl;
	for (int i = 0; i < we.getRows(); i++) {
		for (int j = 0; j < we.getCols(); j++) {
			std::cout << we.getElement(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	int row = 3; 
	int col = 3;
	char Ma[] = "행렬 a";
	char Mb[] = "행렬 b";
	char Mr[] = "행렬 r";
	Matrix a(row, col);
	std::cout << "a행렬 입력" << std::endl;
	float dt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cin >> dt;
			a.setElement(i, j, dt);
		}
	}
	/*
	Matrix b(row, col);
	std::cout << "b행렬 입력" << std::endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cin >> dt;
			b.setElement(i, j, dt);
		}
	}*/
	Matrix r(row, col);

	/*
	add(r, a, b);
	std::cout << "행렬 덧셈" << std::endl;
	print(r, Mr);

	sub(r, a, b);
	std::cout << "행렬 뻴셈" << std::endl;
	print(r, Mr);

	mul(r, a, b);
	std::cout << "행렬 곱셈" << std::endl;
	print(r, Mr);
	*/
	
	/*
	elemetAdd(r, a, 10);
	std::cout << "행렬 스칼라 덧셈" << std::endl;
	print(r, Mr);
	elemetSub(r, a, 5);
	std::cout << "행렬 스칼라 뺄셈" << std::endl;
	print(r, Mr);
	elemetMul(r, a, 3);
	std::cout << "행렬 스칼라 곱" << std::endl;
	print(r, Mr);
	elemetDiv(r, a, 2);
	std::cout << "행렬 스칼라 나눗셈" << std::endl;
	print(r, Mr);
	*/

	dt = a.determinant();
	//std::cout << dt;

	/*
	transpose(r, a);
	std::cout << "전치행렬" << std::endl;
	print(r, Mr);

	adjoint(r, a);
	std::cout << "수반행렬" << std::endl;
	print(r, Mr);

	inverse(r, a);
	std::cout << "역행렬" << std::endl;
	print(r, Mr);
	*/
	/*
	adjoint(r, a);
	std::cout << "수반행렬" << std::endl;
	print(r, Mr);
	*/

	inverse(r, a);
	std::cout << "역행렬" << std::endl;
	print(r, Mr);


	return 0;
}