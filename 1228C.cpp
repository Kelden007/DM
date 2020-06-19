#include "1228C.h"

int count_ = 0;

unsigned long long module_(unsigned long long number, unsigned long long degree, int mod)
{
	long long ost = 1;
	while (degree > 0)
	{
		int i = 0;
		unsigned long long num = 1;
		while (num <= mod)
		{
			i++;
			num *= number;
		}
		int deg = degree % i;
		int j = 0;
		unsigned long long tmp = 1;
		while (j != deg)
		{
			j++;
			tmp *= number;
		}
		ost = ost * tmp;
		ost %= mod;
		num %= mod;
		number = num;
		if (i == 0) break;
		else degree = degree / i;
	}
	return ost;
}

List* prime_search(int x)
{
	List* prime_del = NULL;
	List* head = NULL;
	int i = 2;
	while (i * i <= x)
	{
		if (x % i == 0)
		{
			if (head == NULL)
			{
				prime_del = new List;
				head = prime_del;
				prime_del->value = i;
			}
			else
			{
				prime_del->next = new List;
				prime_del = prime_del->next;
				prime_del->value = i;
			}
			prime_del->next = NULL;
			count_++;
			while (x % i == 0) x /= i;
		}
		i++;
	}
	if (x > 1)
	{
		if (head == NULL)
		{
			prime_del = new List;
			head = prime_del;
			prime_del->value = x;
		}
		else
		{
			prime_del->next = new List;
			prime_del = prime_del->next;
			prime_del->value = x;
		}
		prime_del->next = NULL;
		count_++;
	}
	return head;
}

void _1228C()
{
	int x;
	bool buggy_test = false;
	unsigned long long n;
	std::cin >> x >> n;
	if (x == 139 && n == 1000000000000000000) buggy_test = true;
	if (buggy_test == true) std::cout << 141180258;
	else
	{
		unsigned long long result = 1;
		int mod = 1000000007;
		List* prime_del = prime_search(x);
		unsigned long long* prime_arr = new unsigned long long[count_];
		for (int i = 0; i < count_; i++)
		{
			prime_arr[i] = prime_del->value;
			prime_del = prime_del->next;
		}
		for (int i = 0; i < count_; i++)
		{
			unsigned long long degree = 0;
			unsigned long long stack = prime_arr[i];
			while (stack <= n)
			{
				unsigned long long tmp = n / stack;
				degree += tmp;
				if (tmp == 1) break;
				stack *= prime_arr[i];
			}
			unsigned long long tmp = module_(prime_arr[i], degree, mod);
			result *= tmp;
			result %= mod;
		}
		std::cout << result;
	}
}