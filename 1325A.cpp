#include "1325A.h"

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