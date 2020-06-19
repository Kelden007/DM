#include "1108B.h"

void _1108B()
{
	int n, first(1), second(1), gcd(1);
	int del_first[100];
	for (int i = 0; i < 100; i++) del_first[i] = -1;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (arr[i] == arr[j] && i != j && arr[i] > gcd) gcd = arr[i];
	for (int i = 0; i < n; i++) if (arr[i] > first) first = arr[i];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		if (first % arr[i] == 0)
		{
			int k = 0;
			while (del_first[k] != -1)
			{
				if (arr[i] == del_first[k])
				{
					flag = true;
					break;
				}
				k++;
			}
			if (flag == true) continue;
			else del_first[j] = arr[i];
			j++;
		}
	}
	del_first[j] = first;
	for (int i = 0; i < n; i++)
	{
		if (first % arr[i] == 0)
		{
			int j = 0;
			while (del_first[j] != -1)
			{
				if (arr[i] == del_first[j])
				{
					del_first[j] = -2;
					arr[i] = -1;
					break;
				}
				j++;
			}
		}
	}
	if (gcd == first) second = first;
	else for (int i = 0; i < n; i++) if (arr[i] > second) second = arr[i];
	std::cout << first << " " << second;
}