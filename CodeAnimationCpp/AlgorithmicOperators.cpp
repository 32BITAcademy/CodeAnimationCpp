#include "AlgorithmicOperators.h"
#include "CodeAnimationController.h"
#include "MSG.h"

bool CA_TMP_BOOL_RESULT = false;

void CA_IF(bool result)
{
	ca::CodeAnimationController* ca = ca::CodeAnimationController::GetInstance();
	ca::MSG m;
	m.type = ca::MsgType::OPER_IF;
	m.oper_if.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

void CA_WHILE_START()
{
	ca::CodeAnimationController* ca = ca::CodeAnimationController::GetInstance();
	ca::MSG m;
	m.type = ca::MsgType::OPER_WHILE_START;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

bool CA_WHILE_CHECK(bool result)
{
	ca::CodeAnimationController* ca = ca::CodeAnimationController::GetInstance();
	ca::MSG m;
	m.type = ca::MsgType::OPER_WHILE_CHECK;
	m.oper_while.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
	return result;
}

void CA_FOR_START()
{
	ca::CodeAnimationController* ca = ca::CodeAnimationController::GetInstance();
	ca::MSG m;
	m.type = ca::MsgType::OPER_FOR_START;
	ca->Send(m);
	ca->WaitEndOfAnimation();
}

bool CA_FOR_CHECK(bool result)
{
	ca::CodeAnimationController* ca = ca::CodeAnimationController::GetInstance();
	ca::MSG m;
	m.type = ca::MsgType::OPER_FOR_CHECK;
	m.oper_for.result = result;
	ca->Send(m);
	ca->WaitEndOfAnimation();
	return result;
}
