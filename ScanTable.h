#include "ArrTable.h"
class ScanTable : public ArrTable
{
public:
	ScanTable(int Size = TabMaxSize) : ArrTable(Size) {}; //конструктор
	// основные методы
	virtual int FindRecord(Key k);//найти запись
	virtual void InsRecord(Key k, int c);//вставить
	virtual void DelRecord(Key k);//удалить запись

	void Set_CurrPos(int i)
	{
		CurrPos = i;
	};

	pTR GetCurrent_pTR()
	{
		return pRecs[CurrPos];
	}

	TR GetCurrent_TR()
	{
		return *pRecs[CurrPos];
	}


	void Print();

};

