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
	char Ma[] = "Çà·Ä a";
	char Mb[] = "Çà·Ä b";
	char Mr[] = "Çà·Ä r";
	Matrix a(row, col);
	std::cout << "aÇà·Ä ÀÔ·Â" << std::endl;
	float dt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cin >> dt;
			a.setElement(i, j, dt);
		}
	}
	/*
	Matrix b(row, col);
	std::cout << "bÇà·Ä ÀÔ·Â" << std::endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cin >> dt;
			b.setElement(i, j, dt);
		}
	}*/
	Matrix r(row, col);

	/*
	add(r, a, b);
	std::cout << "Çà·Ä µ¡¼À" << std::endl;
	print(r, Mr);

	sub(r, a, b);
	std::cout << "Çà·Ä –y¼À" << std::endl;
	print(r, Mr);

	mul(r, a, b);
	std::cout << "Çà·Ä °ö¼À" << std::endl;
	print(r, Mr);
	*/
	
	/*
	elemetAdd(r, a, 10);
	std::cout << "Çà·Ä ½ºÄ®¶ó µ¡¼À" << std::endl;
	print(r, Mr);
	elemetSub(r, a, 5);
	std::cout << "Çà·Ä ½ºÄ®¶ó »¬¼À" << std::endl;
	print(r, Mr);
	elemetMul(r, a, 3);
	std::cout << "Çà·Ä ½ºÄ®¶ó °ö" << std::endl;
	print(r, Mr);
	elemetDiv(r, a, 2);
	std::cout << "Çà·Ä ½ºÄ®¶ó ³ª´°¼À" << std::endl;
	print(r, Mr);
	*/

	dt = a.determinant();
	//std::cout << dt;

	/*
	transpose(r, a);
	std::cout << "ÀüÄ¡Çà·Ä" << std::endl;
	print(r, Mr);

	adjoint(r, a);
	std::cout << "¼ö¹ÝÇà·Ä" << std::endl;
	print(r, Mr);

	inverse(r, a);
	std::cout << "¿ªÇà·Ä" << std::endl;
	print(r, Mr);
	*/
	/*
	adjoint(r, a);
	std::cout << "¼ö¹ÝÇà·Ä" << std::endl;
	print(r, Mr);
	*/

	inverse(r, a);
	std::cout << "¿ªÇà·Ä" << std::endl;
	print(r, Mr);


	return 0;
}