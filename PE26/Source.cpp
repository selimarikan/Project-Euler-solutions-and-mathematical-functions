#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int maximum = 0;
	int index = 0;

	for (int i = 1; i < 1000; i++)
	{
		int val = (int)ceil(log10(pow(10, i - 1) / i));
		if (val > maximum)
		{
			maximum = val;
			index = i;
		}
	}

	cout << index; cin >> index;
	return 0;
}