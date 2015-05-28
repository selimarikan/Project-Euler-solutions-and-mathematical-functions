#include <iostream>
#include <vector>
#include <Windows.h>
#include "..\Functions\Functions.h"

// 90ms -> 983
int main()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;

	//unsigned long long result;

	QueryPerformanceFrequency(&frequency);

	QueryPerformanceCounter(&t1);

	int maximum = 0;
	int index = 0;

	for (int i = 1; i < 1000; ++i)
	{
		if (Functions::IsPrime(i)) // Only primes have recurring decimals
		{
			int result = Functions::MultiplicativeOrder(10, i); // recurring decimal length

			if (result > maximum)
			{
				maximum = result;
				index = i;
			}
		}
	}

	QueryPerformanceCounter(&t2);
	std::cout << std::endl << (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart << "ms"; 

	printf("\n%d %d", index, maximum);
	
	std::cin >> maximum; // dummy
	return 0;
}