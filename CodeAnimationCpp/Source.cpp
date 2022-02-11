#include<iostream>
#include "CodeAnimation.h"
#include "BasicTypes.h"
#include "AlgorithmicOperators.h"

using namespace std;

#define _MY_TYPE_(type, a) type a(#a);
#define _MY_TYPE_(type, a, b) type a(#a), b(#b);
#define _MY_TYPE_(type, a, b, c) type a(#a), b(#b), c(#c);
#define _MY_TYPE_(type, a, b, c, d) type a(#a), b(#b), c(#c), d(#d);
#define _MY_TYPE_(type, a, b, c, d, e) type a(#a), b(#b), c(#c), d(#d), e(#e);
#define _MY_TYPE_(type, a, b, c, d, e, f) type a(#a), b(#b), c(#c), d(#d), e(#e), f(#f);
#define _MY_TYPE_(type, a, b, c, d, e, f, g) type a(#a), b(#b), c(#c), d(#d), e(#e), f(#f), g(#g);
#define _MY_TYPE_(type, a, b, c, d, e, f, g, h) type a(#a), b(#b), c(#c), d(#d), e(#e), f(#f), g(#g), h(#h);
#define _MY_TYPE_(type, a, b, c, d, e, f, g, h, i) type a(#a), b(#b), c(#c), d(#d), e(#e), f(#f), g(#g), h(#h), i(#i);
#define _MY_TYPE_(type, a, b, c, d, e, f, g, h, i, j) type a(#a), b(#b), c(#c), d(#d), e(#e), f(#f), g(#g), h(#h), i(#i), j(#j);
#define _MY_TYPE_(type, a, b, c, d, e, f, g, h, i, j, k) type a(#a), b(#b), c(#c), d(#d), e(#e), f(#f), g(#g), h(#h), i(#i), j(#j), k(#k);


#define STRINGIZE(arg)  STRINGIZE1(arg)
#define STRINGIZE1(arg) STRINGIZE2(arg)
#define STRINGIZE2(arg) #arg

#define CONCATENATE(arg1, arg2)   CONCATENATE1(arg1, arg2)
#define CONCATENATE1(arg1, arg2)  CONCATENATE2(arg1, arg2)
#define CONCATENATE2(arg1, arg2)  arg1##arg2

#define FOR_EACH_1(what, x) 
#define FOR_EACH_2(what, x, ...)\
    what(x);                    \
    FOR_EACH_1(what);
#define FOR_EACH_3(what, x, ...)\
  what(x);\
  FOR_EACH_2(what, __VA_ARGS__);
#define FOR_EACH_4(what, x, ...)\
  what(x);\
  FOR_EACH_3(what,  __VA_ARGS__);
#define FOR_EACH_5(what, x, ...)\
  what(x);\
 FOR_EACH_4(what,  __VA_ARGS__);
#define FOR_EACH_6(what, x, ...)\
  what(x);\
  FOR_EACH_5(what,  __VA_ARGS__);
#define FOR_EACH_7(what, x, ...)\
  what(x);\
  FOR_EACH_6(what,  __VA_ARGS__);
#define FOR_EACH_8(what, x, ...)\
  what(x);\
  FOR_EACH_7(what,  __VA_ARGS__);

#define FOR_EACH_NARG(...) FOR_EACH_NARG_(__VA_ARGS__, FOR_EACH_RSEQ_N())
#define FOR_EACH_NARG_(...) FOR_EACH_ARG_N(__VA_ARGS__) 
#define FOR_EACH_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N 
#define FOR_EACH_RSEQ_N() 8, 7, 6, 5, 4, 3, 2, 1, 0

#define FOR_EACH_(N, what, x, ...) CONCATENATE(FOR_EACH_, N)(what, x, __VA_ARGS__)
#define FOR_EACH(what, x, ...) FOR_EACH_(FOR_EACH_NARG(x, __VA_ARGS__), what, x, __VA_ARGS__)


#define FOR_EACH(what, ...) FOR_EACH_(FOR_EACH_NARG(__VA_ARGS__), what, __VA_ARGS__)

#define INT(x)
int main()
{
	CodeAnimation::Init();

	//INT(a);
	INT(a,b,c);

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