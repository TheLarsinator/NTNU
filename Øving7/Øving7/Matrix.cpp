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

int Matrix::convertToSingle(int M, int N) const
{
	return (M * this->N) + N;
	//return (M - 1)*N + N - 1;
}


//Gets and sets
double Matrix::get(int M, int N) const
{
	return matrix[convertToSingle(M, N)];
}

void Matrix::set(int M, int N, double value)
{
	matrix[convertToSingle(M, N)] = value;
}

int Matrix::getHeight() const
{
	return M;
}

int Matrix::getWidht() const
{
	return N;
}

bool Matrix::isValid() const
{
	return isValidMatrix;
}

//Operators
ostream& operator << (ostream &out, Matrix &matrix)
{
	if (matrix.isValid())
	{
		for (unsigned int i = 0; i < matrix.getHeight(); i++)
		{
			for (unsigned int j = 0; j < matrix.getWidht(); j++)
			{
				out << matrix.get(i, j);

				if (j == matrix.getWidht() - 1)
					out << endl;
				else
					out << '\t';
			}
		}
		return out;
	}
	else
	{
		out << "Invalid matrix!" << endl;
		return out;
	}
}

Matrix& Matrix::operator = (Matrix a)
{
	swap(this->M, a.M);
	swap(this->N, a.N);
	swap(this->matrix, a.matrix);
	swap(this->isValidMatrix, a.isValidMatrix);
	return *this;
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
	double value;
	initMatrix(M, N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "Fill in position: " << i << ", " << j << endl;
			cin >> value;
			set(i, j, value);
		}
	}
}

Matrix::Matrix(unsigned int nRows)
{
	M = nRows;
	N = nRows;
	this->initMatrix(M, N);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				set(i, j, 1);
		}
	}

}

Matrix::Matrix(const Matrix &a)
{
	this->isValidMatrix = a.isValid();
	this->M = a.getHeight();
	this->N = a.getWidht();
	initMatrix(M, N);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			this->set(i, j, a.get(i, j));
		}
	}
}

Matrix::~Matrix()
{
	delete[] matrix;
	matrix = nullptr;
}