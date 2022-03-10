#include "Value.h"
#include "Variable.h"
#include <iostream>

namespace ca {

	Value::Value()
	{
		uv._double = 0;
		isGarbage = true;
		type = DataType::UNDEFINED;
	}
	Value::Value(const Value& b)
	{
		uv = b.uv;
		type = b.type;
		isGarbage = b.isGarbage;
	}
	Value::Value(int v)
	{
		isGarbage = false;
		type = GetType(v);
		uv.SetValue(v);
	}
	Value::Value(float v)
	{
		isGarbage = false;
		type = GetType(v);
		uv.SetValue(v);
	}
	Value::Value(double v)
	{
		isGarbage = false;
		type = GetType(v);
		uv.SetValue(v);
	}
	Value::Value(bool v)
	{
		isGarbage = false;
		type = GetType(v);
		uv.SetValue(v);
	}
	Value::Value(char v)
	{
		isGarbage = false;
		type = GetType(v);
		uv.SetValue(v);
	}

	std::string Value::GetOnlyValue()
	{
		if (isGarbage) return "_GARBAGE_";
		return uv.ToString(type);
	}

	std::string Value::GetShortString()
	{
		return "{" + GetOnlyValue() + "} (" + DataTypeToString(type) + ")";
	}

	std::string Value::GetFullString()
	{
		return "value " + GetShortString();
	}

	void Value::Set(const Value& b)
	{
		/*switch (b.type)
		{
		case DataType::INT: uv.SetValue(b.uv._int); break;
		case DataType::FLOAT: uv.SetValue(b.uv._float); break;
		case DataType::DOUBLE: uv.SetValue(b.uv._double); break;
		case DataType::BOOL: uv.SetValue(b.uv._bool); break;
		case DataType::CHAR: uv.SetValue(b.uv._char); break;
		}
		isGarbage = b.isGarbage;*/
		uv = b.uv;
		type = b.type;
		isGarbage = b.isGarbage;
	}

	void Value::Copy(Value& b)
	{
		type = b.type;
		isGarbage = b.isGarbage;
		uv = b.uv;
	}

	const Value& Value::operator=(const Value& b)
	{
		Set(b);
		return *this;
	}

#pragma region SHORT_FUNCS
	template <typename T, typename S>
	auto add(T a, S b) -> decltype(a + b)
	{
		return a + b;
	}

	template <typename T, typename S>
	auto sub(T a, S b) -> decltype(a - b)
	{
		return a - b;
	}

	template <typename T, typename S>
	auto mul(T a, S b) -> decltype(a * b)
	{
		return a * b;
	}

	template <typename T, typename S>
	auto div(T a, S b) -> decltype(a / b)
	{
		return a / b;
	}

	template <typename T, typename S>
	auto mod(T a, S b) -> decltype(a % b)
	{
		return a % b;
	}

	template <typename T, typename S>
	bool equal(T a, S b)
	{
		return a == b;
	}

	template <typename T, typename S>
	bool not_equal(T a, S b)
	{
		return a != b;
	}

	template <typename T, typename S>
	bool eq_greater(T a, S b)
	{
		return a >= b;
	}

	template <typename T, typename S>
	bool greater(T a, S b)
	{
		return a > b;
	}

	template <typename T, typename S>
	bool eq_less(T a, S b)
	{
		return a <= b;
	}

	template <typename T, typename S>
	bool less(T a, S b)
	{
		return a < b;
	}

	template <typename T, typename S>
	bool b_and(T a, S b)
	{
		return a and b;
	}

	template <typename T, typename S>
	bool b_or(T a, S b)
	{
		return a or b;
	}

#pragma endregion //SHORT_FUNCS

	Value Value::operator+(const Value &b)
	{
		Value res;
		res.isGarbage = isGarbage or b.isGarbage;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._int, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._int, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._int, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._int, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._int, b.uv._char));
				break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._float, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._float, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._float, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._float, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._float, b.uv._char));
				break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._double, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._double, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._double, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._double, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._double, b.uv._char));
				break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._bool, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._bool, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._bool, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._bool, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._bool, b.uv._char));
				break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._char, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._char, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(add(uv._char, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._char, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(add(uv._char, b.uv._char));
				break;
			}
			break;
		}
		return res;
	}
	Value Value::operator-(const Value &b)
	{
		Value res;
		res.isGarbage = isGarbage or b.isGarbage;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._int, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._int, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._int, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._int, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._int, b.uv._char));
				break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._float, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._float, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._float, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._float, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._float, b.uv._char));
				break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._double, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._double, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._double, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._double, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._double, b.uv._char));
				break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._bool, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._bool, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._bool, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._bool, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._bool, b.uv._char));
				break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._char, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._char, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._char, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._char, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(sub(uv._char, b.uv._char));
				break;
			}
			break;
		}
		return res;
	}
	Value Value::operator*(const Value &b)
	{
		Value res;
		res.isGarbage = isGarbage or b.isGarbage;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._int, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._int, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._int, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._int, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._int, b.uv._char));
				break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._float, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._float, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._float, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._float, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._float, b.uv._char));
				break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._double, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._double, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._double, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._double, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._double, b.uv._char));
				break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._bool, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._bool, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._bool, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._bool, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._bool, b.uv._char));
				break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._char, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._char, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._char, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._char, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mul(uv._char, b.uv._char));
				break;
			}
			break;
		}
		return res;
	}
	Value Value::operator/(const Value &b)
	{
		Value res;
		res.isGarbage = isGarbage or b.isGarbage;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._int, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._int, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._int, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._int, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._int, b.uv._char));
				break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._float, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._float, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._float, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._float, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._float, b.uv._char));
				break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._double, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._double, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._double, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._double, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._double, b.uv._char));
				break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._bool, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._bool, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._bool, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._bool, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._bool, b.uv._char));
				break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._char, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._char, b.uv._float));
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				if (!res.isGarbage) res.uv.SetValue(div(uv._char, b.uv._double));
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._char, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(div(uv._char, b.uv._char));
				break;
			}
			break;
		}
		return res;
	}
	Value Value::operator%(const Value &b)
	{
		Value res;
		res.isGarbage = isGarbage or b.isGarbage;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._int, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				res.isGarbage = true;
				std::cout << "[CA-Error] Int mod Float is impossible\n";
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Int mod Double is impossible\n";
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._int, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._int, b.uv._char));
				break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				res.isGarbage = true;
				std::cout << "[CA-Error] Float mod Int is impossible\n";
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				res.isGarbage = true;
				std::cout << "[CA-Error] Float mod Float is impossible\n";
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Float mod Double is impossible\n";
				break;
			case DataType::BOOL:
				res.type = DataType::FLOAT;
				res.isGarbage = true;
				std::cout << "[CA-Error] Float mod Bool is impossible\n";
				break;
			case DataType::CHAR:
				res.type = DataType::FLOAT;
				res.isGarbage = true;
				std::cout << "[CA-Error] Float mod Char is impossible\n";
				break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Double mod Int is impossible\n";
				break;
			case DataType::FLOAT:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Double mod Float is impossible\n";
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Double mod Double is impossible\n";
				break;
			case DataType::BOOL:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Double mod Bool is impossible\n";
				break;
			case DataType::CHAR:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Double mod Char is impossible\n";
				break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._bool, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				res.isGarbage = true;
				std::cout << "[CA-Error] Bool mod Float is impossible\n";
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Bool mod Double is impossible\n";
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._bool, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._bool, b.uv._char));
				break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._char, b.uv._int));
				break;
			case DataType::FLOAT:
				res.type = DataType::FLOAT;
				res.isGarbage = true;
				std::cout << "[CA-Error] Char mod Float is impossible\n";
				break;
			case DataType::DOUBLE:
				res.type = DataType::DOUBLE;
				res.isGarbage = true;
				std::cout << "[CA-Error] Bool mod Double is impossible\n";
				break;
			case DataType::BOOL:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._char, b.uv._bool));
				break;
			case DataType::CHAR:
				res.type = DataType::INT;
				if (!res.isGarbage) res.uv.SetValue(mod(uv._char, b.uv._char));
				break;
			}
			break;
		}
		return res;
	}

	Value Value::operator==(const Value &b)
	{
		Value v;
		v.type = DataType::BOOL;
		if (isGarbage or b.isGarbage)
			v.isGarbage = true; else v.isGarbage = false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = equal(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = equal(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = equal(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = equal(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = equal(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = equal(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = equal(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = equal(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = equal(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = equal(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = equal(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = equal(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = equal(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = equal(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = equal(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = equal(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = equal(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = equal(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = equal(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = equal(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = equal(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = equal(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = equal(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = equal(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = equal(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}
	Value Value::operator!=(const Value &b)
	{
		Value v;
		v.type = DataType::BOOL;
		if (isGarbage or b.isGarbage)
			v.isGarbage = true; else v.isGarbage = false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = not_equal(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = not_equal(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = not_equal(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = not_equal(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = not_equal(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = not_equal(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = not_equal(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = not_equal(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = not_equal(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = not_equal(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = not_equal(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = not_equal(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = not_equal(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = not_equal(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = not_equal(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = not_equal(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = not_equal(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = not_equal(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = not_equal(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = not_equal(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = not_equal(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = not_equal(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = not_equal(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = not_equal(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = not_equal(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}
	Value Value::operator>=(const Value &b)
	{
		Value v;
		v.type = DataType::BOOL;
		if (isGarbage or b.isGarbage)
			v.isGarbage = true; else v.isGarbage = false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_greater(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_greater(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_greater(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_greater(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_greater(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_greater(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_greater(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_greater(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_greater(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_greater(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_greater(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_greater(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_greater(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_greater(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_greater(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_greater(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_greater(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_greater(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_greater(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_greater(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_greater(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_greater(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_greater(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_greater(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_greater(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}
	Value Value::operator>(const Value &b)
	{
		Value v;
		v.type = DataType::BOOL;
		if (isGarbage or b.isGarbage)
			v.isGarbage = true; else v.isGarbage = false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = greater(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = greater(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = greater(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = greater(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = greater(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = greater(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = greater(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = greater(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = greater(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = greater(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = greater(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = greater(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = greater(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = greater(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = greater(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = greater(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = greater(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = greater(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = greater(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = greater(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = greater(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = greater(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = greater(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = greater(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = greater(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}
	Value Value::operator<=(const Value &b)
	{
		Value v;
		v.type = DataType::BOOL;
		if (isGarbage or b.isGarbage)
			v.isGarbage = true; else v.isGarbage = false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_less(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_less(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_less(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_less(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_less(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_less(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_less(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_less(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_less(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_less(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_less(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_less(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_less(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_less(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_less(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_less(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_less(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_less(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_less(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_less(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = eq_less(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = eq_less(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = eq_less(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = eq_less(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = eq_less(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}
	Value Value::operator<(const Value &b)
	{
		Value v;
		v.type = DataType::BOOL;
		if (isGarbage or b.isGarbage)
			v.isGarbage = true; else v.isGarbage = false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = less(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = less(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = less(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = less(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = less(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = less(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = less(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = less(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = less(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = less(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = less(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = less(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = less(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = less(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = less(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = less(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = less(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = less(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = less(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = less(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = less(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = less(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = less(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = less(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = less(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}

	Value Value::operator!()
	{
		Value v;
		v.type = DataType::BOOL;
		v.isGarbage = isGarbage;
		
		switch (type)
		{
		case DataType::INT: v.uv._bool = !uv._int; break;
		case DataType::FLOAT: v.uv._bool = !uv._float; break;
		case DataType::DOUBLE: v.uv._bool = !uv._double; break;
		case DataType::BOOL: v.uv._bool = !uv._bool; break;
		case DataType::CHAR: v.uv._bool = !uv._char; break;
		default: v.uv._bool = true;
		}
		return v;
	}
	Value Value::operator&&(const Value &b)
	{
		Value v;
		v.isGarbage = isGarbage or b.isGarbage;
		v.type = DataType::BOOL;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool =  b_and(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool =  b_and(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool =  b_and(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool =  b_and(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool =  b_and(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool =  b_and(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool =  b_and(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool =  b_and(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool =  b_and(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool =  b_and(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool =  b_and(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool =  b_and(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool =  b_and(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool =  b_and(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool =  b_and(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool =  b_and(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool =  b_and(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool =  b_and(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool =  b_and(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool =  b_and(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool =  b_and(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool =  b_and(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool =  b_and(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool =  b_and(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool =  b_and(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}
	Value Value::operator||(const Value &b)
	{
		Value v;
		v.isGarbage = isGarbage or b.isGarbage;
		v.type = DataType::BOOL;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = b_or(uv._int, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = b_or(uv._int, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = b_or(uv._int, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = b_or(uv._int, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = b_or(uv._int, b.uv._char); break;
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = b_or(uv._float, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = b_or(uv._float, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = b_or(uv._float, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = b_or(uv._float, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = b_or(uv._float, b.uv._char); break;
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = b_or(uv._double, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = b_or(uv._double, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = b_or(uv._double, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = b_or(uv._double, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = b_or(uv._double, b.uv._char); break;
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = b_or(uv._bool, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = b_or(uv._bool, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = b_or(uv._bool, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = b_or(uv._bool, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = b_or(uv._bool, b.uv._char); break;
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: v.uv._bool = b_or(uv._char, b.uv._int); break;
			case DataType::FLOAT: v.uv._bool = b_or(uv._char, b.uv._float); break;
			case DataType::DOUBLE: v.uv._bool = b_or(uv._char, b.uv._double); break;
			case DataType::BOOL: v.uv._bool = b_or(uv._char, b.uv._bool); break;
			case DataType::CHAR: v.uv._bool = b_or(uv._char, b.uv._char); break;
			}
			break;
		}

		return v;
	}

	Value Value::operator+(const Variable &b)
	{
		return *this + b.value;
	}
	Value Value::operator-(const Variable &b)
	{
		return *this - b.value;
	}
	Value Value::operator*(const Variable &b)
	{
		return *this * b.value;
	}
	Value Value::operator/(const Variable &b)
	{
		return *this / b.value;
	}
	Value Value::operator%(const Variable &b)
	{
		return *this % b.value;
	}

	Value Value::operator==(const Variable &b)
	{
		return *this == b.value;
	}
	Value Value::operator!=(const Variable &b)
	{
		return *this != b.value;
	}
	Value Value::operator>=(const Variable &b)
	{
		return *this >= b.value;
	}
	Value Value::operator>(const Variable &b)
	{
		return *this > b.value;
	}
	Value Value::operator<=(const Variable &b)
	{
		return *this <= b.value;
	}
	Value Value::operator<(const Variable &b)
	{
		return *this < b.value;
	}

	Value Value::operator&&(const Variable &b)
	{
		return *this && b.value;
	}
	Value Value::operator||(const Variable &b)
	{
		return *this || b.value;
	}

	bool Value::GetBool()
	{
		if (isGarbage) return false;
		switch (type)
		{
		case DataType::INT: return bool(uv._int); break;
		case DataType::FLOAT: return bool(uv._float); break;
		case DataType::DOUBLE: return bool(uv._double); break;
		case DataType::BOOL: return bool(uv._bool); break;
		case DataType::CHAR: return bool(uv._char); break;
		default: return false;
		}
	}
}