#include "1350A.h"

void _1350A()
{
	int t, n, k;
	std::cin >> t;
	int* arr = new int[t];
	for (int i = 0; i < t; i++)
	{
		std::cin >> n >> k;
		if (n % 2 == 0) arr[i] = n + 2 * k;
		else
		{
			bool flag = false;
			for (int i = 3; i * i <= n; i += 2)
			{
				if (n % i == 0)
				{
					n += i;
					flag = true;
					break;
				}
			}
			if (flag == false) n *= 2;
			n = n + 2 * (k - 1);
			arr[i] = n;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < t; i++) std::cout << arr[i] << std::endl;
}