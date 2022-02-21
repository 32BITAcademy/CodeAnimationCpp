#include "Variable.h"

using namespace std;

namespace ca {

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

	bool Variable::operator==(Variable& b)
	{
		return value == b.value;
	}
	bool Variable::operator!=(Variable& b)
	{
		return value != b.value;
	}
	bool Variable::operator>=(Variable& b)
	{
		return value >= b.value;
	}
	bool Variable::operator> (Variable& b)
	{
		return value >  b.value;
	}
	bool Variable::operator<=(Variable& b)
	{
		return value <= b.value;
	}
	bool Variable::operator< (Variable& b)
	{
		return value <  b.value;
	}

	bool Variable::operator==(Value& b)
	{
		return value == b;
	}
	bool Variable::operator!=(Value& b)
	{
		return value != b;
	}
	bool Variable::operator>=(Value& b)
	{
		return value >= b;
	}
	bool Variable::operator> (Value& b)
	{
		return value >  b;
	}
	bool Variable::operator<=(Value& b)
	{
		return value <= b;
	}
	bool Variable::operator< (Value& b)
	{
		return value <  b;
	}

	template<typename T>
	bool Variable::operator==(T b)
	{
		return value == b;
	}
	template<typename T>
	bool Variable::operator!=(T b)
	{
		return value != b;
	}
	template<typename T>
	bool Variable::operator>=(T b)
	{
		return value >= b;
	}
	template<typename T>
	bool Variable::operator> (T b)
	{
		return value >  b;
	}
	template<typename T>
	bool Variable::operator<=(T b)
	{
		return value <= b;
	}
	template<typename T>
	bool Variable::operator< (T b)
	{
		return value <  b;
	}

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

	template bool Variable::operator==<int>(int b);
	template bool Variable::operator!=<int>(int b);
	template bool Variable::operator>=<int>(int b);
	template bool Variable::operator> <int>(int b);
	template bool Variable::operator<=<int>(int b);
	template bool Variable::operator< <int>(int b);

	template bool Variable::operator==<float>(float b);
	template bool Variable::operator!=<float>(float b);
	template bool Variable::operator>=<float>(float b);
	template bool Variable::operator> <float>(float b);
	template bool Variable::operator<=<float>(float b);
	template bool Variable::operator< <float>(float b);

	template bool Variable::operator==<double>(double b);
	template bool Variable::operator!=<double>(double b);
	template bool Variable::operator>=<double>(double b);
	template bool Variable::operator> <double>(double b);
	template bool Variable::operator<=<double>(double b);
	template bool Variable::operator< <double>(double b);

	template bool Variable::operator==<bool>(bool b);
	template bool Variable::operator!=<bool>(bool b);
	template bool Variable::operator>=<bool>(bool b);
	template bool Variable::operator> <bool>(bool b);
	template bool Variable::operator<=<bool>(bool b);
	template bool Variable::operator< <bool>(bool b);

	template bool Variable::operator==<char>(char b);
	template bool Variable::operator!=<char>(char b);
	template bool Variable::operator>=<char>(char b);
	template bool Variable::operator> <char>(char b);
	template bool Variable::operator<=<char>(char b);
	template bool Variable::operator< <char>(char b);
}