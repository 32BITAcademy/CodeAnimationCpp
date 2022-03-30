#include "Variable.h"

using namespace std;

namespace ca {
	Variable::Variable(const Variable& v) : value(v.value)
	{
		strcpy_s(name, STRING_MAX_LENGTH, v.name);
	}

	Variable::Variable(const char* n, DataType t) : value()
	{
		strcpy_s(name, STRING_MAX_LENGTH, n);
		value.type = t;
	}
	Variable::Variable(const char* n, int v) : value(v)
	{
		strcpy_s(name, STRING_MAX_LENGTH, n);
	}
	Variable::Variable(const char* n, float v) : value(v)
	{
		strcpy_s(name, STRING_MAX_LENGTH, n);
	}
	Variable::Variable(const char* n, double v) : value(v)
	{
		strcpy_s(name, STRING_MAX_LENGTH, n);
	}
	Variable::Variable(const char* n, bool v) : value(v)
	{
		strcpy_s(name, STRING_MAX_LENGTH, n);
	}
	Variable::Variable(const char* n, char v) : value(v)
	{
		strcpy_s(name, STRING_MAX_LENGTH, n);
	}

	std::string Variable::GetOnlyValue()
	{
		return value.GetOnlyValue();
	}
	std::string Variable::GetShortString()
	{
		string s = "\"";
		s = s + name + "\" ";
		if (IsSet())
			s += value.GetShortString();
		else
			s = s + "{_GARBAGE_} (" + DataTypeToString(value.type) + ")";
		return s;
	}
	std::string Variable::GetFullString()
	{
		return "variable " + GetShortString();
	}

	bool Variable::IsSet()
	{
		return !value.isGarbage;
	}

	const Variable& Variable::operator=(const Variable& b)
	{
		strcpy_s(name, STRING_MAX_LENGTH, b.name);
		value = b.value;
		return *this;
	}
	const Variable& Variable::operator=(const Value& b)
	{
		value = b;
		return *this;
	}

	Value Variable::operator+(const Variable& b)
	{
		return value + b.value;
	}
	Value Variable::operator-(const Variable& b)
	{
		return value - b.value;
	}
	Value Variable::operator*(const Variable& b)
	{
		return value * b.value;
	}
	Value Variable::operator/(const Variable& b)
	{
		return value / b.value;
	}
	Value Variable::operator%(const Variable& b)
	{
		return value % b.value;
	}

	Value Variable::operator==(const Variable& b)
	{
		return value == b.value;
	}
	Value Variable::operator!=(const Variable& b)
	{
		return value != b.value;
	}
	Value Variable::operator>=(const Variable& b)
	{
		return value >= b.value;
	}
	Value Variable::operator> (const Variable& b)
	{
		return value >  b.value;
	}
	Value Variable::operator<=(const Variable& b)
	{
		return value <= b.value;
	}
	Value Variable::operator< (const Variable& b)
	{
		return value <  b.value;
	}
	
	Value Variable::operator!()
	{
		return !value;
	}

	Value Variable::operator&&(const Variable& b)
	{
		return value && b.value;
	}
	Value Variable::operator||(const Variable& b)
	{
		return value || b.value;
	}

	Value Variable::operator+(const Value &b)
	{
		return value + b;
	}
	Value Variable::operator-(const Value &b)
	{
		return value - b;
	}
	Value Variable::operator*(const Value &b)
	{
		return value * b;
	}
	Value Variable::operator/(const Value &b)
	{
		return value / b;
	}
	Value Variable::operator%(const Value &b)
	{
		return value % b;
	}

	Value Variable::operator==(const Value &b)
	{
		return value == b;
	}
	Value Variable::operator!=(const Value &b)
	{
		return value != b;
	}
	Value Variable::operator>=(const Value &b)
	{
		return value >= b;
	}
	Value Variable::operator> (const Value &b)
	{
		return value > b;
	}
	Value Variable::operator<=(const Value &b)
	{
		return value <= b;
	}
	Value Variable::operator< (const Value &b)
	{
		return value < b;
	}

	Value Variable::operator&&(const Value &b)
	{
		return value && b;
	}
	Value Variable::operator||(const Value &b)
	{
		return value || b;
	}

	bool Variable::GetBool()
	{
		return value.GetBool();
	}
}