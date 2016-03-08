#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include "CourseCatalog.h"

CC::CC()
{

}

string CC::get(string subject)
{
	return catalog[subject];
}

void CC::set(string subject, string value)
{
	catalog[subject] = value;
}

void CC::eraseFromCatalog(string subject)
{
	catalog[subject].erase();
}

void CC::printCatalog()
{
	map<string, string>::const_iterator iter;
	for (iter = catalog.begin(); iter != catalog.end(); iter++)
	{
		cout << iter->first << '\t' << iter->second << endl;
	}
}

ostream& operator << (ostream &out, CC &CC)
{
	map<string, string>::const_iterator iter;
	for (iter = CC.catalog.begin(); iter != CC.catalog.end(); iter++)
	{
		out << iter->first << '\t' << iter->second << endl;
	}
	return out;
}