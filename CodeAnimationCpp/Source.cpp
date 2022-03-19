#include<iostream>
#include "CodeAnimation.h"

using namespace std;

int main()
{
	CA_Init();
	//CA_DebugMode();

	Int(a, sum);
	a = 5;
	sum = 0;
	While(a > 0)
	{
		sum = sum + a;
		a = a - 1;
	}

	cout << sum << endl;
	sleep(seconds(1));

	CA_Quit();
	return 0;
}