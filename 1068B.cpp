#include "1068B.h"

void _1068B()
{
	long long b;
	int counter = 0;
	std::cin >> b;
	for (long long i = 1; i * i <= b; i++)
	{
		if (b % i == 0)
			counter += 2;
		if (i * i == b)
			counter--;
	}
	std::cout << counter;
}