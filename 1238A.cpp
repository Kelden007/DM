#include "1238A.h"

void _1238A()
{
	int t;
	long long x, y;
	std::cin >> t;
	bool* arr = new bool[t];
	for (int i = 0; i < t; i++)
	{
		std::cin >> x >> y;
		long long razn = x - y;
		if (razn == 1) arr[i] = 0;
		else arr[i] = 1;
	}
	for (int i = 0; i < t; i++)
	{
		if (arr[i] == 1) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
}