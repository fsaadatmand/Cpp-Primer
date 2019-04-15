#include "Chapter6.h"

int fact(int val)
{
	int result = 1;
	while (val > 1)
		result *= val--;
	return result;
}
