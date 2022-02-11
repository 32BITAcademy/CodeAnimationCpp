#include<iostream>
#include "CodeAnimation.h"
#include "BasicTypes.h"
#include "AlgorithmicOperators.h"

using namespace std;

int main()
{
	CodeAnimation::Init();

	//INT(a);
	//INT(a,b,c);

	Int a("a", 7);
	Float b("b", 12.314159f);
	Double c("c");
	Bool d("d", true);
	Char e("e", '!');

	Int f("f");
	f = a;
	If(f == a)
		cout << "YES!!!" << endl;
	Else
		cout << "NOOOO!" << endl;

	sf::sleep(sf::milliseconds(5000));

	CodeAnimation::Quit();
	return 0;
}