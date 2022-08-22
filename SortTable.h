#pragma once
#include "ScanTable.h"

class SortTable : public ScanTable
{
protected:

	void InsertSort(); // ���������� ���������
	
public:
	SortTable(int Size = TabMaxSize) : ScanTable(Size) {};// �����������
	SortTable(ScanTable& tab); // �� ��������������� �������
	
	// �������� ������
	virtual int FindRecord(Key k); // ����� ������
	virtual void InsRecord(Key k, int c); // ��������
	virtual void DelRecord(Key k); // ������� ������
};

