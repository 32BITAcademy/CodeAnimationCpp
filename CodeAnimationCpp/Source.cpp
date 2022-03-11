#include<iostream>
#include "CodeAnimation.h"

using namespace std;

int main()
{
	CA_Init();
	CA_DebugMode();

	Int(sum, i);

	sum = 0;
	i = 5;
	While(i)
	{
		sum += i;
		i--;
	}
	cout << "Sum = " << sum << endl;

	CA_Quit();
	return 0;
}