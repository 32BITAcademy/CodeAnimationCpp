#include<iostream>
#include "CodeAnimation.h"

using namespace std;

int main()
{
	CA_Init();
	//CA_DebugMode();

	Int(a, sum);
	a = 10;
	sum = 0;
	While(a > 0)
	{
		sum += a;
		a--;
	}

	cout << sum << endl;

	CA_Quit();
	return 0;
}