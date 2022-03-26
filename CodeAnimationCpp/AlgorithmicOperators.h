#pragma once
#include <string>

extern bool CA_TMP_BOOL_RESULT;

#define If(x) CA_TMP_BOOL_RESULT = (x); CA_IF(#x, CA_TMP_BOOL_RESULT); if(CA_TMP_BOOL_RESULT)
#define Else else

void CA_IF(const char* s, bool result);


#define While(x) CA_WHILE_START(); while(CA_WHILE_CHECK((#x), (x)))

void CA_WHILE_START();
bool CA_WHILE_CHECK(const char* s, bool result);


#define For(variable, init_value, condition, step) CA_FOR_START(); for( INT variable(#variable, init_value); CA_FOR_CHECK(condition); variable += (step))

void CA_FOR_START();
bool CA_FOR_CHECK(bool result);