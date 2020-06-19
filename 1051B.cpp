#include "1051B.h"

void _1051B()
{
	long long l, r;
	std::cin >> l >> r;
	if (l != r)
	{
		std::cout << "YES" << std::endl;
		for (long long i = l; i <= r; i += 2) std::cout << i << " " << i + 1 << std::endl;
	}
	else std::cout << "NO";
}