#include "Table.h"
#define TabMaxSize 100

class ArrTable : public Table
{
protected:
	pTR* pRecs; // память для записей таблицы
	int TabSize; // макс. возм.количество записей в таблице
	int CurrPos; // номер текущей записи (нумерация с 0)
public:
	ArrTable(int Size = TabMaxSize); // конструктор
	~ArrTable(); // деструктор
	// информационные методы
	virtual int IsFull() const { return (DataCount >= TabSize); }; // заполнена?
	int GetTabSize() const { return DataCount; };
	// к-во записей
	// доступ
	virtual Key Get_Key(void) const
	{
		return pRecs[DataCount-1]->key;
	};

	virtual int Get_С(void) const
	{
		return pRecs[DataCount-1]->C;
	};

};

