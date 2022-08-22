#include "SortTable.h"

void SortTable::InsertSort()
{
    Key tmp_k = "";
    int tmp_c = 0;
    for (int i = 0; i < DataCount; i++)
    {
        Efficiency++;
        for (int j = i; ( j > 0 )&&(pRecs[j-1]->key > pRecs[j]->key ); j--)
        {
            tmp_k = pRecs[j - 1]->key;
            tmp_c = pRecs[j - 1]->C;

            pRecs[j - 1]->key = pRecs[j]->key;
            pRecs[j - 1]->C = pRecs[j]->C;

            pRecs[j]->key = tmp_k;
            pRecs[j]->C = tmp_c;

            //Efficiency++;
        }
    }
}

SortTable::SortTable(ScanTable& tab)
{
    int dc = tab.Get_DataCount();
    for (int i = 0; i < dc; i++)
    {
        tab.Set_CurrPos(i);
        this->pRecs[i] = new TR(tab.GetCurrent_pTR()->key, tab.GetCurrent_pTR()->C);
        DataCount++;
    }
    InsertSort();
}

int SortTable::FindRecord(Key k)
{
    // Бинарный поиск

    Efficiency = 0;
    int find = -1;
    int L = 0;
    int R = DataCount - 1;
    int M;

    while (L <= R)
    {
        Efficiency++;
        M = (R + L) / 2;
        if (k > pRecs[M]->key)
        {
            L = M + 1;
        }
        else if (k < pRecs[M]->key)
        {
            R = M - 1;
        }
        else
        {
            find = M;
            break;
        }
    }

    return find;
}

void SortTable::InsRecord(Key k, int c)
{
    int find = 0;
    find = this->FindRecord(k);
    if (find != -1)
    {
        pRecs[find]->C = pRecs[find]->C + c;
    }
    else
    {
        if (!IsFull())
        {
                pRecs[DataCount] = new TR(k, c);
                DataCount++;
                InsertSort();
        }
        else { cout << "Нет места" << endl; }
    } 
}

void SortTable::DelRecord(Key k)
{
    int find = 0;
    if (this->IsEmpty())
    {
        cout << "Таблица пуста" << endl;
    }
    else
    {
        find = this->FindRecord(k);
        if (find != -1)
        {
            delete pRecs[find];

            for (int i = find; i < DataCount - 1; i++)
            {
                Efficiency++;
                pRecs[i] = pRecs[i + 1];
            }

            pRecs[DataCount - 1] = NULL;
            DataCount--;
        }
        else
        {
            cout << "Такой записи нет" << endl;
        }
    }
}

