#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Matrix
{
public:
	Matrix();
	Matrix(int n);
	Matrix(int n, int min, int max);

	Matrix(const Matrix& matrix);

	int GetMin();
	int GetMax();
	int GetValue();
	int GetElement(int rows, int cols);
	int GetFirstNorm();
	int GetInfinitelyNorm();
	string GetStringMatrix();
	int GetEuclodsNorm();

	void ShowMatrix();
	void ShowTransMatrix();

	void SetRows(int rows);
	void SetCols(int rows);
	void SetElement(int rows, int cols, int el);


	void operator = (const Matrix& new_matrix);
	Matrix operator + (const Matrix& new_matrix);
	Matrix operator - (const Matrix& new_matrix);
	Matrix operator * (const Matrix& new_matrix);
	Matrix Stepen(const Matrix& new_matrix, int n);
	int* operator[](int index);
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
	friend std::istream& operator>> (std::istream& in, Matrix& matrix);
	~Matrix();

private:
	int n;
	int min, max;
	int** matrix;
};


