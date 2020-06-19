#include "630J.h"

void _630J()
{
	long long lcm(1), n;
	std::cin >> n;
	for (long long i = 2; i <= 10; i++) lcm = lcm * i / gcd2(lcm, i);
	std::cout << n / lcm;
}