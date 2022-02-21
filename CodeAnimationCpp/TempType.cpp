#include "TempType.h"

TempType::TempType(Value value)
{
}

TempType::TempType(const TempType& b)
{
}

void TempType::SendArithmeticByMSG(TempType& a, TempType& b, ArithmeticOper ao, Value result)
{
	MSG m;
	m.type = MsgType::OPER_ARITHMETIC;
	m.oper_arithm.arithm_type = ao;
	m.oper_arithm.is1var = false;
	m.oper_arithm.is2var = false;
	m.oper_arithm.value1 = a._value;
	m.oper_arithm.value2 = b._value;
	m.oper_arithm.result = result;

	CodeAnimation* ca = CodeAnimation::GetInstance();
	ca->Send(m);

	ca->WaitEndOfAnimation();
}

TempType TempType::operator+(TempType b)
{
	return TempType();
}

TempType TempType::operator-(TempType b)
{
	return TempType();
}

TempType TempType::operator*(TempType b)
{
	return TempType();
}

TempType TempType::operator/(TempType b)
{
	return TempType();
}

TempType TempType::operator%(TempType b)
{
	return TempType();
}
