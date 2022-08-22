#include "TR.h"

TR::TR()
{
	key = "";
	C = 0;
}

TR::TR(Key k, int c)
{
	key = k;
	C = c;
}

TR& TR::operator=(const TR& t)
{
	key = t.key;
	C = t.C;
	return *this;
}

int TR::operator==(const TR& t)
{
	return key == t.key;
}

int TR::operator>(const TR& t)
{
	return key > t.key;
}

int TR::operator<(const TR& t)
{
	return key < t.key;
}
