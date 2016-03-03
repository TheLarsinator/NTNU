// Øving7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include "Matrix.h"

using namespace std;

void fillInFibonacciNumber(int result[], int length)
{
	int a = 0;
	int b = 1;
	int temp;

	for (int i = 0; i < length; i++)
	{
		if (i == 0)
			result[i] = 0;
		else if (i == 1)
			result[i] = 1;
		else
		{
			result[i] = a + b;
			temp = a;
			a = b;
			b += temp;
		}
	}
}

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}

void createFibonacci()
{
	cout << "How many fibonacci numbers do you need?" << endl;
	int n;
	cin >> n;
	int *results = new int[n] {};
	fillInFibonacciNumber(results, n);
	printArray(results, n);
	delete[] results;
	results = nullptr;
}

int main()
{
	Matrix A(2, 2);
	Matrix B(2, 2);

	A = B;

	Matrix C(A);
	Matrix D = B;

	cout << A;
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	cout << B;
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	cout << C;
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	cout << D;
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
	}
	system("pause");
    return 0;
}

