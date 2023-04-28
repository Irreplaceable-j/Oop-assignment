#include"Matrix_Class.h"
#include <iostream>

using namespace std;

namespace ooplinalg {
	Matrix::Matrix() {  //기본 3x3 행렬 
		rows = 3;
		cols = 3;
		data = new float* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
			for (int j = 0; j < cols; j++) {
				data[i][j] = 0;
			}
		}
	}
	Matrix::Matrix(const Matrix& mat) {  // mat행렬을 그대로 복사
		rows = mat.rows;
		cols = mat.cols;

		data = new float* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = mat.data[i][j];
			}
		}
	}
	Matrix::Matrix(int rows, int cols) {  //행과 열을 입력 받아 배열 생성
		data = new float*[rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
			for (int j = 0; j < cols; j++) {
				data[i][j] = 0;
			}
		}
		this->rows = rows;
		this->cols = cols;
	}
	Matrix::~Matrix() {    // 2차원 배열 메모리 해제
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}
	float Matrix::getElement(int row, int col) const {  // 해당 위치의 원소 반환
		return data[row][col];
	}
	float** Matrix::getData() const {    // 기존의 2차원 배열 반환
		return data;
	}
	void Matrix::setElement(const int row, const int col, float value) {  // 해당 위치에 원소 저장
		data[row][col] = value;
	}
	void Matrix::setData(const int rows, const int cols, float** data) {  // 기존의 2차원 배열에 행렬을 원소 그대로 복사
		this->rows = rows;
		this->cols = cols;

		for (int i = 0; i < this->rows; i++) {  // 원래 메모리 해제
			delete[] data[i];
		}
		delete[] data;

		this->data = new float* [rows];
		for (int i = 0; i < rows; i++)
		{
			this->data[i] = new float[cols];
			for (int j = 0; j < cols; ++j)
				this->data[i][j] = data[i][j];
		}
	}
	int Matrix::getRows() const {
		return rows;
	}
	int Matrix::getCols() const {
		return cols;
	}
	void Matrix::setRows(const int rows) {
		float** temp = new float* [rows];  //새로운 행렬을 rows값대로 다시 행을 설정하여 메모리 할당
		for (int i = 0; i < rows; i++)
		{
			temp[i] = new float[cols];
			for (int j = 0; j < cols; j++) {
				if (i < this->rows && j < this->cols)
					temp[i][j] = data[i][j];      // 기존 행렬의 값들을 저장할 수 있으면 저장
				else
					temp[i][j] = 0;
			}
		}
		for (int i = 0; i < this->rows; ++i)  //기존 배열 메모리 해제
			delete[] data[i];
		delete[] data;

		data = temp;
		this->rows = rows;
	}
	void Matrix::setCols(const int cols) {
		float** temp = new float* [rows];  // 새로운 행렬을 cols값대로 다시 행을 설정하여 메모리 할당
		for (int i = 0; i < rows; ++i)
		{
			temp[i] = new float[cols];
			for (int j = 0; j < cols; ++j) {
				if (i < this->rows && j < this->cols)
					temp[i][j] = data[i][j];
				else
					temp[i][j] = 0;
			}
		}
		for (int i = 0; i < this->rows; ++i)  //기존 배열 메모리 해제
			delete[] data[i];
		delete[] data;

		data = temp;
		this->cols = cols;
	}
	float Matrix::determinant() {
		if (rows == 1)           //행렬이 1x1일 때 행렬식
			return data[0][0];
		if (rows == 2)           //행렬이 2x2일 때 행렬식
			return data[0][0] * data[1][1] - data[0][1] * data[1][0];

		float det = 0; // 행렬식 값을 저장할 변수
		Matrix submat(rows - 1, cols -1); // 부분 행렬을 저장할 객체

		for (int i = 0; i < rows; i++) {
			int mi = 0; // 부분 행렬의 행 인덱스

			for (int j = 1; j < cols; j++) {     // 1행을 기준으로 부분행렬을 만드므로 인데스는 0을 제외한 1부터
				int mj = 0; // 부분 행렬의 열 인덱스

				for (int k = 0; k < cols; k++) {
					if (k == i)   // 같은 열의 원소는 제외하고 부분행렬을 만듬
						continue;
					submat.setElement(mi, mj, data[j][k]);   // 해당 인덱스에 data값을 저장함
					mj++;
				}
				mi++;
			}
			det += pow(-1, i) * data[0][i] * submat.determinant();  // 재귀함수를 통해 행렬식을 부분행렬로 쪼개어 계산함
		}
		return det;
	}
	Matrix& add(Matrix& r, Matrix& a, Matrix& b) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));
			}
		}
		return r;
	}
	Matrix& sub(Matrix& r, Matrix& a, Matrix& b) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));
			}
		}
		return r;
	}
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				float mtp = 0;     // 행렬곱을 저장할 임시 변수
				for (int k = 0; k < a.getRows(); k++) {

					mtp += a.getElement(i, k) * b.getElement(k, j);
					r.setElement(i, j, a.getElement(i, k) * b.getElement(i, j));  // 행렬곱은 a의 행과 b의 열을 적당히 곱해서 계산함
				}
				r.setElement(i, j, mtp);
			}
		}
		return r;
	}
	Matrix& elemetAdd(Matrix& r, Matrix& a, float v) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) + v);
			}
		}
		return r;
	}
	Matrix& elemetSub(Matrix& r, Matrix& a, float v) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) - v);
			}
		}
		return r;
	}
	Matrix& elemetMul(Matrix& r, Matrix& a, float v) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) * v);
			}
		}
		return r;
	}
	Matrix& elemetDiv(Matrix& r, Matrix& a, float v) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) / v);
			}
		}
		return r;
	}

	Matrix& transpose(Matrix& r, Matrix& m) {
		r.setRows(m.getCols());     //전치행렬을 만들면 행과 열의 수가 바뀐 행렬이 만들어짐
		r.setCols(m.getRows());
		for (int i = 0; i < m.getRows(); i++) {
			for (int j = 0; j < m.getCols(); j++) {
				r.setElement(j, i, m.getElement(i, j));
			}
		}
		return r;
	}
	Matrix& adjoint(Matrix& r, Matrix& m) {
		if (m.getRows() != m.getCols())
			cout << "행과 열의 수가 같지 않습니다(오류 발생)" << endl;
		r.setRows(m.getRows());    
		r.setCols(m.getCols());

		float det = 0; // 행렬식 값을 저장할 변수
		Matrix temp(m.getRows(), m.getCols());    //여인수들로 이루어진 행렬을 저장할 배열
		Matrix adjmat(m.getRows() - 1, m.getCols() - 1);  
		for (int i = 0; i < m.getRows(); i++) {

			for (int j = 0; j < m.getCols(); j++) {     				

				int a = 0, b = 0;
				
				for (int g = 0; g < m.getRows(); g++) {  // 여인수 전개 하는 과정
					if (g == i)               //여인수 전개를 하는 원소에 대하여 그 원소가 포함되어 있는 
						continue;             //행과 열의 원소들을 제외한 원소들로 행열을 만들고 행렬식 값을 계산함
					for (int h = 0; h < m.getCols(); h++) {
						if (h == j)
							continue;
						adjmat.setElement(a, b, m.getElement(g, h));
						b++;
						if (b == adjmat.getCols()) {
							b = 0;
							a++;
						}

					}
				}
				temp.setElement(i, j, pow(-1, i + j) * adjmat.determinant());	  // 여인수 행렬을 r에 저장 
			}
		}
		transpose(r, temp);  //여인수 행렬 전치
		return r;
	}
	Matrix& inverse(Matrix& r, Matrix& m) {  // 역행렬을 출력하는 함수
		float det = 0;
		Matrix temp(m.getRows(), m.getCols());  // 수반행렬을 저장할 행렬
		adjoint(temp, m);
		det = m.determinant();
		elemetDiv(r, temp, det);
		return r;
	}

}