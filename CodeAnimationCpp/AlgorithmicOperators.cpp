#include "AlgorithmicOperators.h"
#include "CodeAnimation.h"

bool CA_TMP_BOOL_RESULT = false;

void CA_IF(bool result)
{
	CodeAnimation* ca = CodeAnimation::GetInstance();
	MSG m;
	m.type = MsgType::OPER_IF;
	m.oper_if.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

void CA_WHILE_START()
{
	CodeAnimation* ca = CodeAnimation::GetInstance();
	MSG m;
	m.type = MsgType::OPER_WHILE_START;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

bool CA_WHILE_CHECK(bool result)
{
	CodeAnimation* ca = CodeAnimation::GetInstance();
	MSG m;
	m.type = MsgType::OPER_WHILE_CHECK;
	m.oper_while.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
	return result;
}
