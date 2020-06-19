#include "798C.h"

int gcd1(int a, int b)
{
	int nod = 1;
	int tmp;
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == b)  return a;
	if (a == 1 || b == 1) return 1;
	while (a != 0 && b != 0)
	{
		if (a % 2 == 0 && b % 2 == 0)
		{
			nod *= 2;
			a /= 2;
			b /= 2;
			continue;
		}
		if (a % 2 == 0 && b % 2 != 0)
		{
			a /= 2;
			continue;
		}
		if (a % 2 != 0 && b % 2 == 0)
		{
			b /= 2;
			continue;
		}
		if (a > b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		tmp = a;
		a = (b - a) / 2;
		b = tmp;
	}
	if (a == 0) return nod * b;
	else return nod * a;
}

void _798C()
{
	int N;
	std::cin >> N;
	int num = 0, counter = 0, result = 0;
	while (N--)
	{
		int temp;
		std::cin >> temp;
		num = gcd1(num, temp);
		if (temp & 1) counter++;
		else
		{
			result += (counter / 2) + 2 * (counter & 1);
			counter = 0;
		}
	}
	result += (counter / 2) + 2 * (counter & 1);
	std::cout << "YES" << std::endl;
	if (num == 1) std::cout << result << std::endl;
	else std::cout << "0" << std::endl;
}