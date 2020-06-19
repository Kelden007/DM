#include "271B.h"

void _271B()
{
	int n, m, min(1000000), curr;
	int primes[9593];
	int* prime_to_go = new int[100003];
	for (int i = 0; i <= 9592; i++) primes[i] = 0;
	for (int i = 0; i <= 100003; i++) prime_to_go[i] = 1;
	int k = 0;
	for (long long i = 2; i <= 100003; i++)
	{
		if (prime_to_go[i] != 0)
		{
			primes[k] = i;
			k++;
		}
		for (long long j = i * i; j <= 100003; j += i) prime_to_go[j] = 0;
	}
	k = 0;
	for (int i = 1; i <= 100000; i++)
	{
		prime_to_go[i] = primes[k] - i;
		if (primes[k] - i == 0) k++;
	}
	std::cin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) arr[i] = new int[m];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) std::cin >> arr[i][j];
	for (int i = 0; i < n; i++)
	{
		curr = 0;
		for (int j = 0; j < m; j++)
			curr += prime_to_go[arr[i][j]];
		if (curr < min) min = curr;
	}
	for (int i = 0; i < m; i++)
	{
		curr = 0;
		for (int j = 0; j < n; j++)
			curr += prime_to_go[arr[j][i]];
		if (curr < min) min = curr;
	}
	std::cout << min;
}