#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	bool isValidMatrix = true;
	int M;
	int N;
	double *matrix;
	void Matrix::initMatrix(int M, int N);
	int Matrix::convertToSingle(int M, int N) const;
public:
	Matrix::Matrix();
	Matrix::Matrix(unsigned int nRows, unsigned int nColumns);
	explicit Matrix::Matrix(unsigned int nRows);
	Matrix::~Matrix();
	double Matrix::get(int M, int N) const;
	void Matrix::set(int M, int N, double value);
	int Matrix::getHeight() const;
	int Matrix::getWidht() const;
	bool Matrix::isValid() const;
	Matrix::Matrix(const Matrix &a);

	//Operators
	Matrix& operator = (Matrix a);

};

ostream& operator << (ostream &out, Matrix &matrix);
