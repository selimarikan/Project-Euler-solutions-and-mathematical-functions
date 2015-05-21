#include <iostream>
#include <vector>
#include <iterator>
#include <Windows.h>

using namespace std;

int Factorial(int i)
{
	if ((i == 0) || (i == 1))
		return 1;
	else
		return i * Factorial(i - 1);
}

int main()
{
	vector<int> numbers {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> lexiperm;

	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;

	QueryPerformanceFrequency(&frequency);

	double xThPermutation = 1000000;
	double startingFactorial = Factorial(10);
	QueryPerformanceCounter(&t1);
	for (int i = 10; i > 0; --i)
	{
		startingFactorial /= i;
		int characterIndex = (int)ceil(xThPermutation / startingFactorial);
		lexiperm.push_back(numbers[characterIndex - 1]);
		numbers.erase(numbers.begin() + characterIndex - 1);
		xThPermutation -= ((characterIndex - 1) * startingFactorial);
	}
	QueryPerformanceCounter(&t2);
	copy(lexiperm.begin(), lexiperm.end(), ostream_iterator<int>(cout, "")); 
	cout << endl << (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart << "ms"; cin >> startingFactorial;
}