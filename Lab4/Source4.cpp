#include <iostream>
#include <windows.h>
#include <time.h>
#include <typeinfo>	
#include <cmath>
using namespace std;

template <typename T>
class Matrix
{
public:
	Matrix();
	Matrix(int n);
	Matrix(int n, T min, T max);
	Matrix(int n, T min, T max, int afterPoint);
	~Matrix();

	// конструктор копирования
	Matrix(const Matrix& matrix);

	// геттеры
	T GetMin();
	T GetMax();
	T GetValue();
	T GetElement(int rows, int cols);
	T GetFirstNorm();
	T GetInfinitelyNorm();
	T GetEuclodsNorm();
	string GetType();

	// показы матрицы
	void ShowMatrix();
	void ShowTransMatrix();

	// сеттеры
	void SetRows(int rows);
	void SetCols(int rows);
	void SetElement(int rows, int cols, int el);


	// перегрузка операторов
	void operator = (const Matrix& new_matrix);
	Matrix operator + (const Matrix& new_matrix);
	Matrix operator - (const Matrix& new_matrix);
	Matrix operator * (const Matrix& new_matrix);
	Matrix operator *= (const Matrix& new_matrix);
	Matrix Stepen(const Matrix& new_matrix, int n);
private:
	int n;
	T min;
	T** matrix;
	T max;
};

// КОНСТРУКТОРЫ
template <typename T>
Matrix<T>::Matrix()
{
	this->n = 0;
}

template <typename T>
Matrix<T>::Matrix(int n)
{
	this->n = n;
	this->matrix = new T * [n];

	for (int i = 0; i < n; i++)
		matrix[i] = new T[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;

}

template <typename T>
Matrix<T>::Matrix(int n, T min, T max) : Matrix::Matrix(n)
{
	this->min = min;
	this->max = max;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			//matrix[i][j] = this->min + (rand() / (RAND_MAX / (this->max - this->min)));
			matrix[i][j] = ((float)rand() / RAND_MAX) * (this->max - this->min) + this->min;
}

template <typename T>
Matrix<T>::Matrix(int n, T min, T max, int afterPoint) : Matrix::Matrix(n, min, max)
{
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
			matrix[i][j] = round(matrix[i][j] * pow(10, afterPoint)) / pow(10, afterPoint);
}


// КОНСТРУКТОР КОПИРОВАНИЯ
template <typename T>
Matrix<T>::Matrix(const Matrix& new_matrix) : Matrix(new_matrix.n) {
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
			this->matrix[i][j] = new_matrix.matrix[i][j];
}


// ГЕТТЕРЫ
template <typename T>
T Matrix<T>::GetMin() { return this->min; }

template <typename T>
T Matrix<T>::GetMax() { return this->max; }

template <typename T>
T Matrix<T>::GetValue() { return this->n; }

template <typename T>
T Matrix<T>::GetElement(int rows, int cols) {
	if (rows > n || cols > n)
	{
		cout << "ERROR\n";
		return 0;
	}
	else
		return this->matrix[rows--][cols--];
}

template <typename T>
T Matrix<T>::GetFirstNorm() {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = 0; j < n; j++)
			temp += this->matrix[j][i];
		sum = max(temp, sum);
	}
	return sum;
}

template <typename T>
T Matrix<T>::GetInfinitelyNorm() {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = 0; j < n; j++)
			temp += this->matrix[i][j];
		sum = max(temp, sum);
	}
	return sum;
}

template <typename T>
T Matrix<T>::GetEuclodsNorm() {
	int sum = 0;
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
			sum += this->matrix[i][j];
	return sqrt(sum);
}

template <typename T>
string Matrix<T>::GetType() {
	return typeid(this->matrix).name();
}


// СЕТТЕРЫ
template <typename T>
void Matrix<T>::SetRows(int rows) {
	if (rows > this->n)
		cout << "ERROR\n";
	else
		for (int i = 0; i < this->n; i++)
		{
			cout << "Введи элемент [" << rows << "][" << i + 1 << "]";
			cin >> this->matrix[rows - 1][i];
		}
}

template <typename T>
void Matrix<T>::SetCols(int cols) {
	if (cols > this->n)
		cout << "ERROR\n";
	else
		for (int i = 0; i < this->n; i++)
		{
			cout << "Введи элемент [" << i + 1 << "][" << cols << "]";
			cin >> this->matrix[i][cols - 1];
		}
}

template <typename T>
void Matrix<T>::SetElement(int rows, int cols, int el) {
	if (rows > n || cols > n)
		cout << "ERROR\n";
	else
		this->matrix[rows - 1][cols - 1] = el;
}


// ПОКАЗЫ МАТРИЦЫ
template <typename T>
void Matrix<T>::ShowMatrix() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << this->matrix[i][j] << '\t';
		}
		cout << "\n\n";
	}
	cout << '\n';
}

template <typename T>
void Matrix<T>::ShowTransMatrix() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[j][i] << '\t';
		}
		cout << '\n\n';
	}
	cout << '\n';
}


// ПЕРЕГРУЗКИ ОПЕРАТОРОВ
template <typename T>
void Matrix<T>::operator=(const Matrix& new_matrix) {
	if (this->GetValue() != new_matrix.n)
	{
		cout << "Is not equal matrix!\n\n";
		return;
	}
	else {
		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->n; j++)
				this->matrix[i][j] = new_matrix.matrix[i][j];
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& new_matrix) {
	if (this->n != new_matrix.n)
	{
		cout << "ERROR";
		return 0;
	}
	else {
		Matrix<T> temp(this->n);
		for (int i = 0; i < temp.n; i++)
			for (int j = 0; j < temp.n; j++)
				temp.matrix[i][j] = this->matrix[i][j] + new_matrix.matrix[i][j];
		return temp;
	}
}

template <typename T>
Matrix <T>Matrix<T>::operator-(const Matrix& new_matrix) {
	if (this->n != new_matrix.n)
	{
		cout << "ERROR";
		return 0;
	}
	else {
		Matrix <T>temp(this->n);
		for (int i = 0; i < temp.n; i++)
			for (int j = 0; j < temp.n; j++)
				temp.matrix[i][j] = this->matrix[i][j] - new_matrix.matrix[i][j];
		return temp;
	}
}

template <typename T>
Matrix <T>Matrix<T>::operator*(const Matrix& new_matrix) {
	if (this->n != new_matrix.n)
	{
		cout << "ERROR";
		return 0;
	}
	else {
		Matrix<T> temp(this->n);
		for (int i = 0; i < this->n; i++)
			for (int j = 0; j < this->n; j++)
				for (int k = 0; k < n; k++)
					temp.matrix[i][j] += this->matrix[i][k] * new_matrix.matrix[k][j];
		return temp;
	}
}

template <typename T>
Matrix <T>Matrix<T>::Stepen(const Matrix& new_matrix, int n) {
	Matrix <T>temp(new_matrix);
	if (n <= 1)
		cout << "ERROR\n";
	else
		for (int i = 0; i < n - 1; i++)
			temp = temp * new_matrix;

	return temp;
}

// ДЕСТРУКТОР
template <typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < n; i++)
		delete[]this->matrix[i];
	delete[]this->matrix;
}


int main() {
	srand(time(NULL));
	Matrix <float> A (5, 1, 10, 3);
	Matrix <float> B (5, 1, 10, 3);
	A.ShowMatrix();
	cout << endl;
	B.ShowMatrix();
	cout << endl;

	Matrix <float> C = B - A;
	C.ShowMatrix();
	cout << C.GetType();
	cout << endl;
	return 0;
	system("pause");
}
