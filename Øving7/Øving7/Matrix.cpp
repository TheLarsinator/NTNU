#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>

#include "Matrix.h"

using namespace std;

//Private functions
void Matrix::initMatrix(int M, int N)
{
	matrix = new double[M*N]{};
}

int Matrix::convertToSingle(int M, int N)
{
	return (M - 1)*N + N - 1;
}


//Gets and sets
double Matrix::get(int M, int N)
{
	return matrix[convertToSingle(M, N)];
}

void Matrix::set(int M, int N, double value)
{
	matrix[convertToSingle(M, N)] = value;
}

int Matrix::getHeight()
{
	return M;
}

int Matrix::getWidht()
{
	return N;
}

bool Matrix::isValid() const
{
	return isValidMatrix;
}

//Operators
ostream& operator << (ostream &out, Matrix matrix)
{
	int counter = 0;
	for (int i = 0; i < matrix.getHeight; i++)
	{
		for (int j = 0; j < matrix.getWidht; j++)
		{
			out << matrix.get(i, j);
			counter++;
			if (counter == matrix.getWidht - 1)
				out << endl;
		}
	}
	return out;
}

//Constructors and destructor
Matrix::Matrix()
{
	isValidMatrix = false;
}

Matrix::Matrix(unsigned int nRows, unsigned int nColumns)
{
	M = nRows;
	N = nColumns;
	initMatrix(M, N);
}

Matrix::Matrix(unsigned int nRows)
{
	M, N = nRows;
	initMatrix(M, N);
}

Matrix::~Matrix()
{
	delete[] matrix;
	matrix = nullptr;
}