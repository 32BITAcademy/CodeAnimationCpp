#pragma once
#include "BasicTypes.h"

namespace ca {

	class TempType
	{
	public:
		Value value;

		TempType(Value v) : value(v)
		{
		}
		TempType(const TempType& b) : value(b.value)
		{
		}
		operator bool()
		{
			return value.GetBool();
		}

//#pragma region TEMP-TEMP
//
//		TempType operator+(const TempType& b);
//		TempType operator-(const TempType& b);
//		TempType operator*(const TempType& b);
//		TempType operator/(const TempType& b);
//		TempType operator%(const TempType& b);
//
//		TempType operator==(const TempType& b);
//		TempType operator!=(const TempType& b);
//		TempType operator>=(const TempType& b);
//		TempType operator>(const TempType& b);
//		TempType operator<=(const TempType& b);
//		TempType operator<(const TempType& b);
//
//		TempType operator!();
//		TempType operator&&(const TempType& b);
//		TempType operator||(const TempType& b);
//
//#pragma endregion //TEMP-TEMP
//
//#pragma region TEMP-BASIC
//
//		template <typename T>
//		TempType operator+(const BasicType<T>& b);
//		template <typename T>
//		TempType operator-(const BasicType<T>& b);
//		template <typename T>
//		TempType operator*(const BasicType<T>& b);
//		template <typename T>
//		TempType operator/(const BasicType<T>& b);
//		template <typename T>
//		TempType operator%(const BasicType<T>& b);
//
//		template <typename T>
//		TempType operator==(const BasicType<T>& b);
//		template <typename T>
//		TempType operator!=(const BasicType<T>& b);
//		template <typename T>
//		TempType operator>=(const BasicType<T>& b);
//		template <typename T>
//		TempType operator>(const BasicType<T>& b);
//		template <typename T>
//		TempType operator<=(const BasicType<T>& b);
//		template <typename T>
//		TempType operator<(const BasicType<T>& b);
//
//		template <typename T>
//		TempType operator&&(const BasicType<T>& b);
//		template <typename T>
//		TempType operator||(const BasicType<T>& b);
//
//#pragma endregion //TEMP-BASIC
//
//#pragma region TEMP-NATIVE
//
//		template <typename T>
//		TempType operator+(T b);
//		template <typename T>
//		TempType operator-(T b);
//		template <typename T>
//		TempType operator*(T b);
//		template <typename T>
//		TempType operator/(T b);
//		template <typename T>
//		TempType operator%(T b);
//
//		template <typename T>
//		TempType operator==(T b);
//		template <typename T>
//		TempType operator!=(T b);
//		template <typename T>
//		TempType operator>=(T b);
//		template <typename T>
//		TempType operator>(T b);
//		template <typename T>
//		TempType operator<=(T b);
//		template <typename T>
//		TempType operator<(T b);
//
//		template <typename T>
//		TempType operator&&(T b);
//		template <typename T>
//		TempType operator||(T b);
//
//#pragma endregion //TEMP-NATIVE

#pragma region ARITHMETIC TEMP-TEMP

		TempType operator+(const TempType& b)
		{
			TempType res(value + b.value);
			SendArithmeticMSG(value, b.value, ArithmeticOper::ADDITION, res.value);
			return res;
		}

		TempType operator-(const TempType& b)
		{
			TempType res(value - b.value);
			SendArithmeticMSG(value, b.value, ArithmeticOper::SUBTRACTION, res.value);
			return res;
		}

		TempType operator*(const TempType& b)
		{
			TempType res(value * b.value);
			SendArithmeticMSG(value, b.value, ArithmeticOper::MULTIPLICATION, res.value);
			return res;
		}

		TempType operator/(const TempType& b)
		{
			TempType res(value / b.value);
			SendArithmeticMSG(value, b.value, ArithmeticOper::DIVISION, res.value);
			return res;
		}

		TempType operator%(const TempType& b)
		{
			TempType res(value % b.value);
			SendArithmeticMSG(value, b.value, ArithmeticOper::MODULO, res.value);
			return res;
		}

#pragma endregion //ARITHMETIC TEMP-TEMP

#pragma region COMPARE TEMP-TEMP

		TempType operator==(const TempType& b)
		{
			TempType res(value == b.value);
			SendCompareMSG(value, b.value, CompareOper::EQUAL, res.value);
			return res;
		}

		TempType operator!=(const TempType& b)
		{
			TempType res(value != b.value);
			SendCompareMSG(value, b.value, CompareOper::NOT_EQUAL, res.value);
			return res;
		}

		TempType operator>=(const TempType& b)
		{
			TempType res(value >= b.value);
			SendCompareMSG(value, b.value, CompareOper::EQ_GREATER, res.value);
			return res;
		}

		TempType operator>(const TempType& b)
		{
			TempType res(value > b.value);
			SendCompareMSG(value, b.value, CompareOper::GREATER, res.value);
			return res;
		}

		TempType operator<=(const TempType& b)
		{
			TempType res(value <= b.value);
			SendCompareMSG(value, b.value, CompareOper::EQ_LESSER, res.value);
			return res;
		}

		TempType operator<(const TempType& b)
		{
			TempType res(value < b.value);
			SendCompareMSG(value, b.value, CompareOper::LESSER, res.value);
			return res;
		}

#pragma endregion //COMPARE TEMP-TEMP

#pragma region LOGIC TEMP-TEMP

		TempType operator!()
		{
			TempType res(!value);
			SendLogicMSG(value, value, LogicOper::NOT, res.value);
			return res;
		}

		TempType operator&&(const TempType& b)
		{
			TempType res(value && b.value);
			SendLogicMSG(value, b.value, LogicOper::AND, res.value);
			return res;
		}

		TempType operator||(const TempType& b)
		{
			TempType res(value || b.value);
			SendLogicMSG(value, b.value, LogicOper::OR, res.value);
			return res;
		}

#pragma endregion //LOGIC TEMP-TEMP

#pragma region ARITHMETIC TEMP-BASIC

		template <typename T>
		TempType operator+(const BasicType<T>& b)
		{
			TempType res(value + b.var.value);
			SendArithmeticMSG(value, b.var, ArithmeticOper::ADDITION, res.value);
			return res;
		}

		template <typename T>
		TempType operator-(const BasicType<T>& b)
		{
			TempType res(value - b.var.value);
			SendArithmeticMSG(value, b.var, ArithmeticOper::SUBTRACTION, res.value);
			return res;
		}

		template <typename T>
		TempType operator*(const BasicType<T>& b)
		{
			TempType res(value * b.var.value);
			SendArithmeticMSG(value, b.var, ArithmeticOper::MULTIPLICATION, res.value);
			return res;
		}

		template <typename T>
		TempType operator/(const BasicType<T>& b)
		{
			TempType res(value / b.var.value);
			SendArithmeticMSG(value, b.var, ArithmeticOper::DIVISION, res.value);
			return res;
		}

		template <typename T>
		TempType operator%(const BasicType<T>& b)
		{
			TempType res(value % b.var.value);
			SendArithmeticMSG(value, b.var, ArithmeticOper::MODULO, res.value);
			return res;
		}

#pragma endregion //ARITHMETIC TEMP-BASIC

#pragma region COMPARE TEMP-BASIC

		template <typename T>
		TempType operator==(const BasicType<T>& b)
		{
			TempType res(value == b.var.value);
			SendCompareMSG(value, b.var, CompareOper::EQUAL, res.value);
			return res;
		}

		template <typename T>
		TempType operator!=(const BasicType<T>& b)
		{
			TempType res(value != b.var.value);
			SendCompareMSG(value, b.var, CompareOper::NOT_EQUAL, res.value);
			return res;
		}

		template <typename T>
		TempType operator>=(const BasicType<T>& b)
		{
			TempType res(value >= b.var.value);
			SendCompareMSG(value, b.var, CompareOper::EQ_GREATER, res.value);
			return res;
		}

		template <typename T>
		TempType operator>(const BasicType<T>& b)
		{
			TempType res(value > b.var.value);
			SendCompareMSG(value, b.var, CompareOper::GREATER, res.value);
			return res;
		}

		template <typename T>
		TempType operator<=(const BasicType<T>& b)
		{
			TempType res(value <= b.var.value);
			SendCompareMSG(value, b.var, CompareOper::EQ_LESSER, res.value);
			return res;
		}

		template <typename T>
		TempType operator<(const BasicType<T>& b)
		{
			TempType res(value < b.var.value);
			SendCompareMSG(value, b.var, CompareOper::LESSER, res.value);
			return res;
		}

#pragma endregion //COMPARE TEMP-BASIC

#pragma region LOGIC TEMP-BASIC

		template <typename T>
		TempType operator&&(const BasicType<T>& b)
		{
			TempType res(value && b.var.value);
			SendLogicMSG(value, b.var, LogicOper::AND, res.value);
			return res;
		}

		template <typename T>
		TempType operator||(const BasicType<T>& b)
		{
			TempType res(value || b.var.value);
			SendLogicMSG(value, b.var, LogicOper::OR, res.value);
			return res;
		}

#pragma endregion //LOGIC TEMP-BASIC

#pragma region ARITHMETIC TEMP-NATIVE

		template <typename T>
		TempType operator+(T b)
		{
			TempType res(value + Value(b));
			SendArithmeticMSG(value, Value(b), ArithmeticOper::ADDITION, res.value);
			return res;
		}

		template <typename T>
		TempType operator-(T b)
		{
			TempType res(value - Value(b));
			SendArithmeticMSG(value, Value(b), ArithmeticOper::SUBTRACTION, res.value);
			return res;
		}

		template <typename T>
		TempType operator*(T b)
		{
			TempType res(value * Value(b));
			SendArithmeticMSG(value, Value(b), ArithmeticOper::MULTIPLICATION, res.value);
			return res;
		}

		template <typename T>
		TempType operator/(T b)
		{
			TempType res(value / Value(b));
			SendArithmeticMSG(value, Value(b), ArithmeticOper::DIVISION, res.value);
			return res;
		}

		template <typename T>
		TempType operator%(T b)
		{
			TempType res(value % Value(b));
			SendArithmeticMSG(value, Value(b), ArithmeticOper::MODULO, res.value);
			return res;
		}

#pragma endregion //ARITHMETIC TEMP-NATIVE

#pragma region COMPARE TEMP-NATIVE

		template <typename T>
		TempType operator==(T b)
		{
			TempType res(value == Value(b));
			SendCompareMSG(value, Value(b), CompareOper::EQUAL, res.value);
			return res;
		}

		template <typename T>
		TempType operator!=(T b)
		{
			TempType res(value != Value(b));
			SendCompareMSG(value, Value(b), CompareOper::NOT_EQUAL, res.value);
			return res;
		}

		template <typename T>
		TempType operator>=(T b)
		{
			TempType res(value >= Value(b));
			SendCompareMSG(value, Value(b), CompareOper::EQ_GREATER, res.value);
			return res;
		}

		template <typename T>
		TempType operator>(T b)
		{
			TempType res(value > Value(b));
			SendCompareMSG(value, Value(b), CompareOper::GREATER, res.value);
			return res;
		}

		template <typename T>
		TempType operator<=(T b)
		{
			TempType res(value <= Value(b));
			SendCompareMSG(value, Value(b), CompareOper::EQ_LESSER, res.value);
			return res;
		}

		template <typename T>
		TempType operator<(T b)
		{
			TempType res(value < Value(b));
			SendCompareMSG(value, Value(b), CompareOper::LESSER, res.value);
			return res;
		}

#pragma endregion //COMPARE TEMP-NATIVE

#pragma region LOGIC TEMP-NATIVE

		template <typename T>
		TempType operator&&(T b)
		{
			TempType res(value && Value(b));
			SendLogicMSG(value, Value(b), LogicOper::AND, res.value);
			return res;
		}

		template <typename T>
		TempType operator||(T b)
		{
			TempType res(value || Value(b));
			SendLogicMSG(value, Value(b), LogicOper::OR, res.value);
			return res;
		}

#pragma endregion //LOGIC TEMP-NATIVE
		
	};

#pragma region NATIVE-TEMP
	template <typename T>
	TempType operator+(T a, const TempType& b);
	template <typename T>
	TempType operator-(T a, const TempType& b);
	template <typename T>
	TempType operator*(T a, const TempType& b);
	template <typename T>
	TempType operator/(T a, const TempType& b);
	template <typename T>
	TempType operator%(T a, const TempType& b);

	template <typename T>
	TempType operator==(T a, const TempType& b);
	template <typename T>
	TempType operator!=(T a, const TempType& b);
	template <typename T>
	TempType operator>=(T a, const TempType& b);
	template <typename T>
	TempType operator>(T a, const TempType& b);
	template <typename T>
	TempType operator<=(T a, const TempType& b);
	template <typename T>
	TempType operator<(T a, const TempType& b);

	template <typename T>
	TempType operator&&(T a, const TempType& b);
	template <typename T>
	TempType operator||(T a, const TempType& b);

#pragma endregion //NATIVE-TEMP

#pragma region NATIVE-BASIC

	template <typename T, typename S>
	TempType operator+(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator-(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator*(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator/(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator%(S a, const BasicType<T>& b);

	template <typename T, typename S>
	TempType operator==(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator!=(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator>=(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator>(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator<=(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator<(S a, const BasicType<T>& b);

	template <typename T, typename S>
	TempType operator&&(S a, const BasicType<T>& b);
	template <typename T, typename S>
	TempType operator||(S a, const BasicType<T>& b);

#pragma endregion //NATIVE-BASIC


#pragma region BASIC-TEMP

	template <typename T>
	TempType operator+(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator-(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator*(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator/(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator%(const BasicType<T>& a, const TempType& b);

	template <typename T>
	TempType operator==(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator!=(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator>=(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator>(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator<=(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator<(const BasicType<T>& a, const TempType& b);

	template <typename T>
	TempType operator&&(const BasicType<T>& a, const TempType& b);
	template <typename T>
	TempType operator||(const BasicType<T>& a, const TempType& b);

#pragma endregion //BASIC-TEMP

#pragma region BASIC-BASIC

	template <typename T, typename S>
	TempType operator+(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator-(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator*(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator/(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator%(const BasicType<T>& a, const BasicType<S>& b);

	template <typename T, typename S>
	TempType operator==(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator!=(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator>=(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator>(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator<=(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator<(const BasicType<T>& a, const BasicType<S>& b);

	template <typename T>
	TempType operator!(const BasicType<T>& a);
	template <typename T, typename S>
	TempType operator&&(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator||(const BasicType<T>& a, S b);

#pragma endregion //BASIC-BASIC

#pragma region BASIC-NATIVE

	template <typename T, typename S>
	TempType operator+(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator-(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator*(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator/(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator%(const BasicType<T>& a, S b);

	template <typename T, typename S>
	TempType operator==(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator!=(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator>=(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator>(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator<=(const BasicType<T>& a, S b);
	template <typename T, typename S>
	TempType operator<(const BasicType<T>& a, S b);

	template <typename T, typename S>
	TempType operator&&(const BasicType<T>& a, const BasicType<S>& b);
	template <typename T, typename S>
	TempType operator||(const BasicType<T>& a, const BasicType<S>& b);

#pragma endregion //BASIC-NATIVE

//#pragma region ARITHMETIC TEMP-TEMP
//
//	TempType TempType::operator+(const TempType& b)
//	{
//		TempType res(value + b.value);
//		SendArithmeticMSG(value, b.value, ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	TempType TempType::operator-(const TempType& b)
//	{
//		TempType res(value - b.value);
//		SendArithmeticMSG(value, b.value, ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	TempType TempType::operator*(const TempType& b)
//	{
//		TempType res(value * b.value);
//		SendArithmeticMSG(value, b.value, ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	TempType TempType::operator/(const TempType& b)
//	{
//		TempType res(value / b.value);
//		SendArithmeticMSG(value, b.value, ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	TempType TempType::operator%(const TempType& b)
//	{
//		TempType res(value % b.value);
//		SendArithmeticMSG(value, b.value, ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//#pragma endregion //ARITHMETIC TEMP-TEMP
//
//#pragma region COMPARE TEMP-TEMP
//
//	bool TempType::operator==(const TempType& b)
//	{
//		TempType res(value == b.value);
//		SendCompareMSG(value, b.value, CompareOper::EQUAL, res.value);
//		return res;
//	}
//
//	bool TempType::operator!=(const TempType& b)
//	{
//		TempType res(value != b.value);
//		SendCompareMSG(value, b.value, CompareOper::NOT_EQUAL, res.value);
//		return res;
//	}
//
//	bool TempType::operator>=(const TempType& b)
//	{
//		TempType res(value >= b.value);
//		SendCompareMSG(value, b.value, CompareOper::EQ_GREATER, res.value);
//		return res;
//	}
//
//	bool TempType::operator>(const TempType& b)
//	{
//		TempType res(value > b.value);
//		SendCompareMSG(value, b.value, CompareOper::GREATER, res.value);
//		return res;
//	}
//
//	bool TempType::operator<=(const TempType& b)
//	{
//		TempType res(value <= b.value);
//		SendCompareMSG(value, b.value, CompareOper::EQ_LESSER, res.value);
//		return res;
//	}
//
//	bool TempType::operator<(const TempType& b)
//	{
//		TempType res(value < b.value);
//		SendCompareMSG(value, b.value, CompareOper::LESSER, res.value);
//		return res;
//	}
//
//#pragma endregion //COMPARE TEMP-TEMP
//
//#pragma region LOGIC TEMP-TEMP
//
//	bool TempType::operator!()
//	{
//		TempType res(!value);
//		SendLogicMSG(value, value, LogicOper::NOT, res.value);
//		return res;
//	}
//
//	bool TempType::operator&&(const TempType& b)
//	{
//		TempType res(value && b.value);
//		SendLogicMSG(value, b.value, LogicOper::AND, res.value);
//		return res;
//	}
//
//	bool TempType::operator||(const TempType& b)
//	{
//		TempType res(value || b.value);
//		SendLogicMSG(value, b.value, LogicOper::OR, res.value);
//		return res;
//	}
//
//#pragma endregion //LOGIC TEMP-TEMP
//
//#pragma region ARITHMETIC TEMP-BASIC
//
//	template <typename T>
//	TempType TempType::operator+(const BasicType<T>& b)
//	{
//		TempType res(value + b.var.value);
//		SendArithmeticMSG(value, b.var, ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator-(const BasicType<T>& b)
//	{
//		TempType res(value - b.var.value);
//		SendArithmeticMSG(value, b.var, ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator*(const BasicType<T>& b)
//	{
//		TempType res(value * b.var.value);
//		SendArithmeticMSG(value, b.var, ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator/(const BasicType<T>& b)
//	{
//		TempType res(value / b.var.value);
//		SendArithmeticMSG(value, b.var, ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator%(const BasicType<T>& b)
//	{
//		TempType res(value % b.var.value);
//		SendArithmeticMSG(value, b.var, ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//#pragma endregion //ARITHMETIC TEMP-BASIC
//
//#pragma region COMPARE TEMP-BASIC
//
//	template <typename T>
//	bool TempType::operator==(const BasicType<T>& b)
//	{
//		TempType res(value == b.var.value);
//		SendCompareMSG(value, b.var, CompareOper::EQUAL, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator!=(const BasicType<T>& b)
//	{
//		TempType res(value != b.var.value);
//		SendCompareMSG(value, b.var, CompareOper::NOT_EQUAL, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator>=(const BasicType<T>& b)
//	{
//		TempType res(value >= b.var.value);
//		SendCompareMSG(value, b.var, CompareOper::EQ_GREATER, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator>(const BasicType<T>& b)
//	{
//		TempType res(value > b.var.value);
//		SendCompareMSG(value, b.var, CompareOper::GREATER, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator<=(const BasicType<T>& b)
//	{
//		TempType res(value <= b.var.value);
//		SendCompareMSG(value, b.var, CompareOper::EQ_LESSER, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator<(const BasicType<T>& b)
//	{
//		TempType res(value < b.var.value);
//		SendCompareMSG(value, b.var, CompareOper::LESSER, res.value);
//		return res;
//	}
//
//#pragma endregion //COMPARE TEMP-BASIC
//
//#pragma region LOGIC TEMP-BASIC
//
//	template <typename T>
//	bool TempType::operator&&(const BasicType<T>& b)
//	{
//		TempType res(value && b.var.value);
//		SendLogicMSG(value, b.var, LogicOper::AND, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator||(const BasicType<T>& b)
//	{
//		TempType res(value || b.var.value);
//		SendLogicMSG(value, b.var, LogicOper::OR, res.value);
//		return res;
//	}
//
//#pragma endregion //LOGIC TEMP-BASIC
//
//#pragma region ARITHMETIC TEMP-NATIVE
//
//	template <typename T>
//	TempType TempType::operator+(T b)
//	{
//		TempType res(value + Value(b));
//		SendArithmeticMSG(value, Value(b), ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator-(T b)
//	{
//		TempType res(value - Value(b));
//		SendArithmeticMSG(value, Value(b), ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator*(T b)
//	{
//		TempType res(value * Value(b));
//		SendArithmeticMSG(value, Value(b), ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator/(T b)
//	{
//		TempType res(value / Value(b));
//		SendArithmeticMSG(value, Value(b), ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	TempType TempType::operator%(T b)
//	{
//		TempType res(value % Value(b));
//		SendArithmeticMSG(value, Value(b), ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//#pragma endregion //ARITHMETIC TEMP-NATIVE
//
//#pragma region COMPARE TEMP-NATIVE
//
//	template <typename T>
//	bool TempType::operator==(T b)
//	{
//		TempType res(value == Value(b));
//		SendCompareMSG(value, Value(b), CompareOper::EQUAL, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator!=(T b)
//	{
//		TempType res(value != Value(b));
//		SendCompareMSG(value, Value(b), CompareOper::NOT_EQUAL, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator>=(T b)
//	{
//		TempType res(value >= Value(b));
//		SendCompareMSG(value, Value(b), CompareOper::EQ_GREATER, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator>(T b)
//	{
//		TempType res(value > Value(b));
//		SendCompareMSG(value, Value(b), CompareOper::GREATER, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator<=(T b)
//	{
//		TempType res(value <= Value(b));
//		SendCompareMSG(value, Value(b), CompareOper::EQ_LESSER, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator<(T b)
//	{
//		TempType res(value < Value(b));
//		SendCompareMSG(value, Value(b), CompareOper::LESSER, res.value);
//		return res;
//	}
//
//#pragma endregion //COMPARE TEMP-NATIVE
//
//#pragma region LOGIC TEMP-NATIVE
//
//	template <typename T>
//	bool TempType::operator&&(T b)
//	{
//		TempType res(value && Value(b));
//		SendLogicMSG(value, Value(b), LogicOper::AND, res.value);
//		return res;
//	}
//
//	template <typename T>
//	bool TempType::operator||(T b)
//	{
//		TempType res(value || Value(b));
//		SendLogicMSG(value, Value(b), LogicOper::OR, res.value);
//		return res;
//	}
//
//#pragma endregion //LOGIC TEMP-NATIVE

#pragma region ARITHMETIC NATIVE-TEMP

	template <typename T>
	TempType operator+(T a, const TempType& b)
	{
		TempType res(Value(a) + b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T>
	TempType operator-(T a, const TempType& b)
	{
		TempType res(Value(a) - b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T>
	TempType operator*(T a, const TempType& b)
	{
		TempType res(Value(a) * b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T>
	TempType operator/(T a, const TempType& b)
	{
		TempType res(Value(a) / b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T>
	TempType operator%(T a, const TempType& b)
	{
		TempType res(Value(a) % b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC NATIVE-TEMP

#pragma region COMPARE NATIVE-TEMP

	template <typename T>
	TempType operator==(T a, const TempType& b)
	{
		TempType res(Value(a) == b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T>
	TempType operator!=(T a, const TempType& b)
	{
		TempType res(Value(a) != b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T>
	TempType operator>=(T a, const TempType& b)
	{
		TempType res(Value(a) >= b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T>
	TempType operator>(T a, const TempType& b)
	{
		TempType res(Value(a) > b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T>
	TempType operator<=(T a, const TempType& b)
	{
		TempType res(Value(a) <= b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T>
	TempType operator<(T a, const TempType& b)
	{
		TempType res(Value(a) < b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE NATIVE-TEMP

#pragma region LOGIC NATIVE-TEMP

	template <typename T>
	TempType operator&&(T a, const TempType& b)
	{
		TempType res(Value(a) && b.value);
		SendLogicMSG(Value(a), b.value, LogicOper::AND, res.value);
		return res;
	}

	template <typename T>
	TempType operator||(T a, const TempType& b)
	{
		TempType res(Value(a) || b.value);
		SendLogicMSG(Value(a), b.value, LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC NATIVE-TEMP

#pragma region ARITHMETIC NATIVE-BASIC

	template <typename T, typename S>
	TempType operator+(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) + b.var.value);
		SendArithmeticMSG(Value(a), b.var, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator-(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) - b.var.value);
		SendArithmeticMSG(Value(a), b.var, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator*(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) * b.var.value);
		SendArithmeticMSG(Value(a), b.var, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator/(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) / b.var.value);
		SendArithmeticMSG(Value(a), b.var, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator%(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) % b.var.value);
		SendArithmeticMSG(Value(a), b.var, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC NATIVE-BASIC

#pragma region COMPARE NATIVE-BASIC

	template <typename T, typename S>
	TempType operator==(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) == b.var.value);
		SendCompareMSG(Value(a), b.var, CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator!=(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) != b.var.value);
		SendCompareMSG(Value(a), b.var, CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator>=(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) >= b.var.value);
		SendCompareMSG(Value(a), b.var, CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator>(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) > b.var.value);
		SendCompareMSG(Value(a), b.var, CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator<=(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) <= b.var.value);
		SendCompareMSG(Value(a), b.var, CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator<(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) < b.var.value);
		SendCompareMSG(Value(a), b.var, CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE NATIVE-BASIC

#pragma region LOGIC NATIVE-BASIC

	template <typename T, typename S>
	TempType operator&&(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) && b.var.value);
		SendLogicMSG(Value(a), b.var, LogicOper::AND, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator||(T a, const BasicType<S>& b)
	{
		TempType res(Value(a) || b.var.value);
		SendLogicMSG(Value(a), b.var, LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC NATIVE-BASIC

#pragma region ARITHMETIC BASIC-TEMP

	template <typename T>
	TempType operator+(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value + b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T>
	TempType operator-(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value - b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T>
	TempType operator*(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value * b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T>
	TempType operator/(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value / b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T>
	TempType operator%(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value % b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC BASIC-TEMP

#pragma region COMPARE BASIC-TEMP

	template <typename T>
	TempType operator==(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value == b.value);
		SendCompareMSG(a.var, b.value, CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T>
	TempType operator!=(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value != b.value);
		SendCompareMSG(a.var, b.value, CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T>
	TempType operator>=(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value >= b.value);
		SendCompareMSG(a.var, b.value, CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T>
	TempType operator>(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value > b.value);
		SendCompareMSG(a.var, b.value, CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T>
	TempType operator<=(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value <= b.value);
		SendCompareMSG(a.var, b.value, CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T>
	TempType operator<(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value < b.value);
		SendCompareMSG(a.var, b.value, CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE BASIC-TEMP

#pragma region LOGIC BASIC-TEMP

	template <typename T>
	TempType operator&&(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value && b.value);
		SendLogicMSG(a.var, b.value, LogicOper::AND, res.value);
		return res;
	}

	template <typename T>
	TempType operator||(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value || b.value);
		SendLogicMSG(a.var, b.value, LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC BASIC-TEMP

#pragma region ARITHMETIC BASIC-BASIC

	template <typename T, typename S>
	TempType operator+(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value + b.var.value);
		SendArithmeticMSG(a.var, b.var, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator-(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value - b.var.value);
		SendArithmeticMSG(a.var, b.var, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator*(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value * b.var.value);
		SendArithmeticMSG(a.var, b.var, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator/(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value / b.var.value);
		SendArithmeticMSG(a.var, b.var, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator%(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value % b.var.value);
		SendArithmeticMSG(a.var, b.var, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC BASIC-BASIC

#pragma region COMPARE BASIC-BASIC

	template <typename T, typename S>
	TempType operator==(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value == b.var.value);
		SendCompareMSG(a.var, b.var, CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator!=(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value != b.var.value);
		SendCompareMSG(a.var, b.var, CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator>=(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value >= b.var.value);
		SendCompareMSG(a.var, b.var, CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator>(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value > b.var.value);
		SendCompareMSG(a.var, b.var, CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator<=(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value <= b.var.value);
		SendCompareMSG(a.var, b.var, CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator<(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value < b.var.value);
		SendCompareMSG(a.var, b.var, CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE BASIC-BASIC

#pragma region LOGIC BASIC-BASIC
	template <typename T>
	TempType operator!(const BasicType<T>& a)
	{
		TempType res(!a.var.value);
		SendLogicMSG(a.var, a.var, LogicOper::NOT, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator&&(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value && b.var.value);
		SendLogicMSG(a.var, b.var, LogicOper::AND, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator||(const BasicType<T>& a, const BasicType<S>& b)
	{
		TempType res(a.var.value || b.var.value);
		SendLogicMSG(a.var, b.var, LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC BASIC-BASIC

#pragma region ARITHMETIC BASIC-NATIVE

	template <typename T, typename S>
	TempType operator+(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value + Value(b));
		SendArithmeticMSG(a.var, Value(b), ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator-(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value - Value(b));
		SendArithmeticMSG(a.var, Value(b), ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator*(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value * Value(b));
		SendArithmeticMSG(a.var, Value(b), ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator/(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value / Value(b));
		SendArithmeticMSG(a.var, Value(b), ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator%(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value % Value(b));
		SendArithmeticMSG(a.var, Value(b), ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC BASIC-NATIVE

#pragma region COMPARE BASIC-NATIVE

	template <typename T, typename S>
	TempType operator==(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value == Value(b));
		SendCompareMSG(a.var, Value(b), CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator!=(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value != Value(b));
		SendCompareMSG(a.var, Value(b), CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator>=(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value >= Value(b));
		SendCompareMSG(a.var, Value(b), CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator>(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value > Value(b));
		SendCompareMSG(a.var, Value(b), CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator<=(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value <= Value(b));
		SendCompareMSG(a.var, Value(b), CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator<(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value < Value(b));
		SendCompareMSG(a.var, Value(b), CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE BASIC-NATIVE

#pragma region LOGIC BASIC-NATIVE

	template <typename T, typename S>
	TempType operator&&(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value && Value(b));
		SendLogicMSG(a.var, Value(b), LogicOper::AND, res.value);
		return res;
	}

	template <typename T, typename S>
	TempType operator||(const BasicType<T>& a, S b)
	{
		TempType res(a.var.value || Value(b));
		SendLogicMSG(a.var, Value(b), LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC BASIC-NATIVE

	std::ostream& operator<<(std::ostream& out, TempType a);

}