#include "Value.h"
#include <iostream>

namespace ca {

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
	auto mul(T a, S b) -> decltype(a* b)
	{
		return a * b;
	}

	template <typename T, typename S>
	auto div(T a, S b) -> decltype(a / b)
	{
		return a / b;
	}

	template <typename T, typename S>
	auto mod(T a, S b) -> decltype(a% b)
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

	Value Value::operator+(Value& b)
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
	}

	Value Value::operator-(Value& b)
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
	}
	
	Value Value::operator*(Value& b)
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
	}

	Value Value::operator/(Value& b)
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
	}

	Value Value::operator%(Value& b)
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
	}

	template<typename T>
	Value Value::operator+(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this + _b;
	}

	template<typename T>
	Value Value::operator-(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this - _b;
	}

	template<typename T>
	Value Value::operator*(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this * _b;
	}

	template<typename T>
	Value Value::operator/(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this / _b;
	}

	template<typename T>
	Value Value::operator%(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this % _b;
	}

	template Value Value::operator+<int>(int b);
	template Value Value::operator-<int>(int b);
	template Value Value::operator*<int>(int b);
	template Value Value::operator/<int>(int b);
	template Value Value::operator%<int>(int b);

	template Value Value::operator+<float>(float b);
	template Value Value::operator-<float>(float b);
	template Value Value::operator*<float>(float b);
	template Value Value::operator/<float>(float b);
	template Value Value::operator%<float>(float b);

	template Value Value::operator+<double>(double b);
	template Value Value::operator-<double>(double b);
	template Value Value::operator*<double>(double b);
	template Value Value::operator/<double>(double b);
	template Value Value::operator%<double>(double b);

	template Value Value::operator+<bool>(bool b);
	template Value Value::operator-<bool>(bool b);
	template Value Value::operator*<bool>(bool b);
	template Value Value::operator/<bool>(bool b);
	template Value Value::operator%<bool>(bool b);

	template Value Value::operator+<char>(char b);
	template Value Value::operator-<char>(char b);
	template Value Value::operator*<char>(char b);
	template Value Value::operator/<char>(char b);
	template Value Value::operator%<char>(char b);

	bool Value::operator==(Value& b)
	{
		if (isGarbage or b.isGarbage) return false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: return equal(uv._int, b.uv._int);
			case DataType::FLOAT: return equal(uv._int, b.uv._float);
			case DataType::DOUBLE: return equal(uv._int, b.uv._double);
			case DataType::BOOL: return equal(uv._int, b.uv._bool);
			case DataType::CHAR: return equal(uv._int, b.uv._char);
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: return equal(uv._float, b.uv._int);
			case DataType::FLOAT: return equal(uv._float, b.uv._float);
			case DataType::DOUBLE: return equal(uv._float, b.uv._double);
			case DataType::BOOL: return equal(uv._float, b.uv._bool);
			case DataType::CHAR: return equal(uv._float, b.uv._char);
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: return equal(uv._double, b.uv._int);
			case DataType::FLOAT: return equal(uv._double, b.uv._float);
			case DataType::DOUBLE: return equal(uv._double, b.uv._double);
			case DataType::BOOL: return equal(uv._double, b.uv._bool);
			case DataType::CHAR: return equal(uv._double, b.uv._char);
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: return equal(uv._bool, b.uv._int);
			case DataType::FLOAT: return equal(uv._bool, b.uv._float);
			case DataType::DOUBLE: return equal(uv._bool, b.uv._double);
			case DataType::BOOL: return equal(uv._bool, b.uv._bool);
			case DataType::CHAR: return equal(uv._bool, b.uv._char);
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: return equal(uv._char, b.uv._int);
			case DataType::FLOAT: return equal(uv._char, b.uv._float);
			case DataType::DOUBLE: return equal(uv._char, b.uv._double);
			case DataType::BOOL: return equal(uv._char, b.uv._bool);
			case DataType::CHAR: return equal(uv._char, b.uv._char);
			}
			break;
		}
	}

	bool Value::operator!=(Value& b)
	{
		if (isGarbage or b.isGarbage) return false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: return not_equal(uv._int, b.uv._int);
			case DataType::FLOAT: return not_equal(uv._int, b.uv._float);
			case DataType::DOUBLE: return not_equal(uv._int, b.uv._double);
			case DataType::BOOL: return not_equal(uv._int, b.uv._bool);
			case DataType::CHAR: return not_equal(uv._int, b.uv._char);
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: return not_equal(uv._float, b.uv._int);
			case DataType::FLOAT: return not_equal(uv._float, b.uv._float);
			case DataType::DOUBLE: return not_equal(uv._float, b.uv._double);
			case DataType::BOOL: return not_equal(uv._float, b.uv._bool);
			case DataType::CHAR: return not_equal(uv._float, b.uv._char);
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: return not_equal(uv._double, b.uv._int);
			case DataType::FLOAT: return not_equal(uv._double, b.uv._float);
			case DataType::DOUBLE: return not_equal(uv._double, b.uv._double);
			case DataType::BOOL: return not_equal(uv._double, b.uv._bool);
			case DataType::CHAR: return not_equal(uv._double, b.uv._char);
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: return not_equal(uv._bool, b.uv._int);
			case DataType::FLOAT: return not_equal(uv._bool, b.uv._float);
			case DataType::DOUBLE: return not_equal(uv._bool, b.uv._double);
			case DataType::BOOL: return not_equal(uv._bool, b.uv._bool);
			case DataType::CHAR: return not_equal(uv._bool, b.uv._char);
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: return not_equal(uv._char, b.uv._int);
			case DataType::FLOAT: return not_equal(uv._char, b.uv._float);
			case DataType::DOUBLE: return not_equal(uv._char, b.uv._double);
			case DataType::BOOL: return not_equal(uv._char, b.uv._bool);
			case DataType::CHAR: return not_equal(uv._char, b.uv._char);
			}
			break;
		}
	}

	bool Value::operator>=(Value& b)
	{
		if (isGarbage or b.isGarbage) return false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: return eq_greater(uv._int, b.uv._int);
			case DataType::FLOAT: return eq_greater(uv._int, b.uv._float);
			case DataType::DOUBLE: return eq_greater(uv._int, b.uv._double);
			case DataType::BOOL: return eq_greater(uv._int, b.uv._bool);
			case DataType::CHAR: return eq_greater(uv._int, b.uv._char);
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: return eq_greater(uv._float, b.uv._int);
			case DataType::FLOAT: return eq_greater(uv._float, b.uv._float);
			case DataType::DOUBLE: return eq_greater(uv._float, b.uv._double);
			case DataType::BOOL: return eq_greater(uv._float, b.uv._bool);
			case DataType::CHAR: return eq_greater(uv._float, b.uv._char);
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: return eq_greater(uv._double, b.uv._int);
			case DataType::FLOAT: return eq_greater(uv._double, b.uv._float);
			case DataType::DOUBLE: return eq_greater(uv._double, b.uv._double);
			case DataType::BOOL: return eq_greater(uv._double, b.uv._bool);
			case DataType::CHAR: return eq_greater(uv._double, b.uv._char);
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: return eq_greater(uv._bool, b.uv._int);
			case DataType::FLOAT: return eq_greater(uv._bool, b.uv._float);
			case DataType::DOUBLE: return eq_greater(uv._bool, b.uv._double);
			case DataType::BOOL: return eq_greater(uv._bool, b.uv._bool);
			case DataType::CHAR: return eq_greater(uv._bool, b.uv._char);
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: return eq_greater(uv._char, b.uv._int);
			case DataType::FLOAT: return eq_greater(uv._char, b.uv._float);
			case DataType::DOUBLE: return eq_greater(uv._char, b.uv._double);
			case DataType::BOOL: return eq_greater(uv._char, b.uv._bool);
			case DataType::CHAR: return eq_greater(uv._char, b.uv._char);
			}
			break;
		}
	}

	bool Value::operator>(Value& b)
	{
		if (isGarbage or b.isGarbage) return false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: return greater(uv._int, b.uv._int);
			case DataType::FLOAT: return greater(uv._int, b.uv._float);
			case DataType::DOUBLE: return greater(uv._int, b.uv._double);
			case DataType::BOOL: return greater(uv._int, b.uv._bool);
			case DataType::CHAR: return greater(uv._int, b.uv._char);
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: return greater(uv._float, b.uv._int);
			case DataType::FLOAT: return greater(uv._float, b.uv._float);
			case DataType::DOUBLE: return greater(uv._float, b.uv._double);
			case DataType::BOOL: return greater(uv._float, b.uv._bool);
			case DataType::CHAR: return greater(uv._float, b.uv._char);
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: return greater(uv._double, b.uv._int);
			case DataType::FLOAT: return greater(uv._double, b.uv._float);
			case DataType::DOUBLE: return greater(uv._double, b.uv._double);
			case DataType::BOOL: return greater(uv._double, b.uv._bool);
			case DataType::CHAR: return greater(uv._double, b.uv._char);
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: return greater(uv._bool, b.uv._int);
			case DataType::FLOAT: return greater(uv._bool, b.uv._float);
			case DataType::DOUBLE: return greater(uv._bool, b.uv._double);
			case DataType::BOOL: return greater(uv._bool, b.uv._bool);
			case DataType::CHAR: return greater(uv._bool, b.uv._char);
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: return greater(uv._char, b.uv._int);
			case DataType::FLOAT: return greater(uv._char, b.uv._float);
			case DataType::DOUBLE: return greater(uv._char, b.uv._double);
			case DataType::BOOL: return greater(uv._char, b.uv._bool);
			case DataType::CHAR: return greater(uv._char, b.uv._char);
			}
			break;
		}
	}

	bool Value::operator<=(Value& b)
	{
		if (isGarbage or b.isGarbage) return false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: return eq_less(uv._int, b.uv._int);
			case DataType::FLOAT: return eq_less(uv._int, b.uv._float);
			case DataType::DOUBLE: return eq_less(uv._int, b.uv._double);
			case DataType::BOOL: return eq_less(uv._int, b.uv._bool);
			case DataType::CHAR: return eq_less(uv._int, b.uv._char);
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: return eq_less(uv._float, b.uv._int);
			case DataType::FLOAT: return eq_less(uv._float, b.uv._float);
			case DataType::DOUBLE: return eq_less(uv._float, b.uv._double);
			case DataType::BOOL: return eq_less(uv._float, b.uv._bool);
			case DataType::CHAR: return eq_less(uv._float, b.uv._char);
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: return eq_less(uv._double, b.uv._int);
			case DataType::FLOAT: return eq_less(uv._double, b.uv._float);
			case DataType::DOUBLE: return eq_less(uv._double, b.uv._double);
			case DataType::BOOL: return eq_less(uv._double, b.uv._bool);
			case DataType::CHAR: return eq_less(uv._double, b.uv._char);
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: return eq_less(uv._bool, b.uv._int);
			case DataType::FLOAT: return eq_less(uv._bool, b.uv._float);
			case DataType::DOUBLE: return eq_less(uv._bool, b.uv._double);
			case DataType::BOOL: return eq_less(uv._bool, b.uv._bool);
			case DataType::CHAR: return eq_less(uv._bool, b.uv._char);
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: return eq_less(uv._char, b.uv._int);
			case DataType::FLOAT: return eq_less(uv._char, b.uv._float);
			case DataType::DOUBLE: return eq_less(uv._char, b.uv._double);
			case DataType::BOOL: return eq_less(uv._char, b.uv._bool);
			case DataType::CHAR: return eq_less(uv._char, b.uv._char);
			}
			break;
		}
	}

	bool Value::operator<(Value& b)
	{
		if (isGarbage or b.isGarbage) return false;

		switch (type)
		{
		case DataType::INT:
			switch (b.type)
			{
			case DataType::INT: return less(uv._int, b.uv._int);
			case DataType::FLOAT: return less(uv._int, b.uv._float);
			case DataType::DOUBLE: return less(uv._int, b.uv._double);
			case DataType::BOOL: return less(uv._int, b.uv._bool);
			case DataType::CHAR: return less(uv._int, b.uv._char);
			}
			break;
		case DataType::FLOAT:
			switch (b.type)
			{
			case DataType::INT: return less(uv._float, b.uv._int);
			case DataType::FLOAT: return less(uv._float, b.uv._float);
			case DataType::DOUBLE: return less(uv._float, b.uv._double);
			case DataType::BOOL: return less(uv._float, b.uv._bool);
			case DataType::CHAR: return less(uv._float, b.uv._char);
			}
			break;
		case DataType::DOUBLE:
			switch (b.type)
			{
			case DataType::INT: return less(uv._double, b.uv._int);
			case DataType::FLOAT: return less(uv._double, b.uv._float);
			case DataType::DOUBLE: return less(uv._double, b.uv._double);
			case DataType::BOOL: return less(uv._double, b.uv._bool);
			case DataType::CHAR: return less(uv._double, b.uv._char);
			}
			break;
		case DataType::BOOL:
			switch (b.type)
			{
			case DataType::INT: return less(uv._bool, b.uv._int);
			case DataType::FLOAT: return less(uv._bool, b.uv._float);
			case DataType::DOUBLE: return less(uv._bool, b.uv._double);
			case DataType::BOOL: return less(uv._bool, b.uv._bool);
			case DataType::CHAR: return less(uv._bool, b.uv._char);
			}
			break;
		case DataType::CHAR:
			switch (b.type)
			{
			case DataType::INT: return less(uv._char, b.uv._int);
			case DataType::FLOAT: return less(uv._char, b.uv._float);
			case DataType::DOUBLE: return less(uv._char, b.uv._double);
			case DataType::BOOL: return less(uv._char, b.uv._bool);
			case DataType::CHAR: return less(uv._char, b.uv._char);
			}
			break;
		}
	}

	template <typename T>
	bool Value::operator==(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this == _b;
	}

	template <typename T>
	bool Value::operator!=(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this != _b;
	}

	template <typename T>
	bool Value::operator>=(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this >= _b;
	}

	template <typename T>
	bool Value::operator>(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this > _b;
	}

	template <typename T>
	bool Value::operator<=(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this <= _b;
	}

	template <typename T>
	bool Value::operator<(T b)
	{
		Value _b;
		_b.type = GetType(b);
		_b.uv.SetValue(b);
		return *this < _b;
	}

	template bool Value::operator==<int>(int b);
	template bool Value::operator!=<int>(int b);
	template bool Value::operator>=<int>(int b);
	template bool Value::operator> <int>(int b);
	template bool Value::operator<=<int>(int b);
	template bool Value::operator< <int>(int b);

	template bool Value::operator==<float>(float b);
	template bool Value::operator!=<float>(float b);
	template bool Value::operator>=<float>(float b);
	template bool Value::operator> <float>(float b);
	template bool Value::operator<=<float>(float b);
	template bool Value::operator< <float>(float b);

	template bool Value::operator==<double>(double b);
	template bool Value::operator!=<double>(double b);
	template bool Value::operator>=<double>(double b);
	template bool Value::operator> <double>(double b);
	template bool Value::operator<=<double>(double b);
	template bool Value::operator< <double>(double b);

	template bool Value::operator==<bool>(bool b);
	template bool Value::operator!=<bool>(bool b);
	template bool Value::operator>=<bool>(bool b);
	template bool Value::operator> <bool>(bool b);
	template bool Value::operator<=<bool>(bool b);
	template bool Value::operator< <bool>(bool b);

	template bool Value::operator==<char>(char b);
	template bool Value::operator!=<char>(char b);
	template bool Value::operator>=<char>(char b);
	template bool Value::operator> <char>(char b);
	template bool Value::operator<=<char>(char b);
	template bool Value::operator< <char>(char b);
}