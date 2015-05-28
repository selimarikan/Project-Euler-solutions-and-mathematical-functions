#include "Functions.h"

using namespace std;

Functions::Functions()
{
}


Functions::~Functions()
{
}


const unsigned long long Functions::Factorial(const int i)
{
	if (i < 11) 
	{
		if (i == 0)	{ return 1; }
		if (i == 1)	{ return 1; }
		if (i == 2)	{ return 2; }
		if (i == 3)	{ return 6; }
		if (i == 4)	{ return 24; }
		if (i == 5)	{ return 120; }
		if (i == 6)	{ return 720; }
		if (i == 7)	{ return 5040; }
		if (i == 8)	{ return 40320; }
		if (i == 9)	{ return 362880; }
		if (i == 10){ return 3628800; }
	}
	else
	{
		return i * Factorial(i - 1);
	}
}

//Greatest Common Divisor
const long Functions::GCD(const int a, const int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

const bool Functions::IsPrime(const unsigned long i)
{
	if (i <= 1)	{ return false; }
	else if (i <= 3) { return true; }
	else if ((i % 2 == 0) || (i % 3 == 0))	{ return false; }

	long sqI = ceil(sqrt(i));

	for (int j = 5; j <= sqI; ++j)
	{
		if (i % j == 0)
		{
			return false;
		}
	}
	return true;
}

const long Functions::Fibonacci(const int i)
{
	if (i == 0) { return 0; }
	else if (i == 1) { return 1; }
	else if (i == 2) { return 1; }
	else { return Fibonacci(i - 1) + Fibonacci(i - 2); }
}

const int Functions::Totient(const long i)
{
	int count = 0;

	for (int j = 1; j <= i; ++j)
	{
		if (GCD(i, j) == 1)
			count++;
	}

	return count;
}

const int Functions::ModExponentiate(const int base, const int exponent, const int modulus)
{
	int c = 1;

	for (int i = 1; i <= exponent; ++i)
	{
		c = (c * base) % modulus;
	}

	return c;
}

const int Functions::MultiplicativeOrder(const int base, const int mod)
{
	for (int i = 1; i <= mod; ++i)
	{
		if (ModExponentiate(base, i, mod) == 1)
			return i;
	}

	return 0;
}