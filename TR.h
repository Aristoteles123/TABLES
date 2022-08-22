#pragma once
#include <iostream>
#include <istream>
#include <clocale>
#include <string>

using namespace std;

typedef string Key;

class TR
{
	Key key;
	int C;
public:
	TR();
	TR(Key k, int c);
	TR& operator=(const TR& t);
	int operator == (const TR& t);
	int operator > (const TR& t);
	int operator < (const TR& t);

	void Set_key(Key k) { key = k; };
	Key Get_key() { return key; };
	void Set_C(int c) { C = c; };
	int Get_C() { return C; };

	friend class Table;
	friend class ArrTable;
	friend class ScanTable;
	friend class SortTable;
	friend class ArrayHash;
};

typedef TR* pTR;

