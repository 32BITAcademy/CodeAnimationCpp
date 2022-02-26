#include "BasicTypes.h"

namespace ca {
	
	void SendChangeByMSG(Variable a, Variable b, ChangeOper co, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_CHANGE_BY;
		m.oper_change_by.change_type = co;
		m.oper_change_by.varWhat = a;
		m.oper_change_by.isByVar = true;
		m.oper_change_by.varBy = b;
		m.oper_change_by.result = result;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendChangeByMSG(Variable a, Value b, ChangeOper co, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_CHANGE_BY;
		m.oper_change_by.change_type = co;
		m.oper_change_by.varWhat = a;
		m.oper_change_by.isByVar = false;
		m.oper_change_by.valueBy = b;
		m.oper_change_by.result = result;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendAritmeticMSG(Variable a, Variable b, ArithmeticOper ao, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_ARITHMETIC;
		m.oper_arithm.result = result;
		m.oper_arithm.arithm_type = ao;
		m.oper_arithm.is1var = true;
		m.oper_arithm.is2var = true;
		m.oper_arithm.var1 = a;
		m.oper_arithm.var2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);
		ca->WaitEndOfAnimation();
	}

	void SendAritmeticMSG(Value a, Variable b, ArithmeticOper ao, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_ARITHMETIC;
		m.oper_arithm.result = result;
		m.oper_arithm.arithm_type = ao;
		m.oper_arithm.is1var = false;
		m.oper_arithm.is2var = true;
		m.oper_arithm.value1 = a;
		m.oper_arithm.var2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);
		ca->WaitEndOfAnimation();
	}

	void SendAritmeticMSG(Variable a, Value b, ArithmeticOper ao, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_ARITHMETIC;
		m.oper_arithm.result = result;
		m.oper_arithm.arithm_type = ao;
		m.oper_arithm.is1var = true;
		m.oper_arithm.is2var = false;
		m.oper_arithm.var1 = a;
		m.oper_arithm.value2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);
		ca->WaitEndOfAnimation();
	}

	void SendAritmeticMSG(Value a, Value b, ArithmeticOper ao, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_ARITHMETIC;
		m.oper_arithm.result = result;
		m.oper_arithm.arithm_type = ao;
		m.oper_arithm.is1var = false;
		m.oper_arithm.is2var = false;
		m.oper_arithm.value1 = a;
		m.oper_arithm.value2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);
		ca->WaitEndOfAnimation();
	}

	void SendCompareMSG(Variable a, Variable b, CompareOper co, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = result;
		m.oper_compare.comp_type = co;
		m.oper_compare.is1var = true;
		m.oper_compare.is2var = true;
		m.oper_compare.var1 = a;
		m.oper_compare.var2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendCompareMSG(Value a, Variable b, CompareOper co, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = result;
		m.oper_compare.comp_type = co;
		m.oper_compare.is1var = false;
		m.oper_compare.is2var = true;
		m.oper_compare.value1 = a;
		m.oper_compare.var2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendCompareMSG(Variable a, Value b, CompareOper co, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = result;
		m.oper_compare.comp_type = co;
		m.oper_compare.is1var = true;
		m.oper_compare.is2var = false;
		m.oper_compare.var1 = a;
		m.oper_compare.value2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendCompareMSG(Value a, Value b, CompareOper co, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = result;
		m.oper_compare.comp_type = co;
		m.oper_compare.is1var = false;
		m.oper_compare.is2var = false;
		m.oper_compare.value1 = a;
		m.oper_compare.value2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

}