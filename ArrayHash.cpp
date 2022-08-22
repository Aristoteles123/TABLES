#include "ArrayHash.h"

ArrayHash::ArrayHash(int Size, int Step) : HashTable()
{
	pRecs = new pTR[Size];
	TabSize = Size;
	for (int i = 0; i < Size; i++)
	{
		pRecs[i] = NULL;
	}
	HashStep = Step; // шаг вторичного перемешивания
	FreePos = 0; // первая свободная строка, обнаруженная при поиске
	CurrPos = 0; // строка памяти при завершении поиска
	pMark = new TR();
}

int ArrayHash::FindRecord(Key k)
{
	int pos = HF(k);
	
	pos = pos % TabSize;
	int res = -1;
	FreePos = -1;
	Efficiency = 0;
	
	//while (true)
	for(int i = 0; i < TabMaxSize; i++)
	{
		Efficiency++;
		if (pRecs[pos] != NULL)
		{
			if (pRecs[pos]->key == k)
			{
				res = pos;
				break;
			}
			else
			{
				if (pRecs[pos] == pMark)
				{
					if (FreePos == -1) 
					{
						FreePos = pos;
					}
				}
				pos = GetNextPos(pos);
			}
		}
		else
		{
			FreePos = pos;
			break;
		}
	}
	return res;
}

void ArrayHash::InsRecord(Key k, int c)
{

	int find = FindRecord(k);
	
	if (find != -1)
	{
		pRecs[find]->C += c;
	}
	else
	{
		if (!IsFull())
		{
			pRecs[FreePos] = new TR(k, c);
			DataCount++;
		}
		else
		{
			cout << "Таблица заполнена." << endl;
		}
	}
}

void ArrayHash::DelRecord(Key k)
{
	int find = 0;
	find = FindRecord(k);
	if (find == -1)
	{
		cout << "Такой записи нет." << endl;
	}
	else
	{
		delete pRecs[find];
		pRecs[find] = pMark;
		DataCount--;
	}
}

void ArrayHash::Print()
{
	for (int i = 0; i < TabSize; i++)
	{
		if ((pRecs[i] != NULL))
		{
			if ((pRecs[i] != pMark))
			{
				cout << i << "		" << pRecs[i]->key << "		" << pRecs[i]->C << endl;
			}
			else { cout << i << "		" << "УДАЛЕНО" << endl; }
		}
	}
}
