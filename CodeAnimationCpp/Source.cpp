#include<iostream>
#include "CodeAnimation.h"

using namespace std;

int main()
{
	CA_Init();
	CA_DebugMode();

	Int(a);
	Float(b);
	Double(c);

	a = 11;
	b = 2;
	c = 0;

	If (a / b > 5 && !!c)
		cout << "Res = " << a << endl;
	Else
		cout << "Res = " << b << endl;

	CA_Quit();
	return 0;
}