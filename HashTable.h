#pragma once
#include "SortTable.h"

class HashTable : public Table
{
protected:
	virtual int HF(const Key key); 
	// hash-������� (unsigned long) ?
public:
	HashTable() : Table() {} 
	// �����������
};

