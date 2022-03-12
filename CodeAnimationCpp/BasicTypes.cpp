#include "BasicTypes.h"
#include "TempType.h"

namespace ca {
	
	template<typename T>
	BasicType<T>& BasicType<T>::operator=(const TempType& b)
	{
		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		MSG m;
		m.type = MsgType::SET_VAR;
		m.set_var.varWhat = var;
		m.set_var.isByVar = false;
		m.set_var.valueBy = b.value;

		var.value.SetVal(b.value);
		real_value = var.value.uv.GetValue(real_value);

		m.set_var.result = var.value;
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
	}

	template BasicType<int>& BasicType<int>::operator=(const TempType& b);
	template BasicType<float>& BasicType<float>::operator=(const TempType& b);
	template BasicType<double>& BasicType<double>::operator=(const TempType& b);
	template BasicType<bool>& BasicType<bool>::operator=(const TempType& b);
	template BasicType<char>& BasicType<char>::operator=(const TempType& b);

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

	void SendArithmeticMSG(Variable a, Variable b, ArithmeticOper ao, Value result)
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

	void SendArithmeticMSG(Value a, Variable b, ArithmeticOper ao, Value result)
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

	void SendArithmeticMSG(Variable a, Value b, ArithmeticOper ao, Value result)
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

	void SendArithmeticMSG(Value a, Value b, ArithmeticOper ao, Value result)
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
	
	void SendLogicMSG(Variable a, Variable b, LogicOper lo, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_LOGIC;
		m.oper_logic.result = result;
		m.oper_logic.logic_type = lo;
		m.oper_logic.is1var = true;
		m.oper_logic.is2var = true;
		m.oper_logic.var1 = a;
		m.oper_logic.var2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendLogicMSG(Variable a, Value b, LogicOper lo, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_LOGIC;
		m.oper_logic.result = result;
		m.oper_logic.logic_type = lo;
		m.oper_logic.is1var = true;
		m.oper_logic.is2var = false;
		m.oper_logic.var1 = a;
		m.oper_logic.value2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendLogicMSG(Value a, Variable b, LogicOper lo, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_LOGIC;
		m.oper_logic.result = result;
		m.oper_logic.logic_type = lo;
		m.oper_logic.is1var = false;
		m.oper_logic.is2var = true;
		m.oper_logic.value1 = a;
		m.oper_logic.var2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	void SendLogicMSG(Value a, Value b, LogicOper lo, Value result)
	{
		MSG m;
		m.type = MsgType::OPER_LOGIC;
		m.oper_logic.result = result;
		m.oper_logic.logic_type = lo;
		m.oper_logic.is1var = false;
		m.oper_logic.is2var = false;
		m.oper_logic.value1 = a;
		m.oper_logic.value2 = b;

		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

}