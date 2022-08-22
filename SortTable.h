#pragma once
#include "ScanTable.h"

class SortTable : public ScanTable
{
protected:

	void InsertSort(); // сортировка вставками
	
public:
	SortTable(int Size = TabMaxSize) : ScanTable(Size) {};// конструктор
	SortTable(ScanTable& tab); // из просматриваемой таблицы
	
	// основные методы
	virtual int FindRecord(Key k); // найти запись
	virtual void InsRecord(Key k, int c); // вставить
	virtual void DelRecord(Key k); // удалить запись
};

