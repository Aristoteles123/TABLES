#include <fstream>
#include "SortTable.h"
#include "ArrayHash.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	ScanTable ScanT;
	ArrayHash Hash;

	string path = "My_File.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "������ �������� �����." << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
		string str;
		while (!fin.eof())
		{
			str = "";
			fin >> str;
			if (str != "")
			{
				ScanT.InsRecord(str, 1);
				Hash.InsRecord(str, 1);
				
			}
		}
	}
	fin.close();

	// ��ר� 
	// ->

	
	SortTable SortT(ScanT);
	cout << "��������������� �������:" << endl; 
	ScanT.Print();
	cout << endl;
	cout << "������������ �������:" << endl;
	SortT.Print();
	cout << endl;
	cout << "���-�������:" << endl;
	Hash.Print();
	cout << endl;

	cout << "����� �������������� ������:" << endl;
	cout << endl;

			cout << "	" << "������������� ��� �����. �������:	";
			ScanT.FindRecord("q");
			cout << ScanT.Get_Efficiency() << endl;

			cout << "	" << "������������� ��� ����. �������:	";
			SortT.FindRecord("q");
			cout << SortT.Get_Efficiency() << endl;

			cout << "	" << "������������� ��� ���-�������:		";
			Hash.FindRecord("q");
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "������� ����� ������:" << endl;
	cout << endl;

			ScanT.InsRecord("������", 1);
			cout << "	" << "������������� ��� �����. �������:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.InsRecord("������", 1);
			cout << "	" << "������������� ��� ����. �������:	";
			cout << SortT.Get_Efficiency() << "	(��������� ����������)" << endl;

			cout << "	" << "������������� ��� ���-�������:		";
			Hash.InsRecord("������", 1);
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "������� ������������ ������:" << endl;
	cout << endl;

			ScanT.InsRecord("����", 10000);
			cout << "	" << "������������� ��� ��������������� �������:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.InsRecord("����", 10000);
			cout << "	" << "������������� ��� ������������� �������:	";
			cout << SortT.Get_Efficiency() << endl;

			cout << "	" << "������������� ��� ���-�������:			";
			Hash.InsRecord("����", 10000);
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "�������� �������������� ������:" << endl;
	cout << endl;

			ScanT.DelRecord("q");
			cout << "	" << "������������� ��� ��������������� �������:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.DelRecord("q");
			cout << "	" << "������������� ��� ������������� �������:	";
			cout << SortT.Get_Efficiency() << endl;

			Hash.DelRecord("q");
			cout << "	" << "������������� ��� ���-�������:			";
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "�������� ������������ ������:" << endl;
	cout << endl;

			ScanT.DelRecord("�����");
			cout << "	" << "������������� ��� ��������������� �������:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.DelRecord("�����");
			cout << "	" << "������������� ��� ������������� �������:	";
			cout << SortT.Get_Efficiency() << "	(�����������)" << endl;

			cout << "	" << "������������� ��� ���-�������:			";
			Hash.DelRecord("�����");
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "��������������� �������:" << endl;
	ScanT.Print();
	cout << endl;
	cout << "������������ �������:" << endl;
	SortT.Print();
	cout << endl;
	cout << "���-�������:" << endl;
	Hash.Print();
	cout << endl;

	// <-

	return 0;
}
