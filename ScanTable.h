#include "ArrTable.h"
class ScanTable : public ArrTable
{
public:
	ScanTable(int Size = TabMaxSize) : ArrTable(Size) {}; //�����������
	// �������� ������
	virtual int FindRecord(Key k);//����� ������
	virtual void InsRecord(Key k, int c);//��������
	virtual void DelRecord(Key k);//������� ������

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

