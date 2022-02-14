#include<iostream>
#include "CodeAnimationLibrary.h"

using namespace std;

int main()
{
	CodeAnimation::Init();
	CodeAnimation::DebugMode();

	Int(sum, i);
	sum = 0;
	i = 1;
	While(i <= 5)
	{
		sum += i;
		i++;
	}
	cout << "Sum = " << sum << endl;

	CodeAnimation::Quit();
	return 0;
}