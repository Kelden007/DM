#include "72G.h"

int cache[100];

int fibo(int n)
{
	if (cache[n] == 0)
	{
		if (n == 0)
			cache[n] = 0;
		else if (n == 1 || n == 2)
			cache[n] = 1;
		else
			cache[n] = fibo(n - 1) + fibo(n - 2);
	}
	return cache[n];
}

int Fib(int place)
{
	int old_value = 0;
	int value = 1;
	int temp;
	if (place < 1)
		return 0;
	for (int n = 1; n < place; ++n)
	{
		temp = value;
		value += old_value;
		old_value = temp;
	}
	return value;
}

int fib(int n)
{
	switch (n)
	{
	case 0:
		return 1;
	case 1:
		return 1;
	default:
		return fib(n - 1) + fib(n - 2);
	}
}

void _72G()
{
	int n;
	std::cin >> n;
	std::cout << fib(n);
}