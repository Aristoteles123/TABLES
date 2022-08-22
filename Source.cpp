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
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
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

	// ОТЧЁТ 
	// ->

	
	SortTable SortT(ScanT);
	cout << "Просматриваемая таблица:" << endl; 
	ScanT.Print();
	cout << endl;
	cout << "Сортировання таблица:" << endl;
	SortT.Print();
	cout << endl;
	cout << "Хеш-таблица:" << endl;
	Hash.Print();
	cout << endl;

	cout << "ПОИСК НЕСУЩЕСТВУЮЩЕЙ ЗАПИСИ:" << endl;
	cout << endl;

			cout << "	" << "Эффективность для ПРОСМ. таблицы:	";
			ScanT.FindRecord("q");
			cout << ScanT.Get_Efficiency() << endl;

			cout << "	" << "Эффективность для СОРТ. таблицы:	";
			SortT.FindRecord("q");
			cout << SortT.Get_Efficiency() << endl;

			cout << "	" << "Эффективность для ХЕШ-таблицы:		";
			Hash.FindRecord("q");
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "ВСТАВКА НОВОЙ ЗАПИСИ:" << endl;
	cout << endl;

			ScanT.InsRecord("ноябрь", 1);
			cout << "	" << "Эффективность для ПРОСМ. таблицы:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.InsRecord("ноябрь", 1);
			cout << "	" << "Эффективность для СОРТ. таблицы:	";
			cout << SortT.Get_Efficiency() << "	(повторная сортировка)" << endl;

			cout << "	" << "Эффективность для ХЕШ-таблицы:		";
			Hash.InsRecord("ноябрь", 1);
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "ВСТАВКА СУЩЕСТВУЮЩЕЙ ЗАПИСИ:" << endl;
	cout << endl;

			ScanT.InsRecord("июль", 10000);
			cout << "	" << "Эффективность для просматриваемой таблицы:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.InsRecord("июль", 10000);
			cout << "	" << "Эффективность для сортированной таблицы:	";
			cout << SortT.Get_Efficiency() << endl;

			cout << "	" << "Эффективность для ХЕШ-таблицы:			";
			Hash.InsRecord("июль", 10000);
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "УДАЛЕНИЕ НЕСУЩЕСТВУЮЩЕЙ ЗАПИСИ:" << endl;
	cout << endl;

			ScanT.DelRecord("q");
			cout << "	" << "Эффективность для просматриваемой таблицы:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.DelRecord("q");
			cout << "	" << "Эффективность для сортированной таблицы:	";
			cout << SortT.Get_Efficiency() << endl;

			Hash.DelRecord("q");
			cout << "	" << "Эффективность для ХЕШ-таблицы:			";
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "УДАЛЕНИЕ СУЩЕСТВУЮЩЕЙ ЗАПИСИ:" << endl;
	cout << endl;

			ScanT.DelRecord("абвгд");
			cout << "	" << "Эффективность для просматриваемой таблицы:	";
			cout << ScanT.Get_Efficiency() << endl;

			SortT.DelRecord("абвгд");
			cout << "	" << "Эффективность для сортированной таблицы:	";
			cout << SortT.Get_Efficiency() << "	(перепаковка)" << endl;

			cout << "	" << "Эффективность для ХЕШ-таблицы:			";
			Hash.DelRecord("абвгд");
			cout << Hash.Get_Efficiency() << endl;

			cout << endl;

	cout << "Просматриваемая таблица:" << endl;
	ScanT.Print();
	cout << endl;
	cout << "Сортировання таблица:" << endl;
	SortT.Print();
	cout << endl;
	cout << "Хеш-таблица:" << endl;
	Hash.Print();
	cout << endl;

	// <-

	return 0;
}
