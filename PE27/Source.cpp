#include <iostream>
#include <vector>
#include <Windows.h>
#include "..\Functions\Functions.h"

// smart brute force
// 590ms -> -59231
int main()
{
	int dummy = 0;
	int maximum = 0;

	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;

	QueryPerformanceFrequency(&frequency);

	bool isSuccessful = true;

	int a = 1;
	int b = -241;
	int c = 1000;

	std::vector<int> primesTo1000;

	QueryPerformanceCounter(&t1);

	for (int i = 2; i < 1000; ++i)
	{
		if (Functions::IsPrime(i))
		{
			primesTo1000.push_back(i);
		}
	}

	for (int i = 0; i < primesTo1000.size(); ++i)
	{
		for (int j = 0; j < primesTo1000.size(); ++j)
		{
			isSuccessful = true;
			int k = 0;
			for (k = 0; k < primesTo1000[i]; ++k)
			{
				if (!Functions::IsPrime((k * k) - (primesTo1000[i] * k) + primesTo1000[j]))
				{
					isSuccessful = false;
					break;
				}
			}

			if (isSuccessful)
			{
				//std::cout << "Prime generator with coefficients " << primesTo1000[i] << " and " << primesTo1000[j] << " with prime count: " << k << std::endl;
				if (primesTo1000[i] * primesTo1000[j] > maximum)
				{
					maximum = primesTo1000[i] * primesTo1000[j];
				}
			}
		}
	}

	QueryPerformanceCounter(&t2);
	std::cout << std::endl << (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart << "ms" << std::endl;
	std::cout << "Prime generator coefficient product " << maximum << std::endl;

	std::cin >> dummy;
	return 0;
}