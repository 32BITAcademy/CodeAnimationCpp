#pragma once

extern bool CA_TMP_BOOL_RESULT;

#define If(x) CA_TMP_BOOL_RESULT = (x); CA_IF(CA_TMP_BOOL_RESULT); if(CA_TMP_BOOL_RESULT)
#define Else else

#define While(x) CA_WHILE_START(); while(CA_WHILE_CHECK(x))

void CA_IF(bool result);
void CA_WHILE_START();
bool CA_WHILE_CHECK(bool result);