//#include "TempType.h"
//
//namespace ca {
//
//	TempType::TempType(Value v) : value (v)
//	{
//	}
//
//	TempType::TempType(const TempType& b) : value(b.value)
//	{
//	}
//
//	const TempType TempType::operator+(TempType& b)
//	{
//		TempType res = value + b.value;
//		SendAritmeticMSG(value, b.value, ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	const TempType TempType::operator-(TempType& b)
//	{
//		TempType res = value - b.value;
//		SendAritmeticMSG(value, b.value, ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	const TempType TempType::operator*(TempType& b)
//	{
//		TempType res = value * b.value;
//		SendAritmeticMSG(value, b.value, ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	const TempType TempType::operator/(TempType& b)
//	{
//		TempType res = value / b.value;
//		SendAritmeticMSG(value, b.value, ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	const TempType TempType::operator%(TempType& b)
//	{
//		TempType res = value % b.value;
//		SendAritmeticMSG(value, b.value, ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator+(BasicType<T>& b)
//	{
//		TempType res = value + b.var;
//		SendAritmeticMSG(value, b.var, ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator-(BasicType<T>& b)
//	{
//		TempType res = value - b.var;
//		SendAritmeticMSG(value, b.var, ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator*(BasicType<T>& b)
//	{
//		TempType res = value * b.var;
//		SendAritmeticMSG(value, b.var, ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator/(BasicType<T>& b)
//	{
//		TempType res = value / b.var;
//		SendAritmeticMSG(value, b.var, ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator%(BasicType<T>& b)
//	{
//		TempType res = value % b.var;
//		SendAritmeticMSG(value, b.var, ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator+(T b)
//	{
//		TempType res = value + b;
//		SendAritmeticMSG(value, Value(b), ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator-(T b)
//	{
//		TempType res = value - b;
//		SendAritmeticMSG(value, Value(b), ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator*(T b)
//	{
//		TempType res = value * b;
//		SendAritmeticMSG(value, Value(b), ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator/(T b)
//	{
//		TempType res = value / b;
//		SendAritmeticMSG(value, Value(b), ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType TempType::operator%(T b)
//	{
//		TempType res = value % b;
//		SendAritmeticMSG(value, Value(b), ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator+(T a, TempType& b)
//	{
//		TempType res = a + b.value;
//		SendAritmeticMSG(Value(a), b.value, ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator-(T a, TempType& b)
//	{
//		TempType res = a - b.value;
//		SendAritmeticMSG(Value(a), b.value, ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator*(T a, TempType& b)
//	{
//		TempType res = a * b.value;
//		SendAritmeticMSG(Value(a), b.value, ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator/(T a, TempType& b)
//	{
//		TempType res = a / b.value;
//		SendAritmeticMSG(Value(a), b.value, ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator%(T a, TempType& b)
//	{
//		TempType res = a % b.value;
//		SendAritmeticMSG(Value(a), b.value, ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator+(BasicType<T>& a, TempType& b)
//	{
//		TempType res = a.var + b.value;
//		SendAritmeticMSG(a.var, b.value, ArithmeticOper::ADDITION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator-(BasicType<T>& a, TempType& b)
//	{
//		TempType res = a.var - b.value;
//		SendAritmeticMSG(a.var, b.value, ArithmeticOper::SUBTRACTION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator*(BasicType<T>& a, TempType& b)
//	{
//		TempType res = a.var * b.value;
//		SendAritmeticMSG(a.var, b.value, ArithmeticOper::MULTIPLICATION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator/(BasicType<T>& a, TempType& b)
//	{
//		TempType res = a.var / b.value;
//		SendAritmeticMSG(a.var, b.value, ArithmeticOper::DIVISION, res.value);
//		return res;
//	}
//
//	template <typename T>
//	const TempType operator%(BasicType<T>& a, TempType& b)
//	{
//		TempType res = a.var % b.value;
//		SendAritmeticMSG(a.var, b.value, ArithmeticOper::MODULO, res.value);
//		return res;
//	}
//
//	template const TempType TempType::operator+<int>(BasicType<int>& b);
//	template const TempType TempType::operator-<int>(BasicType<int>& b);
//	template const TempType TempType::operator*<int>(BasicType<int>& b);
//	template const TempType TempType::operator/<int>(BasicType<int>& b);
//	template const TempType TempType::operator%<int>(BasicType<int>& b);
//
//	template const TempType TempType::operator+<float>(BasicType<float>& b);
//	template const TempType TempType::operator-<float>(BasicType<float>& b);
//	template const TempType TempType::operator*<float>(BasicType<float>& b);
//	template const TempType TempType::operator/<float>(BasicType<float>& b);
//	template const TempType TempType::operator%<float>(BasicType<float>& b);
//
//	template const TempType TempType::operator+<double>(BasicType<double>& b);
//	template const TempType TempType::operator-<double>(BasicType<double>& b);
//	template const TempType TempType::operator*<double>(BasicType<double>& b);
//	template const TempType TempType::operator/<double>(BasicType<double>& b);
//	template const TempType TempType::operator%<double>(BasicType<double>& b);
//
//	template const TempType TempType::operator+<bool>(BasicType<bool>& b);
//	template const TempType TempType::operator-<bool>(BasicType<bool>& b);
//	template const TempType TempType::operator*<bool>(BasicType<bool>& b);
//	template const TempType TempType::operator/<bool>(BasicType<bool>& b);
//	template const TempType TempType::operator%<bool>(BasicType<bool>& b);
//
//	template const TempType TempType::operator+<char>(BasicType<char>& b);
//	template const TempType TempType::operator-<char>(BasicType<char>& b);
//	template const TempType TempType::operator*<char>(BasicType<char>& b);
//	template const TempType TempType::operator/<char>(BasicType<char>& b);
//	template const TempType TempType::operator%<char>(BasicType<char>& b);
//
//	template const TempType TempType::operator+<int>(int b);
//	template const TempType TempType::operator-<int>(int b);
//	template const TempType TempType::operator*<int>(int b);
//	template const TempType TempType::operator/<int>(int b);
//	template const TempType TempType::operator%<int>(int b);
//
//	template const TempType TempType::operator+<float>(float b);
//	template const TempType TempType::operator-<float>(float b);
//	template const TempType TempType::operator*<float>(float b);
//	template const TempType TempType::operator/<float>(float b);
//	template const TempType TempType::operator%<float>(float b);
//
//	template const TempType TempType::operator+<double>(double b);
//	template const TempType TempType::operator-<double>(double b);
//	template const TempType TempType::operator*<double>(double b);
//	template const TempType TempType::operator/<double>(double b);
//	template const TempType TempType::operator%<double>(double b);
//
//	template const TempType TempType::operator+<bool>(bool b);
//	template const TempType TempType::operator-<bool>(bool b);
//	template const TempType TempType::operator*<bool>(bool b);
//	template const TempType TempType::operator/<bool>(bool b);
//	template const TempType TempType::operator%<bool>(bool b);
//
//	template const TempType TempType::operator+<char>(char b);
//	template const TempType TempType::operator-<char>(char b);
//	template const TempType TempType::operator*<char>(char b);
//	template const TempType TempType::operator/<char>(char b);
//	template const TempType TempType::operator%<char>(char b);
//
//	template const TempType operator+<int>(int a, TempType& b);
//	template const TempType operator-<int>(int a, TempType& b);
//	template const TempType operator*<int>(int a, TempType& b);
//	template const TempType operator/<int>(int a, TempType& b);
//	template const TempType operator%<int>(int a, TempType& b);
//
//	template const TempType operator+<float>(float a, TempType& b);
//	template const TempType operator-<float>(float a, TempType& b);
//	template const TempType operator*<float>(float a, TempType& b);
//	template const TempType operator/<float>(float a, TempType& b);
//	template const TempType operator%<float>(float a, TempType& b);
//
//	template const TempType operator+<double>(double a, TempType& b);
//	template const TempType operator-<double>(double a, TempType& b);
//	template const TempType operator*<double>(double a, TempType& b);
//	template const TempType operator/<double>(double a, TempType& b);
//	template const TempType operator%<double>(double a, TempType& b);
//
//	template const TempType operator+<bool>(bool a, TempType& b);
//	template const TempType operator-<bool>(bool a, TempType& b);
//	template const TempType operator*<bool>(bool a, TempType& b);
//	template const TempType operator/<bool>(bool a, TempType& b);
//	template const TempType operator%<bool>(bool a, TempType& b);
//
//	template const TempType operator+<char>(char a, TempType& b);
//	template const TempType operator-<char>(char a, TempType& b);
//	template const TempType operator*<char>(char a, TempType& b);
//	template const TempType operator/<char>(char a, TempType& b);
//	template const TempType operator%<char>(char a, TempType& b);
//
//	template const TempType operator+<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator-<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator*<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator/<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator%<int>(BasicType<int>& a, TempType& b);
//
//	template const TempType operator+<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator-<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator*<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator/<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator%<int>(BasicType<int>& a, TempType& b);
//
//	template const TempType operator+<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator-<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator*<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator/<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator%<int>(BasicType<int>& a, TempType& b);
//
//	template const TempType operator+<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator-<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator*<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator/<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator%<int>(BasicType<int>& a, TempType& b);
//
//	template const TempType operator+<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator-<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator*<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator/<int>(BasicType<int>& a, TempType& b);
//	template const TempType operator%<int>(BasicType<int>& a, TempType& b);
//}