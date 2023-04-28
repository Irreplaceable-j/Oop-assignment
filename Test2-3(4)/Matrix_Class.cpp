#include"Matrix_Class.h"
#include <iostream>

using namespace std;

namespace ooplinalg {
	Matrix::Matrix() {  //�⺻ 3x3 ��� 
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
	Matrix::Matrix(const Matrix& mat) {  // mat����� �״�� ����
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
	Matrix::Matrix(int rows, int cols) {  //��� ���� �Է� �޾� �迭 ����
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
	Matrix::~Matrix() {    // 2���� �迭 �޸� ����
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}
	float Matrix::getElement(int row, int col) const {  // �ش� ��ġ�� ���� ��ȯ
		return data[row][col];
	}
	float** Matrix::getData() const {    // ������ 2���� �迭 ��ȯ
		return data;
	}
	void Matrix::setElement(const int row, const int col, float value) {  // �ش� ��ġ�� ���� ����
		data[row][col] = value;
	}
	void Matrix::setData(const int rows, const int cols, float** data) {  // ������ 2���� �迭�� ����� ���� �״�� ����
		this->rows = rows;
		this->cols = cols;

		for (int i = 0; i < this->rows; i++) {  // ���� �޸� ����
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
		float** temp = new float* [rows];  //���ο� ����� rows����� �ٽ� ���� �����Ͽ� �޸� �Ҵ�
		for (int i = 0; i < rows; i++)
		{
			temp[i] = new float[cols];
			for (int j = 0; j < cols; j++) {
				if (i < this->rows && j < this->cols)
					temp[i][j] = data[i][j];      // ���� ����� ������ ������ �� ������ ����
				else
					temp[i][j] = 0;
			}
		}
		for (int i = 0; i < this->rows; ++i)  //���� �迭 �޸� ����
			delete[] data[i];
		delete[] data;

		data = temp;
		this->rows = rows;
	}
	void Matrix::setCols(const int cols) {
		float** temp = new float* [rows];  // ���ο� ����� cols����� �ٽ� ���� �����Ͽ� �޸� �Ҵ�
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
		for (int i = 0; i < this->rows; ++i)  //���� �迭 �޸� ����
			delete[] data[i];
		delete[] data;

		data = temp;
		this->cols = cols;
	}
	float Matrix::determinant() {
		if (rows == 1)           //����� 1x1�� �� ��Ľ�
			return data[0][0];
		if (rows == 2)           //����� 2x2�� �� ��Ľ�
			return data[0][0] * data[1][1] - data[0][1] * data[1][0];

		float det = 0; // ��Ľ� ���� ������ ����
		Matrix submat(rows - 1, cols -1); // �κ� ����� ������ ��ü

		for (int i = 0; i < rows; i++) {
			int mi = 0; // �κ� ����� �� �ε���

			for (int j = 1; j < cols; j++) {     // 1���� �������� �κ������ ����Ƿ� �ε����� 0�� ������ 1����
				int mj = 0; // �κ� ����� �� �ε���

				for (int k = 0; k < cols; k++) {
					if (k == i)   // ���� ���� ���Ҵ� �����ϰ� �κ������ ����
						continue;
					submat.setElement(mi, mj, data[j][k]);   // �ش� �ε����� data���� ������
					mj++;
				}
				mi++;
			}
			det += pow(-1, i) * data[0][i] * submat.determinant();  // ����Լ��� ���� ��Ľ��� �κ���ķ� �ɰ��� �����
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
				float mtp = 0;     // ��İ��� ������ �ӽ� ����
				for (int k = 0; k < a.getRows(); k++) {

					mtp += a.getElement(i, k) * b.getElement(k, j);
					r.setElement(i, j, a.getElement(i, k) * b.getElement(i, j));  // ��İ��� a�� ��� b�� ���� ������ ���ؼ� �����
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
		r.setRows(m.getCols());     //��ġ����� ����� ��� ���� ���� �ٲ� ����� �������
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
			cout << "��� ���� ���� ���� �ʽ��ϴ�(���� �߻�)" << endl;
		r.setRows(m.getRows());    
		r.setCols(m.getCols());

		float det = 0; // ��Ľ� ���� ������ ����
		Matrix temp(m.getRows(), m.getCols());    //���μ���� �̷���� ����� ������ �迭
		Matrix adjmat(m.getRows() - 1, m.getCols() - 1);  
		for (int i = 0; i < m.getRows(); i++) {

			for (int j = 0; j < m.getCols(); j++) {     				

				int a = 0, b = 0;
				
				for (int g = 0; g < m.getRows(); g++) {  // ���μ� ���� �ϴ� ����
					if (g == i)               //���μ� ������ �ϴ� ���ҿ� ���Ͽ� �� ���Ұ� ���ԵǾ� �ִ� 
						continue;             //��� ���� ���ҵ��� ������ ���ҵ�� �࿭�� ����� ��Ľ� ���� �����
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
				temp.setElement(i, j, pow(-1, i + j) * adjmat.determinant());	  // ���μ� ����� r�� ���� 
			}
		}
		transpose(r, temp);  //���μ� ��� ��ġ
		return r;
	}
	Matrix& inverse(Matrix& r, Matrix& m) {  // ������� ����ϴ� �Լ�
		float det = 0;
		Matrix temp(m.getRows(), m.getCols());  // ��������� ������ ���
		adjoint(temp, m);
		det = m.determinant();
		elemetDiv(r, temp, det);
		return r;
	}

}