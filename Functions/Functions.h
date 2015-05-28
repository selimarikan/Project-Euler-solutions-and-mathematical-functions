#pragma once
#include <math.h>
#include <vector>

using namespace std;

class Functions
{
public:
	Functions();
	~Functions();
	static const unsigned long long Factorial(const int i);
	static const long GCD(const int a, const int b);
	static const bool IsPrime(const unsigned long i);
	static const long Fibonacci(const int i);
	static const int Totient(const long i);
	static const int ModExponentiate(const int base, const int exponent, const int modulus);
	static const int MultiplicativeOrder(const int base, const int mod);
};

