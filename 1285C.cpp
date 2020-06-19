#include "1285C.h"

void _1285C()
{
	long long X, max(1), gcd;
	std::cin >> X;
	for (long long i = 1; i * i < X; i++)
	{
		if (X % i == 0)
		{
			gcd = gcd2(i, X / i);
			if (gcd == 1) max = i;
		}
	}
	std::cout << max << " " << (X / max);
}