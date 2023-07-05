#include <stdio.h>
#include "my_lists.h"

long int seed = 1;

int pseudorandom()
{
	int a = 16807;
	int m = 0x7fffffff;

	seed = seed * a % m;
	return seed;
}