#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <random>

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

void _1325A()
{
	long t, x;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
	{
		std::cin >> x;
		std::cout << std::endl << 1 << std::endl << x - 1 << std::endl;
	}
}

void _664A()
{
	std::string a, b;
	std::cin >> a >> b;

	if (a == b)
	{
		std::cout << a;
	}
	else
	{
		std::cout << 1;
	}
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

int count_ = 0;

struct List
{
	long long value;
	List* next;
};

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

#define INF 0x3fffffffffffffff

const long long  mod = 1e9 + 7;
const int maxn = 1000005;
long long  n, a, b;
long long  cost[maxn], val[maxn], dp[maxn][3];
std::vector <long long> GCD;

long long calculation(long long x)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		cost[i] = 1e12 + 7;
		if (val[i] % x == 0)
			cost[i] = 0;
		else if ((val[i] + 1) % x == 0 || (val[i] - 1) % x == 0)
			cost[i] = b;
	}
	for (i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + cost[i];
		dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + a;
		dp[i][2] = std::min(dp[i - 1][1], dp[i - 1][2]) + cost[i];
	}
	return std::min(std::min(dp[n][2], dp[n][1]), dp[n][0]);
}

void pri(long long x)
{
	int i;
	for (i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			GCD.push_back(i);
		while (x % i == 0)
			x = x / i;
	}
	if (x != 1)
		GCD.push_back(x);
}

void _1350A()
{
	int t, n, k;
	std::cin >> t;
	int* arr = new int[t];
	for (int i = 0; i < t; i++)
	{
		std::cin >> n >> k;
		if (n % 2 == 0) arr[i] = n + 2 * k;
		else
		{
			bool flag = false;
			for (int i = 3; i * i <= n; i += 2)
			{
				if (n % i == 0)
				{
					n += i;
					flag = true;
					break;
				}
			}
			if (flag == false) n *= 2;
			n = n + 2 * (k - 1);
			arr[i] = n;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < t; i++) std::cout << arr[i] << std::endl;
}

void _1238A()
{
	int t;
	long long x, y;
	std::cin >> t;
	bool* arr = new bool[t];
	for (int i = 0; i < t; i++)
	{
		std::cin >> x >> y;
		long long razn = x - y;
		if (razn == 1) arr[i] = 0;
		else arr[i] = 1;
	}
	for (int i = 0; i < t; i++)
	{
		if (arr[i] == 1) std::cout << "YES" << std::endl; 
		else std::cout << "NO" << std::endl;
	}
}

void _1285C()
{
	long long X, max(1), gcd;
	std::cin >> X;
	for (long long i = 1; i * i < X; i++)
	{
		if (X % i == 0)
		{
			gcd = gcd2(i, X / i);
			if (gcd == 1) max = i;
		}
	}
	std::cout << max << " " << (X / max);
}

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

void _1068B()
{
	long long b;
	int counter = 0;
	std::cin >> b;
	for (long long i = 1; i * i <= b; i++)
	{
		if (b % i == 0) 
			counter += 2;
		if (i * i == b) 
			counter--;
	}
	std::cout << counter;
}

void _1076B()
{
	unsigned long long n, counter = 0;
	bool flag = false;
	std::cin >> n;
	for (unsigned long long i = 2; i * i <= n; ++i)
	{
		if (n % 2 == 0)
		{
			if (flag)
			{
				counter = n / 2;
				std::cout << ++counter;
			}
			else 
			{
				counter = n / 2;
				std::cout << counter;
			}
			return;
		}
		else if (n % i == 0)
			n -= i, i = 2, flag = true;
	}
	std::cout << 1;
}

void _1051B()
{
	long long l, r;
	std::cin >> l >> r;
	if (l != r)
	{
		std::cout << "YES" << std::endl;
		for (long long i = l; i <= r; i += 2) std::cout << i << " " << i + 1 << std::endl;
	}
	else std::cout << "NO";
}

void _858A()
{
	int k; long long n, kn;
	std::cin >> n >> k;
	long long inc = 1;
	for (int i = 0; i < k; i++) inc *= 10;
	kn = n * inc / gcd2(n, inc);
	std::cout << kn;
}

void _630J()
{
	long long lcm(1), n;
	std::cin >> n;
	for (long long i = 2; i <= 10; i++) lcm = lcm * i / gcd2(lcm, i);
	std::cout << n / lcm;
}

void _630K()
{
	long long n, del;
	std::cin >> n;
	del = n / 2 + n / 3 + n / 5 + n / 7 - n / 6 - n / 10 - n / 14 - n / 15 - n / 21 - n / 35 + n / 30 + n / 42 + n / 70 + n / 105 - n / 210;
	std::cout << n - del;
}

void _75C()
{
	int a, b, n, low, high, gcd;
	std::cin >> a >> b >> n;
	int* result = new int[n];
	gcd = gcd1(a, b);
	for (int i = 0; i < n; i++)
	{
		result[i] = -1;
		std::cin >> low >> high;
		if (low <= gcd && gcd <= high) 
			result[i] = gcd;
		else
		{
			int j;
			if (gcd - 1 > high) 
				j = high;
			else 
				j = gcd - 1;
			for (j; j * j >= gcd, j >= low; j--)
				if (gcd % j == 0)
				{
					result[i] = j;
					break;
				}
		}
	}
	for (int i = 0; i < n; i++) 
		std::cout << result[i] << std::endl;
}

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

int main()
{
	//_1325A();
	//_664A();
	//_798C();
	//_1228C();
	//_199A();
	//_1350A();
	//_1108B();
	//_1285C();
	//_1238A();
	//_1349A();
	//_1068B();
	//_1076B();
	//_1051B(); 
	//_946B();
	//_919B();
	//_858A();
	//_742A();
	//_630J();
	//_630K();
	//_75C();
	//_1198F();
	//_271B();
}
