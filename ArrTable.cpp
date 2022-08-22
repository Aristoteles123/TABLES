#include "ArrTable.h"

ArrTable::ArrTable(int Size) : Table()
{
	
	pRecs = new pTR[Size];
	TabSize = Size;
	CurrPos = 0;
	for (int i = 0; i < Size; i++)
	{
		pRecs[i] = NULL;
	}
	
}

ArrTable::~ArrTable()
{
	for (int i = 0; i++; i < DataCount)
	{
		delete pRecs[i];
	}
	delete[] pRecs;
}




