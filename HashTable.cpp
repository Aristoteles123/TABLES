#include "HashTable.h"

int HashTable::HF(const Key key)
{
	int i = 0;
	int summ = 0;
	while (key[i] != '\0')
	{
		summ = summ + abs((int)(key[i]));
		i++;
	}
	return summ;
}
