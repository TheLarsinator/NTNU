#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class CC{
private:
	map<string, string> catalog;
public:
	CC::CC();
	string CC::get(string subject);
	void CC::set(string subject, string value);
	void CC::eraseFromCatalog(string subject);
	void CC::printCatalog();
	friend ostream& operator << (ostream &out, CC &CC);
};

