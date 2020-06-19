#include "858A.h"

void _858A()
{
	int k; long long n, kn;
	std::cin >> n >> k;
	long long inc = 1;
	for (int i = 0; i < k; i++) inc *= 10;
	kn = n * inc / gcd2(n, inc);
	std::cout << kn;
}