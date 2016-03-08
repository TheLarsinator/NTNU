#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <fstream>

using namespace std;

char convertToEnglishLetter(char car)
{
	if (tolower(car) == 'æ')
		return 'e';
	if (tolower(car) == 'ø')
		return 'o';
	if (tolower(car) == 'å')
		return 'a';
	else
		return car;
}

void printMap(map<string, int> list)
{
	map<string, int>::const_iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++)
	{
		cout << iter->first << '\t' << iter->second << endl;
	}
}

void countWords()
{
	char car;
	
	int words = 0;
	map<string, int> word;
	int currentWordLength = 0;
	int longestWordLength = 0;
	string longestWord;
	int numberOfWords = 0;
	int numberOfLines = 0;
	string tempChar;
	int average = 0;

	ifstream file("C:/Users/Lars/Desktop/Lars.txt");
	if (file.is_open())
	{
		while (file.get(car))
		{
			car = tolower(car);
			car = convertToEnglishLetter(car);
			if (isalpha(car))
			{
				currentWordLength++;
				tempChar += car;
				average++;
			}
			if (isblank(car) || car == '\n' || car == '.')
			{
				//En mellomrom så enden på et ord
				numberOfWords++;
				if (tempChar != "")
					word[tempChar] += 1;
				if (currentWordLength > longestWordLength)
				{
					longestWordLength = currentWordLength;
					longestWord = tempChar;
				}
				if (car == '\n')
					numberOfLines++;

				currentWordLength = 0;
				tempChar = "";
			}
		}
		if (tempChar != "")
		{
			//En mellomrom så enden på et ord
			numberOfWords++;
			word[tempChar] += 1;
			if (currentWordLength > longestWordLength)
			{
				longestWordLength = currentWordLength;
				longestWord = tempChar;
			}
			currentWordLength = 0;
			tempChar = "";
		}

		file.close();
	}

	cout << "Text stats" << endl;
	cout << "Longest word: " << longestWord << endl;
	cout << "Length of longest word: " << longestWordLength << endl;
	cout << "Number of words: " << numberOfWords << endl;
	cout << "Number of lines: " << numberOfLines << endl;
	cout << "Gjennomsnitlig ordlengde: " << average / numberOfWords << endl;
	printMap(word);
}

