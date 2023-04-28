#pragma once

namespace ooplinalg {

// Definition of Matrix
	class Matrix
	{
	public:
		Matrix();
		Matrix(const Matrix& mat);
		Matrix(int rows, int cols);
		~Matrix();

		float getElement(int row, int col) const;
		float** getData() const;
		void setElement(const int row, const int col, float value);
		void setData(const int rows, const int cols, float** data);
		int getRows() const;
		int getCols() const;
		void setRows(const int rows);
		void setCols(const int cols);

		float determinant();

	private:
		float** data;
		int rows;
		int cols;
	};

	// definition of Matrix operations
	Matrix& add(Matrix& r, Matrix& a, Matrix& b);
	Matrix& sub(Matrix& r, Matrix& a, Matrix& b);
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b);

	Matrix& elemetAdd(Matrix& r, Matrix& a, float v);
	Matrix& elemetSub(Matrix& r, Matrix& a, float v);
	Matrix& elemetMul(Matrix& r, Matrix& a, float v);
	Matrix& elemetDiv(Matrix& r, Matrix& a, float v);

	Matrix& transpose(Matrix& r, Matrix& m);
	Matrix& adjoint(Matrix& r, Matrix& m);
	Matrix& inverse(Matrix& r, Matrix& m);
}