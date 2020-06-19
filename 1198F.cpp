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
	for (int it = 0; it < 100; it++) // 100 �������� ������ ������� ����� ��������� �� ����� � ������������� ��������
	{
		std::random_shuffle(index, index + n); //����������� ������� ��������, ����� �������� ������ ��� � ������ �������
		int x = 0, y = 0; //��������� �������� ��� �������� (0 ��������� ���������)
		for (int i = 0; i < n; i++)
		{
			int t = gcd1(x, arr[index[i]]); //����� �������� ��� �� ��������� � ��� ������� �������
			if (t != x) //1 ������
			{
				x = t; //���������������
				result[index[i]] = 1;
			}
			else //2 ������
			{
				y = gcd1(y, arr[index[i]]); //���������������
				result[index[i]] = 2;
			}
		}
		if (x == 1 && y == 1) //����� ��������� �������� ��� ����� �������� 1
		{
			std::cout << "YES" << std::endl;
			for (int i = 0; i < n; i++) std::cout << result[i] << " ";
		}
	}
	std::cout << "NO";
}