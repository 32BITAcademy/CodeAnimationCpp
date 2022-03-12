#include "TempType.h"

namespace ca {

	TempType::TempType(Value v) : value (v)
	{
	}

	TempType::TempType(const TempType& b) : value(b.value)
	{
	}

	TempType::operator bool()
	{
		return value.GetBool();
	}

#pragma region ARITHMETIC TEMP-TEMP

	const TempType TempType::operator+(const TempType& b)
	{
		TempType res(value + b.value);
		SendArithmeticMSG(value, b.value, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	const TempType TempType::operator-(const TempType& b)
	{
		TempType res(value - b.value);
		SendArithmeticMSG(value, b.value, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	const TempType TempType::operator*(const TempType& b)
	{
		TempType res(value * b.value);
		SendArithmeticMSG(value, b.value, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	const TempType TempType::operator/(const TempType& b)
	{
		TempType res(value / b.value);
		SendArithmeticMSG(value, b.value, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	const TempType TempType::operator%(const TempType& b)
	{
		TempType res(value % b.value);
		SendArithmeticMSG(value, b.value, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC TEMP-TEMP

#pragma region COMPARE TEMP-TEMP
	
	bool TempType::operator==(const TempType& b)
	{
		TempType res(value == b.value);
		SendCompareMSG(value, b.value, CompareOper::EQUAL, res.value);
		return res;
	}

	bool TempType::operator!=(const TempType& b)
	{
		TempType res(value != b.value);
		SendCompareMSG(value, b.value, CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	bool TempType::operator>=(const TempType& b)
	{
		TempType res(value >= b.value);
		SendCompareMSG(value, b.value, CompareOper::EQ_GREATER, res.value);
		return res;
	}

	bool TempType::operator>(const TempType& b)
	{
		TempType res(value > b.value);
		SendCompareMSG(value, b.value, CompareOper::GREATER, res.value);
		return res;
	}

	bool TempType::operator<=(const TempType& b)
	{
		TempType res(value <= b.value);
		SendCompareMSG(value, b.value, CompareOper::EQ_LESSER, res.value);
		return res;
	}

	bool TempType::operator<(const TempType& b)
	{
		TempType res(value < b.value);
		SendCompareMSG(value, b.value, CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE TEMP-TEMP

#pragma region LOGIC TEMP-TEMP

	bool TempType::operator!()
	{
		TempType res(!value);
		SendLogicMSG(value, value, LogicOper::NOT, res.value);
		return res;
	}

	bool TempType::operator&&(const TempType& b)
	{
		TempType res(value && b.value);
		SendLogicMSG(value, b.value, LogicOper::AND, res.value);
		return res;
	}

	bool TempType::operator||(const TempType& b)
	{
		TempType res(value || b.value);
		SendLogicMSG(value, b.value, LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC TEMP-TEMP

#pragma region ARITHMETIC TEMP-BASIC

	template <typename T>
	const TempType TempType::operator+(const BasicType<T>& b)
	{
		TempType res(value + b.var.value);
		SendArithmeticMSG(value, b.var, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator-(const BasicType<T>& b)
	{
		TempType res(value - b.var.value);
		SendArithmeticMSG(value, b.var, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator*(const BasicType<T>& b)
	{
		TempType res(value * b.var.value);
		SendArithmeticMSG(value, b.var, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator/(const BasicType<T>& b)
	{
		TempType res(value / b.var.value);
		SendArithmeticMSG(value, b.var, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator%(const BasicType<T>& b)
	{
		TempType res(value % b.var.value);
		SendArithmeticMSG(value, b.var, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC TEMP-BASIC

#pragma region COMPARE TEMP-BASIC

	template <typename T>
	bool TempType::operator==(const BasicType<T>& b)
	{
		TempType res(value == b.var.value);
		SendCompareMSG(value, b.var, CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator!=(const BasicType<T>& b)
	{
		TempType res(value != b.var.value);
		SendCompareMSG(value, b.var, CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator>=(const BasicType<T>& b)
	{
		TempType res(value >= b.var.value);
		SendCompareMSG(value, b.var, CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator>(const BasicType<T>& b)
	{
		TempType res(value > b.var.value);
		SendCompareMSG(value, b.var, CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator<=(const BasicType<T>& b)
	{
		TempType res(value <= b.var.value);
		SendCompareMSG(value, b.var, CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator<(const BasicType<T>& b)
	{
		TempType res(value < b.var.value);
		SendCompareMSG(value, b.var, CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE TEMP-BASIC

#pragma region LOGIC TEMP-BASIC

	template <typename T>
	bool TempType::operator&&(const BasicType<T>& b)
	{
		TempType res(value && b.var.value);
		SendLogicMSG(value, b.var, LogicOper::AND, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator||(const BasicType<T>& b)
	{
		TempType res(value || b.var.value);
		SendLogicMSG(value, b.var, LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC TEMP-BASIC

#pragma region ARITHMETIC TEMP-NATIVE

	template <typename T>
	const TempType TempType::operator+(T b)
	{
		TempType res(value + b);
		SendArithmeticMSG(value, Value(b), ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator-(T b)
	{
		TempType res(value - b);
		SendArithmeticMSG(value, Value(b), ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator*(T b)
	{
		TempType res(value * b);
		SendArithmeticMSG(value, Value(b), ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator/(T b)
	{
		TempType res(value / b);
		SendArithmeticMSG(value, Value(b), ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T>
	const TempType TempType::operator%(T b)
	{
		TempType res(value % b);
		SendArithmeticMSG(value, Value(b), ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC TEMP-NATIVE

#pragma region COMPARE TEMP-NATIVE

	template <typename T>
	bool TempType::operator==(T b)
	{
		TempType res(value == Value(b));
		SendCompareMSG(value, Value(b), CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator!=(T b)
	{
		TempType res(value != Value(b));
		SendCompareMSG(value, Value(b), CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator>=(T b)
	{
		TempType res(value >= Value(b));
		SendCompareMSG(value, Value(b), CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator>(T b)
	{
		TempType res(value > Value(b));
		SendCompareMSG(value, Value(b), CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator<=(T b)
	{
		TempType res(value <= Value(b));
		SendCompareMSG(value, Value(b), CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator<(T b)
	{
		TempType res(value < Value(b));
		SendCompareMSG(value, Value(b), CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE TEMP-NATIVE

#pragma region LOGIC TEMP-NATIVE

	template <typename T>
	bool TempType::operator&&(T b)
	{
		TempType res(value && Value(b));
		SendLogicMSG(value, Value(b), LogicOper::AND, res.value);
		return res;
	}

	template <typename T>
	bool TempType::operator||(T b)
	{
		TempType res(value || Value(b));
		SendLogicMSG(value, Value(b), LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC TEMP-NATIVE

#pragma region ARITHMETIC NATIVE-TEMP

	template <typename T>
	const TempType operator+(T a, const TempType& b)
	{
		TempType res(Value(a) + b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator-(T a, const TempType& b)
	{
		TempType res(Value(a) - b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator*(T a, const TempType& b)
	{
		TempType res(Value(a) * b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator/(T a, const TempType& b)
	{
		TempType res(Value(a) / b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator%(T a, const TempType& b)
	{
		TempType res(Value(a) % b.value);
		SendArithmeticMSG(Value(a), b.value, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC NATIVE-TEMP

#pragma region COMPARE NATIVE-TEMP

	template <typename T>
	bool operator==(T a, const TempType& b)
	{
		TempType res(Value(a) == b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::EQUAL, res.value);
		return res;
	}

	template <typename T>
	bool operator!=(T a, const TempType& b)
	{
		TempType res(Value(a) != b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::NOT_EQUAL, res.value);
		return res;
	}

	template <typename T>
	bool operator>=(T a, const TempType& b)
	{
		TempType res(Value(a) >= b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::EQ_GREATER, res.value);
		return res;
	}

	template <typename T>
	bool operator>(T a, const TempType& b)
	{
		TempType res(Value(a) > b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::GREATER, res.value);
		return res;
	}

	template <typename T>
	bool operator<=(T a, const TempType& b)
	{
		TempType res(Value(a) <= b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::EQ_LESSER, res.value);
		return res;
	}

	template <typename T>
	bool operator<(T a, const TempType& b)
	{
		TempType res(Value(a) < b.value);
		SendCompareMSG(Value(a), b.value, CompareOper::LESSER, res.value);
		return res;
	}

#pragma endregion //COMPARE NATIVE-TEMP

#pragma region LOGIC NATIVE-TEMP

	template <typename T>
	bool operator&&(T a, const TempType& b)
	{
		TempType res(Value(a) && b.value);
		SendLogicMSG(Value(a), b.value, LogicOper::AND, res.value);
		return res;
	}

	template <typename T>
	bool operator||(T a, const TempType& b)
	{
		TempType res(Value(a) || b.value);
		SendLogicMSG(Value(a), b.value, LogicOper::OR, res.value);
		return res;
	}

#pragma endregion //LOGIC NATIVE-TEMP

#pragma region ARITHMETIC BASIC-TEMP

	template <typename T>
	const TempType operator+(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value + b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::ADDITION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator-(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value - b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::SUBTRACTION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator*(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value * b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::MULTIPLICATION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator/(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value / b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::DIVISION, res.value);
		return res;
	}

	template <typename T>
	const TempType operator%(const BasicType<T>& a, const TempType& b)
	{
		TempType res(a.var.value % b.value);
		SendArithmeticMSG(a.var, b.value, ArithmeticOper::MODULO, res.value);
		return res;
	}

#pragma endregion //ARITHMETIC BASIC-TEMP

	template const TempType TempType::operator+<int>(const BasicType<int>& b);
	template const TempType TempType::operator-<int>(const BasicType<int>& b);
	template const TempType TempType::operator*<int>(const BasicType<int>& b);
	template const TempType TempType::operator/<int>(const BasicType<int>& b);
	template const TempType TempType::operator%<int>(const BasicType<int>& b);

	template const TempType TempType::operator+<float>(const BasicType<float>& b);
	template const TempType TempType::operator-<float>(const BasicType<float>& b);
	template const TempType TempType::operator*<float>(const BasicType<float>& b);
	template const TempType TempType::operator/<float>(const BasicType<float>& b);
	template const TempType TempType::operator%<float>(const BasicType<float>& b);

	template const TempType TempType::operator+<double>(const BasicType<double>& b);
	template const TempType TempType::operator-<double>(const BasicType<double>& b);
	template const TempType TempType::operator*<double>(const BasicType<double>& b);
	template const TempType TempType::operator/<double>(const BasicType<double>& b);
	template const TempType TempType::operator%<double>(const BasicType<double>& b);

	template const TempType TempType::operator+<bool>(const BasicType<bool>& b);
	template const TempType TempType::operator-<bool>(const BasicType<bool>& b);
	template const TempType TempType::operator*<bool>(const BasicType<bool>& b);
	template const TempType TempType::operator/<bool>(const BasicType<bool>& b);
	template const TempType TempType::operator%<bool>(const BasicType<bool>& b);

	template const TempType TempType::operator+<char>(const BasicType<char>& b);
	template const TempType TempType::operator-<char>(const BasicType<char>& b);
	template const TempType TempType::operator*<char>(const BasicType<char>& b);
	template const TempType TempType::operator/<char>(const BasicType<char>& b);
	template const TempType TempType::operator%<char>(const BasicType<char>& b);

	template const TempType TempType::operator+<int>(int b);
	template const TempType TempType::operator-<int>(int b);
	template const TempType TempType::operator*<int>(int b);
	template const TempType TempType::operator/<int>(int b);
	template const TempType TempType::operator%<int>(int b);

	template const TempType TempType::operator+<float>(float b);
	template const TempType TempType::operator-<float>(float b);
	template const TempType TempType::operator*<float>(float b);
	template const TempType TempType::operator/<float>(float b);
	template const TempType TempType::operator%<float>(float b);

	template const TempType TempType::operator+<double>(double b);
	template const TempType TempType::operator-<double>(double b);
	template const TempType TempType::operator*<double>(double b);
	template const TempType TempType::operator/<double>(double b);
	template const TempType TempType::operator%<double>(double b);

	template const TempType TempType::operator+<bool>(bool b);
	template const TempType TempType::operator-<bool>(bool b);
	template const TempType TempType::operator*<bool>(bool b);
	template const TempType TempType::operator/<bool>(bool b);
	template const TempType TempType::operator%<bool>(bool b);

	template const TempType TempType::operator+<char>(char b);
	template const TempType TempType::operator-<char>(char b);
	template const TempType TempType::operator*<char>(char b);
	template const TempType TempType::operator/<char>(char b);
	template const TempType TempType::operator%<char>(char b);

	template const TempType operator+<int>(int a, const TempType& b);
	template const TempType operator-<int>(int a, const TempType& b);
	template const TempType operator*<int>(int a, const TempType& b);
	template const TempType operator/<int>(int a, const TempType& b);
	template const TempType operator%<int>(int a, const TempType& b);

	template const TempType operator+<float>(float a, const TempType& b);
	template const TempType operator-<float>(float a, const TempType& b);
	template const TempType operator*<float>(float a, const TempType& b);
	template const TempType operator/<float>(float a, const TempType& b);
	template const TempType operator%<float>(float a, const TempType& b);

	template const TempType operator+<double>(double a, const TempType& b);
	template const TempType operator-<double>(double a, const TempType& b);
	template const TempType operator*<double>(double a, const TempType& b);
	template const TempType operator/<double>(double a, const TempType& b);
	template const TempType operator%<double>(double a, const TempType& b);

	template const TempType operator+<bool>(bool a, const TempType& b);
	template const TempType operator-<bool>(bool a, const TempType& b);
	template const TempType operator*<bool>(bool a, const TempType& b);
	template const TempType operator/<bool>(bool a, const TempType& b);
	template const TempType operator%<bool>(bool a, const TempType& b);

	template const TempType operator+<char>(char a, const TempType& b);
	template const TempType operator-<char>(char a, const TempType& b);
	template const TempType operator*<char>(char a, const TempType& b);
	template const TempType operator/<char>(char a, const TempType& b);
	template const TempType operator%<char>(char a, const TempType& b);

	template const TempType operator+<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator-<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator*<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator/<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator%<int>(const BasicType<int>& a, const TempType& b);

	template const TempType operator+<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator-<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator*<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator/<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator%<int>(const BasicType<int>& a, const TempType& b);

	template const TempType operator+<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator-<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator*<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator/<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator%<int>(const BasicType<int>& a, const TempType& b);

	template const TempType operator+<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator-<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator*<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator/<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator%<int>(const BasicType<int>& a, const TempType& b);

	template const TempType operator+<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator-<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator*<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator/<int>(const BasicType<int>& a, const TempType& b);
	template const TempType operator%<int>(const BasicType<int>& a, const TempType& b);
	
}