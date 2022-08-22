#include "Table.h"
#define TabMaxSize 100

class ArrTable : public Table
{
protected:
	pTR* pRecs; // ������ ��� ������� �������
	int TabSize; // ����. ����.���������� ������� � �������
	int CurrPos; // ����� ������� ������ (��������� � 0)
public:
	ArrTable(int Size = TabMaxSize); // �����������
	~ArrTable(); // ����������
	// �������������� ������
	virtual int IsFull() const { return (DataCount >= TabSize); }; // ���������?
	int GetTabSize() const { return DataCount; };
	// �-�� �������
	// ������
	virtual Key Get_Key(void) const
	{
		return pRecs[DataCount-1]->key;
	};

	virtual int Get_�(void) const
	{
		return pRecs[DataCount-1]->C;
	};

};

