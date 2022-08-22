#include "TR.h"
class Table
{
protected:
	int DataCount;
	// ���������� ������� � �������
	int Efficiency;
	// ���������� ������������� ���������� ��������
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
	// �������� �������� ����� ������� ������.
	virtual int Get_�(void) const = 0;
	// �������� ��������� �� �������� ������� ������. (�������� � �� ������� ������.)

	virtual int FindRecord(Key k) = 0; 
	// ����� ������ �� �������� �����.
	virtual void InsRecord(Key k, int c) = 0; 
	// ������� ������ � �������.
	virtual void DelRecord(Key k) = 0; 
	// �������� ������.
	
};

