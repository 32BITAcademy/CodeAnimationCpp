#include<iostream>
#include "CodeAnimationLibrary.h"

using namespace std;

int main()
{
	CodeAnimation::Init();
	CodeAnimation::DebugMode();

	Int(sum, i);

	sum = 0;
	i = 0;
	While(i <= 5)
	{
		sum += i;
		i++;
	}
	cout << "Sum = " << sum << endl;

	sum = 0;
	For(i, 0, i <= 5, 1)
	{
		sum += i;
	}
	cout << "Sum = " << sum << endl;


	CodeAnimation::Quit();
	return 0;
}