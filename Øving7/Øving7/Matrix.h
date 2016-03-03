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
	int Matrix::convertToSingle(int M, int N);
public:
	Matrix::Matrix();
	Matrix::Matrix(unsigned int nRows, unsigned int nColumns);
	explicit Matrix::Matrix(unsigned int nRows);
	Matrix::~Matrix();
	double Matrix::get(int M, int N);
	void Matrix::set(int M, int N, double value);
	int Matrix::getHeight();
	int Matrix::getWidht();
	bool Matrix::isValid() const;
};

ostream& operator << (ostream &out, Matrix matrix);
