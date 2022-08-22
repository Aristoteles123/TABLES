#include "ScanTable.h"

int ScanTable::FindRecord(Key k)
{
	int find = -1;
	Efficiency = 0;
	for (int i = 0; i < DataCount; i++)
	{
		Efficiency++;
		if (pRecs[i]->key == k) 
		{
			find = i;
			break;
		}
	}
	return find;
}

void ScanTable::InsRecord(Key k, int c)
{
	int find = 0;
	find = this->FindRecord(k);
	if (find != -1)
	{
		pRecs[find]->C = pRecs[find]->C + c;
	}
	else
	{
		if (!IsFull())
		{
				pRecs[DataCount] = new TR(k, c);
				DataCount++;
		}
		else { cout << "Нет места" << endl; }
	}
}

void ScanTable::DelRecord(Key k)
{
	int find = 0;
	if (this->IsEmpty())
	{
		cout << "Таблица пуста" << endl;
	}
	else
	{
		find = this->FindRecord(k);
		if (find != -1)
		{
			delete pRecs[find];
			pRecs[find] = pRecs[DataCount - 1];
			pRecs[DataCount - 1] = NULL;
			DataCount--;
		}
		else
		{
			cout << "Такой записи нет" << endl;
		}
	}
}

void ScanTable::Print()
{
	for (int i = 0; i < DataCount; i++)
	{
		cout << "	" << pRecs[i]->key << "		" << pRecs[i]->C << endl;
	}
}

