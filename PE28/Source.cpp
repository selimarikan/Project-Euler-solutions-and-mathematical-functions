#include <iostream>
#include <Windows.h>

// 0.66us (200 cycles) -> 669171001
int main()
{
	int dummy;

	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;

	QueryPerformanceFrequency(&frequency);

	int spiralSize = 1001;
	int maximumNumber = spiralSize * spiralSize;
	int result = 1;
	int counter = 2;

	QueryPerformanceCounter(&t1);

	for (int i = 1; i < maximumNumber;)
	{
		i += counter;
		result += i;

		i += counter;
		result += i;

		i += counter;
		result += i;

		i += counter;
		result += i;

		counter += 2;
	}

	QueryPerformanceCounter(&t2);
	std::cout << result << std::endl;
	std::cout << std::endl << (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart << "ms" << std::endl;
	std::cin >> dummy;
	return 0;
}