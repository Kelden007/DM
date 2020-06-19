#include "1349A.h"

long long gcd2(long long a, long long b)
{
	while (true)
	{
		if (a == 0) return b;
		if (b == 0) return a;
		if (a >= b) a = a % b;
		else b = b % a;
	}
}

void _1349A()
{
	int n;
	std::cin >> n;
	long long* arr = new long long[n];
	long long* prev_gcd = new long long[n];
	long long* post_gcd = new long long[n];
	long long* new_gcd = new long long[n];

	for (int i = 0; i < n; i++) std::cin >> arr[i];
	prev_gcd[0] = arr[0];
	post_gcd[n - 1] = arr[n - 1];

	for (int i = 1; i < n; i++) prev_gcd[i] = gcd2(prev_gcd[i - 1], arr[i]);
	for (int i = n - 2; i >= 0; i--) post_gcd[i] = gcd2(post_gcd[i + 1], arr[i]);
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || i == n - 1)
		{
			if (i == 0) new_gcd[i] = post_gcd[i + 1];
			if (i == n - 1) new_gcd[i] = prev_gcd[i - 1];
		}
		else new_gcd[i] = gcd2(prev_gcd[i - 1], post_gcd[i + 1]);
	}
	long long result = new_gcd[0];
	for (int i = 0; i < n - 1; i++) result = result * new_gcd[i + 1] / gcd2(result, new_gcd[i + 1]);
	std::cout << result;
}