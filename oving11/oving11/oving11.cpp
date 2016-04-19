// oving11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include "SimpleSet.h"

using namespace std;
void replaceInVector(vector<string> &vec1, const string &oldString, const string &newString)
{
	for (vector<string>::iterator it = vec1.begin(); it != vec1.end(); ++it)
	{
		if (*it == oldString)
		{
			it = vec1.erase(it);
			it = vec1.insert(it, newString);
		}
	} 
}

void removeNumbers(set<int> &tall, int number)
{
	for (set<int>::iterator it = tall.begin(); it != tall.end();)
	{
		if (*it % number == 0 && *it != number)
		{
			it = tall.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void removeFromSet(SimpleSet<int> set, int maxSize, int number)
{
	if (set.exists(number))
	{
		
	}
}

void printSet(set<int> tall)
{
	for (set<int>::iterator it = tall.begin(); it != tall.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main()
{
	cout << "Start" << endl;

	SimpleSet<int> seta(10);
	for (int i = 0; i < 19; i++)
	{
		seta.insert(i);
	}
	seta.print();
	cout << "Exists: " << seta.exists(1) << endl;
	seta.remove(1);
	seta.remove(2);
	seta.print();
	cout << "Exists: " <<seta.exists(1) << endl;

	system("pause");
	return 0;
}

