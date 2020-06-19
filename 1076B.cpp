#include "1076B.h"

void _1076B()
{
	unsigned long long n, counter = 0;
	bool flag = false;
	std::cin >> n;
	for (unsigned long long i = 2; i * i <= n; ++i)
	{
		if (n % 2 == 0)
		{
			if (flag)
			{
				counter = n / 2;
				std::cout << ++counter;
			}
			else
			{
				counter = n / 2;
				std::cout << counter;
			}
			return;
		}
		else if (n % i == 0)
			n -= i, i = 2, flag = true;
	}
	std::cout << 1;
}