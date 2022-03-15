#include<iostream>
#include "CodeAnimation.h"

using namespace std;

int main()
{
	CA_Init();
	CA_DebugMode();

	Int(a, sum);
	a = 100000;
	sum = 0;
	int i = 0;
	While(a > 0)
	{
		
		i = 0;
		while (i < 2100000000)
			i++;
		sum += a;
	}

	cout << sum << endl;

	CA_Quit();
	return 0;
}