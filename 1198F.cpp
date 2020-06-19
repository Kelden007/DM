#include "1198F.h"

const int max_n = 100001;
int arr[max_n], index[max_n], result[max_n];

void _1198F()
{
	int n;
	srand(232142414);
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		index[i] = i;
	}
	for (int it = 0; it < 100; it++) // 100 итераций вполне хватает чтобы уложиться во время и отсортировать элементы
	{
		std::random_shuffle(index, index + n); //раскидываем индексы случайно, чтобы работать каждый раз в разном порядке
		int x = 0, y = 0; //начальные значения НОД массивов (0 элементов проверено)
		for (int i = 0; i < n; i++)
		{
			int t = gcd1(x, arr[index[i]]); //новое значение НОД по сравнению с НОД старого массива
			if (t != x) //1 массив
			{
				x = t; //переобозначение
				result[index[i]] = 1;
			}
			else //2 массив
			{
				y = gcd1(y, arr[index[i]]); //переобозначение
				result[index[i]] = 2;
			}
		}
		if (x == 1 && y == 1) //после очередной операции НОД обоих массивов 1
		{
			std::cout << "YES" << std::endl;
			for (int i = 0; i < n; i++) std::cout << result[i] << " ";
		}
	}
	std::cout << "NO";
}