#pragma once

#include <iostream>

struct List
{
	long long value;
	List* next;
};

unsigned long long module_(unsigned long long number, unsigned long long degree, int mod);
void _1228C();