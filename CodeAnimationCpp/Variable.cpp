#include "Variable.h"

using namespace std;

namespace ca {
	Variable::Variable(const Variable& v) : value(v.value)
	{
		strcpy_s(name, NAME_LENGTH, v.name);
	}

	Variable::Variable(const char* n, DataType t) : value()
	{
		strcpy_s(name, NAME_LENGTH, n);
		value.type = t;
	}

	Variable::Variable(const char* n, int v) : value(v)
	{
		strcpy_s(name, NAME_LENGTH, n);
	}

	Variable::Variable(const char* n, float v) : value(v)
	{
		strcpy_s(name, NAME_LENGTH, n);
	}

	Variable::Variable(const char* n, double v) : value(v)
	{
		strcpy_s(name, NAME_LENGTH, n);
	}

	Variable::Variable(const char* n, bool v) : value(v)
	{
		strcpy_s(name, NAME_LENGTH, n);
	}

	Variable::Variable(const char* n, char v) : value(v)
	{
		strcpy_s(name, NAME_LENGTH, n);
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

	Variable& Variable::operator=(Variable& b)
	{
		value = b.value;
		return *this;
	}

	template<typename T>
	Variable& Variable::operator=(T b)
	{
		value = b;
	}

	Value Variable::operator+(Variable& b)
	{
		return value + b.value;
	}
	Value Variable::operator-(Variable& b)
	{
		return value - b.value;
	}
	Value Variable::operator*(Variable& b)
	{
		return value * b.value;
	}
	Value Variable::operator/(Variable& b)
	{
		return value / b.value;
	}
	Value Variable::operator%(Variable& b)
	{
		return value % b.value;
	}

	Value Variable::operator+(Value& b)
	{
		return value + b;
	}
	Value Variable::operator-(Value& b)
	{
		return value - b;
	}
	Value Variable::operator*(Value& b)
	{
		return value * b;
	}
	Value Variable::operator/(Value& b)
	{
		return value / b;
	}
	Value Variable::operator%(Value& b)
	{
		return value % b;
	}

	template<typename T>
	Value Variable::operator+(T b)
	{
		return value + b;
	}
	template<typename T>
	Value Variable::operator-(T b)
	{
		return value - b;
	}
	template<typename T>
	Value Variable::operator*(T b)
	{
		return value * b;
	}
	template<typename T>
	Value Variable::operator/(T b)
	{
		return value / b;
	}
	template<typename T>
	Value Variable::operator%(T b)
	{
		return value % b;
	}

	Value Variable::operator==(Variable& b)
	{
		return value == b.value;
	}
	Value Variable::operator!=(Variable& b)
	{
		return value != b.value;
	}
	Value Variable::operator>=(Variable& b)
	{
		return value >= b.value;
	}
	Value Variable::operator> (Variable& b)
	{
		return value >  b.value;
	}
	Value Variable::operator<=(Variable& b)
	{
		return value <= b.value;
	}
	Value Variable::operator< (Variable& b)
	{
		return value <  b.value;
	}
	
	Value Variable::operator==(Value& b)
	{
		return value == b;
	}
	Value Variable::operator!=(Value& b)
	{
		return value != b;
	}
	Value Variable::operator>=(Value& b)
	{
		return value >= b;
	}
	Value Variable::operator> (Value& b)
	{
		return value >  b;
	}
	Value Variable::operator<=(Value& b)
	{
		return value <= b;
	}
	Value Variable::operator< (Value& b)
	{
		return value <  b;
	}

	template<typename T>
	Value Variable::operator==(T b)
	{
		return value == b;
	}
	template<typename T>
	Value Variable::operator!=(T b)
	{
		return value != b;
	}
	template<typename T>
	Value Variable::operator>=(T b)
	{
		return value >= b;
	}
	template<typename T>
	Value Variable::operator> (T b)
	{
		return value >  b;
	}
	template<typename T>
	Value Variable::operator<=(T b)
	{
		return value <= b;
	}
	template<typename T>
	Value Variable::operator< (T b)
	{
		return value <  b;
	}

	Value Variable::operator!()
	{
		return !value;
	}

	Value Variable::operator&&(Variable& b)
	{
		return value && b.value;
	}

	Value Variable::operator||(Variable& b)
	{
		return value || b.value;
	}

	Value Variable::operator&&(Value& b)
	{
		return value && b;
	}

	Value Variable::operator||(Value& b)
	{
		return value || b;
	}

	Value Variable::operator&&(bool b)
	{
		return value && b;
	}

	Value Variable::operator||(bool b)
	{
		return value || b;
	}

	Variable::operator bool()
	{
		return bool(value);
	}

	template Variable& Variable::operator=<int>(int b);
	template Variable& Variable::operator=<float>(float b);
	template Variable& Variable::operator=<double>(double b);
	template Variable& Variable::operator=<bool>(bool b);
	template Variable& Variable::operator=<char>(char b);

	template Value Variable::operator+<int>(int b);
	template Value Variable::operator-<int>(int b);
	template Value Variable::operator*<int>(int b);
	template Value Variable::operator/<int>(int b);
	template Value Variable::operator%<int>(int b);

	template Value Variable::operator+<float>(float b);
	template Value Variable::operator-<float>(float b);
	template Value Variable::operator*<float>(float b);
	template Value Variable::operator/<float>(float b);
	template Value Variable::operator%<float>(float b);

	template Value Variable::operator+<double>(double b);
	template Value Variable::operator-<double>(double b);
	template Value Variable::operator*<double>(double b);
	template Value Variable::operator/<double>(double b);
	template Value Variable::operator%<double>(double b);

	template Value Variable::operator+<bool>(bool b);
	template Value Variable::operator-<bool>(bool b);
	template Value Variable::operator*<bool>(bool b);
	template Value Variable::operator/<bool>(bool b);
	template Value Variable::operator%<bool>(bool b);

	template Value Variable::operator+<char>(char b);
	template Value Variable::operator-<char>(char b);
	template Value Variable::operator*<char>(char b);
	template Value Variable::operator/<char>(char b);
	template Value Variable::operator%<char>(char b);

	template Value Variable::operator==<int>(int b);
	template Value Variable::operator!=<int>(int b);
	template Value Variable::operator>=<int>(int b);
	template Value Variable::operator> <int>(int b);
	template Value Variable::operator<=<int>(int b);
	template Value Variable::operator< <int>(int b);

	template Value Variable::operator==<float>(float b);
	template Value Variable::operator!=<float>(float b);
	template Value Variable::operator>=<float>(float b);
	template Value Variable::operator> <float>(float b);
	template Value Variable::operator<=<float>(float b);
	template Value Variable::operator< <float>(float b);

	template Value Variable::operator==<double>(double b);
	template Value Variable::operator!=<double>(double b);
	template Value Variable::operator>=<double>(double b);
	template Value Variable::operator> <double>(double b);
	template Value Variable::operator<=<double>(double b);
	template Value Variable::operator< <double>(double b);

	template Value Variable::operator==<bool>(bool b);
	template Value Variable::operator!=<bool>(bool b);
	template Value Variable::operator>=<bool>(bool b);
	template Value Variable::operator> <bool>(bool b);
	template Value Variable::operator<=<bool>(bool b);
	template Value Variable::operator< <bool>(bool b);

	template Value Variable::operator==<char>(char b);
	template Value Variable::operator!=<char>(char b);
	template Value Variable::operator>=<char>(char b);
	template Value Variable::operator> <char>(char b);
	template Value Variable::operator<=<char>(char b);
	template Value Variable::operator< <char>(char b);


}