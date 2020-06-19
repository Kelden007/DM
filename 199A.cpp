#include "199A.h"

int fib_search(int num, bool pos_flag)
{
	if (pos_flag == true)
	{
		switch (num)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			return 1;
		}
		default:
		{
			int tmp1 = 2;
			int tmp2 = 3;
			if (num == tmp1) return 3;
			if (num == tmp2) return 4;
			int counter = 4;
			while (true)
			{
				tmp1 = tmp1 + tmp2;
				tmp2 = tmp1 + tmp2;
				counter += 2;
				if (num == tmp1) return counter - 1;
				if (num == tmp2) return counter;
			}
			break;
		}
		}
	}
	else
	{
		int tmp1 = 0;
		int tmp2 = 1;
		int counter = 1;
		switch (num)
		{
		case 0:
		{
			return tmp1;
		}
		case 1:
		{
			return tmp2;
		}
		default:
		{
			while (true)
			{
				tmp1 = tmp1 + tmp2;
				tmp2 = tmp1 + tmp2;
				counter += 2;
				if (num == counter - 1) return tmp1;
				if (num == counter) return tmp2;
			}
			break;
		}
		}

	}
}

void _199A()
{
	int a;
	std::cin >> a;
	if (a > 2)
	{
		int fib_num[3];
		int pos_a = fib_search(a, 1);
		fib_num[0] = fib_search(pos_a - 1, 0);
		fib_num[1] = fib_search(pos_a - 3, 0);
		fib_num[2] = fib_search(pos_a - 4, 0);
		std::cout << fib_num[0] << " " << fib_num[1] << " " << fib_num[2];
	}
	else
	{
		switch (a)
		{
		case 0:
		{
			std::cout << "0 0 0";
			break;
		}
		case 1:
		{
			std::cout << "1 0 0";
			break;
		}
		case 2:
		{
			std::cout << "1 1 0";
			break;
		}
		}
	}
}