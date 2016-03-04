// Øving8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

void printWordsToFile()
{
	string str = "";
	string word;
	cin >> word;
	while (word != "quit")
	{
		str += word + '\n';
		cin >> word;
	}

	ofstream file;
	file.open("C:/Users/Lars/Desktop/Lars.txt");
	if (file.fail())
	{
		cout << "Error!" << endl;
		exit(1);
	}
		
	
	cout << str;
	file << str;
	file.close();
}

void readLinesFromFile()
{
	string line;
	int i = 0;
	ifstream file("C:/Users/Lars/Desktop/Lars.txt");
	ofstream outFile;
	outFile.open("C:/Users/Lars/Desktop/Mads.txt");
	if (file.is_open() && !outFile.fail())
	{
		while (getline(file, line))
		{
			i++;
			outFile << i << '\t' << line << endl;
		}
		file.close();
		outFile.close();
	}
}

void printOccurenceOfLetters()
{
	int stats[26] = {};
	
	char car;
	int i = 0;
	ifstream file("C:/Users/Lars/Desktop/Lars.txt");
	if (file.is_open())
	{
		while(file >> noskipws >> car)
		{
			stats[tolower(car) - 'a'] += 1;
		}
		file.close();
	}
	char letter = 'a';
	for (int i = 0; i < 26; i++)
	{
		cout << char(letter + i) << ": " << stats[i] << '\t';
		if (i % 3 == 0 && i != 0)
			cout << endl;
	}
}


int main()
{
	printWordsToFile();
	system("pause");
	readLinesFromFile();
	system("pause");
	printOccurenceOfLetters();
	system("pause");

    return 0;
}

