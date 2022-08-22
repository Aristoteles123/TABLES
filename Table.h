#include "TR.h"
class Table
{
protected:
	int DataCount;
	// количество записей в таблице
	int Efficiency;
	// показатель эффективности выполнения операции
public:
	Table() { DataCount = 0; Efficiency = 0; }
	virtual ~Table() {};

	int Get_DataCount() const { return DataCount; }
	void Set_DataCount(int d) { DataCount = d; }
	int Get_Efficiency() const { return Efficiency; } 
	void Set_Efficiency(int e) { Efficiency = e; }

	int IsEmpty() const { return DataCount == 0; } 
	virtual int IsFull() const = 0; 

	virtual Key Get_Key(void) const = 0;
	// Получить значение ключа текущей записи.
	virtual int Get_С(void) const = 0;
	// Получить указатель на значение текущей записи. (Получить С из текущей записи.)

	virtual int FindRecord(Key k) = 0; 
	// Поиск записи по значению ключа.
	virtual void InsRecord(Key k, int c) = 0; 
	// Вставка записи в таблицу.
	virtual void DelRecord(Key k) = 0; 
	// Удаление записи.
	
};

