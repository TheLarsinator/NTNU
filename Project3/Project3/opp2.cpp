#include <iostream>

using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int fibonacci(int n)
{
	int a = 0;
	int b = 1;
	int temp;
	for (int x = 1; x < n + 1; x++)
	{
		temp = b;
		b += a;
		a = temp;
	}
	return b;
}

int squareNumberSum(int n)
{
	int totalSum = 0;
	for (int i = 0; i <= n; i++)
	{
		totalSum += i*i;
	}
	return totalSum;
}



void main()
{
	cout << "Oppgave a)" << endl;
	cout << max(5, 6) << endl;
}