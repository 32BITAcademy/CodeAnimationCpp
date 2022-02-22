#include "AlgorithmicOperators.h"
#include "CodeAnimation.h"

bool CA_TMP_BOOL_RESULT = false;

void CA_IF(bool result)
{
	CodeAnimationController* ca = CodeAnimationController::GetInstance();
	MSG m;
	m.type = MsgType::OPER_IF;
	m.oper_if.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

void CA_WHILE_START()
{
	CodeAnimationController* ca = CodeAnimationController::GetInstance();
	MSG m;
	m.type = MsgType::OPER_WHILE_START;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

bool CA_WHILE_CHECK(bool result)
{
	CodeAnimationController* ca = CodeAnimationController::GetInstance();
	MSG m;
	m.type = MsgType::OPER_WHILE_CHECK;
	m.oper_while.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
	return result;
}

void CA_FOR_START()
{
	CodeAnimationController* ca = CodeAnimationController::GetInstance();
	MSG m;
	m.type = MsgType::OPER_FOR_START;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

bool CA_FOR_CHECK(bool result)
{
	CodeAnimationController* ca = CodeAnimationController::GetInstance();
	MSG m;
	m.type = MsgType::OPER_FOR_CHECK;
	m.oper_for.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
	return result;
}
