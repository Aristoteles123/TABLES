#pragma once
#include "HashTable.h"

#define TabMaxSize 100
#define TabHashStep 3

class ArrayHash : public HashTable
{
protected:
	pTR* pRecs; // ������ ��� ������� �������
	int TabSize; // ����. ����. �-�� �������
	int HashStep; // ��� ���������� �������������
	int FreePos; // ������ ��������� ������, ������������ ��� ������
	int CurrPos; // ������ ������ ��� ���������� ������
	pTR pMark; // ������ ��� ��������� ����� � ���������� ��������
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }; // ����. �����.
public:
	ArrayHash(int Size = TabMaxSize, int Step = TabHashStep); // �����������
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
	// �������������� ������
	virtual int IsFull() const { return (DataCount >= TabSize); }; // ���������?
// ������
	virtual Key Get_Key(void) const { return ""; };
	virtual int Get_�(void) const { return 0; };
	virtual pTR GetValuePTR(void) const { return NULL; };
	// �������� ������
	virtual int FindRecord(Key k); // ����� ������
	virtual void InsRecord(Key k, int c); // ��������
	virtual void DelRecord(Key k); // ������� ������
	// ���������
	virtual int Reset(void) { return 0; }; // ���������� �� ������ ������
	virtual int IsTabEnded(void) const { return 0; }; // ������� ���������?
	virtual int GoNext(void) { return 0; }; // ������� � ��������� ������
	//(=1 ����� ���������� ��� ��������� ������ �������)
	void Print();
};

