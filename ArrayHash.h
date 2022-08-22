#pragma once
#include "HashTable.h"

#define TabMaxSize 100
#define TabHashStep 3

class ArrayHash : public HashTable
{
protected:
	pTR* pRecs; // память для записей таблицы
	int TabSize; // макс. возм. к-во записей
	int HashStep; // шаг вторичного перемешивания
	int FreePos; // первая свободная строка, обнаруженная при поиске
	int CurrPos; // строка памяти при завершении поиска
	pTR pMark; // маркер для индикации строк с удаленными записями
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }; // откр. перем.
public:
	ArrayHash(int Size = TabMaxSize, int Step = TabHashStep); // конструктор
	~ArrayHash() 
	{
		for (int i = 0; i < TabSize; i++)
		{
			if ((pRecs[i] != NULL))
			{
				if ((pRecs[i] != pMark))
					delete pRecs[i];
			}
		}
		delete pMark;
		delete[] pRecs;
	};
	// информационные методы
	virtual int IsFull() const { return (DataCount >= TabSize); }; // заполнена?
// доступ
	virtual Key Get_Key(void) const { return ""; };
	virtual int Get_С(void) const { return 0; };
	virtual pTR GetValuePTR(void) const { return NULL; };
	// основные методы
	virtual int FindRecord(Key k); // найти запись
	virtual void InsRecord(Key k, int c); // вставить
	virtual void DelRecord(Key k); // удалить запись
	// навигация
	virtual int Reset(void) { return 0; }; // установить на первую запись
	virtual int IsTabEnded(void) const { return 0; }; // таблица завершена?
	virtual int GoNext(void) { return 0; }; // переход к следующей записи
	//(=1 после применения для последней записи таблицы)
	void Print();
};

