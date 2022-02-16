#pragma once
#include "CodeAnimation.h"
#include <type_traits>

template <typename T> class BasicType;

template <typename A>
std::ostream& operator<<(std::ostream& out, BasicType<A> a)
{
	return out << a._value;
}

#pragma region COMPARE VALUE WITH VAR

template <typename A, typename S>
bool operator==(S a, BasicType<A>& b)
{
	bool res = (a == b._value);
	SendCompareMSG(a, b, CompareOper::EQUAL, res);
	return res;
}

template <typename A, typename S>
bool operator!=(S a, BasicType<A>& b)
{
	bool res = (a != b._value);
	SendCompareMSG(a, b, CompareOper::NOT_EQUAL, res);
	return res;
}

template <typename A, typename S>
bool operator>(S a, BasicType<A>& b)
{
	bool res = (a > b._value);
	SendCompareMSG(a, b, CompareOper::GREATER, res);
	return res;
}

template <typename A, typename S>
bool operator>=(S a, BasicType<A>& b)
{
	bool res = (a >= b._value);
	SendCompareMSG(a, b, CompareOper::EQ_GREATER, res);
	return res;
}

template <typename A, typename S>
bool operator<(S a, BasicType<A>& b)
{
	bool res = (a < b._value);
	SendCompareMSG(a, b, CompareOper::LESSER, res);
	return res;
}

template <typename A, typename S>
bool operator<=(S a, BasicType<A>& b)
{
	bool res = (a <= b._value);
	SendCompareMSG(a, b, CompareOper::EQ_LESSER, res);
	return res;
}

#pragma endregion //COMPARE VALUE WITH VAR

template <typename T>
class BasicType
{
	T _value;
	VariableDescription _v;

	BasicType() {}
public:

#pragma region CONSTRUCTORS

	BasicType(const char* name) : _value(0) {
		if (std::is_same<T, int>::value) _v.value.type = DataType::INT;
		if (std::is_same<T, float>::value) _v.value.type = DataType::FLOAT;
		if (std::is_same<T, double>::value) _v.value.type = DataType::DOUBLE;
		if (std::is_same<T, bool>::value) _v.value.type = DataType::BOOL;
		if (std::is_same<T, char>::value) _v.value.type = DataType::CHAR;
		strcpy_s(_v.name, NAME_LENGTH, name);
		_v.value.isGarbage = true;

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::CREATE_VAR;
		m.create_var.var = _v;
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	template  <typename S>
	BasicType(const char* name, S v) {
		if (std::is_same<T, int>::value) _v.value.type = DataType::INT;
		if (std::is_same<T, float>::value) _v.value.type = DataType::FLOAT;
		if (std::is_same<T, double>::value) _v.value.type = DataType::DOUBLE;
		if (std::is_same<T, bool>::value) _v.value.type = DataType::BOOL;
		if (std::is_same<T, char>::value) _v.value.type = DataType::CHAR;
		strcpy_s(_v.name, NAME_LENGTH, name);
		_value = (T)v;
		_v.SetValue(_value);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::CREATE_VAR;
		m.create_var.var = _v;
		m.create_var.value.SetValue(v);
		m.create_var.value.type = GetType(v);
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	BasicType(const BasicType& b) { 
		_v = b._v;
		_value = b._value;
	}
	
	~BasicType() {}

#pragma endregion //CONSTRUCTORS

#pragma region SETTERS

	T value() { return _value; }
	void value(T v, bool not_garbage = true) { _value = v; if (not_garbage) _v.SetValue(v); }
	DataType type() { return _v.value.type; }
	const char* name() { return _v.name; }

	template <typename S>
	BasicType<T>& operator=(BasicType<S> &b)
	{
		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::SET_VAR;
		m.set_var.varWhat = _v;
		m.set_var.isByVar = true;
		m.set_var.varBy = b._v;

		_value = (T)b._value;
		_v.SetValue(_value);

		m.set_var.result = _v.value;
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
	}

	template <typename S>
	BasicType<T>& operator=(S b)
	{
		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::SET_VAR;
		m.set_var.varWhat = _v;
		m.set_var.isByVar = false;
		m.set_var.valueBy.type = GetType(b);
		m.set_var.valueBy.SetValue(b);

		_value = (T)b;
		_v.SetValue(_value);

		m.set_var.result = _v.value;
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
	}

#pragma endregion //SETTERS

#pragma region CHANGE BY VAR

	template <typename S>
	static void SendChangeByMSG(BasicType<T>& a, BasicType<S>& b, ChangeOper co, T result)
	{
		MSG m;
		m.type = MsgType::OPER_CHANGE_BY;
		m.oper_change_by.change_type = co;
		m.oper_change_by.varWhat = a._v;
		m.oper_change_by.isByVar = true;
		m.oper_change_by.varBy = b._v;

		if (a._v.IsSet() && b._v.IsSet())
		{
			m.oper_change_by.result.type = GetType(result);
			m.oper_change_by.result.SetValue(result);
		}
		else
		{
			m.oper_change_by.result.type = GetType(result);
			m.oper_change_by.result.isGarbage = true;
		}

		CodeAnimation* ca = CodeAnimation::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	template <typename S>
	BasicType<T>& operator+=(BasicType<S>& b)
	{
		T result = _value + b._value;
		SendChangeByMSG(*this, b, ChangeOper::INCREASE_BY, result);
		value(result, _v.IsSet() && b._v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator-=(BasicType<S>& b)
	{
		T result = _value - b._value;
		SendChangeByMSG(*this, b, ChangeOper::DECREASE_BY, result);
		value(result, _v.IsSet() && b._v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator*=(BasicType<S>& b)
	{
		T result = _value * b._value;
		SendChangeByMSG(*this, b, ChangeOper::MULTIPLY_BY, result);
		value(result, _v.IsSet() && b._v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator/=(BasicType<S>& b)
	{
		T result = _value / b._value;
		SendChangeByMSG(*this, b, ChangeOper::DIVIDE_BY, result);
		value(result, _v.IsSet() && b._v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator%=(BasicType<S>& b)
	{
		T result = _value % b._value;
		SendChangeByMSG(*this, b, ChangeOper::MODULO_BY, result);
		value(result, _v.IsSet() && b._v.IsSet());
		return *this;
	}

#pragma endregion //CHANGE BY VAR

#pragma region CHANGE BY VALUE

	template <typename S>
	static void SendChangeByMSG(BasicType<T>& a, S& b, ChangeOper co, T result)
	{
		MSG m;
		m.type = MsgType::OPER_CHANGE_BY;
		m.oper_change_by.change_type = co;
		m.oper_change_by.varWhat = a._v;
		m.oper_change_by.isByVar = false;
		m.oper_change_by.valueBy.type = GetType(b);
		m.oper_change_by.valueBy.SetValue(b);

		if (a._v.IsSet())
		{
			m.oper_change_by.result.type = GetType(result);
			m.oper_change_by.result.SetValue(result);
		}
		else
		{
			m.oper_change_by.result.type = GetType(result);
			m.oper_change_by.result.isGarbage = true;
		}

		CodeAnimation* ca = CodeAnimation::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	template <typename S>
	BasicType<T>& operator+=(S b)
	{
		T result = _value + b;
		SendChangeByMSG(*this, b, ChangeOper::INCREASE_BY, result);
		value(result, _v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator-=(S b)
	{
		T result = _value - b;
		SendChangeByMSG(*this, b, ChangeOper::DECREASE_BY, result);
		value(result, _v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator*=(S b)
	{
		T result = _value * b;
		SendChangeByMSG(*this, b, ChangeOper::MULTIPLY_BY, result);
		value(result, _v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator/=(S b)
	{
		T result = _value / b;
		SendChangeByMSG(*this, b, ChangeOper::DIVIDE_BY, result);
		value(result, _v.IsSet());
		return *this;
	}

	template <typename S>
	BasicType<T>& operator%=(S b)
	{
		T result = _value % b;
		SendChangeByMSG(*this, b, ChangeOper::MODULO_BY, result);
		value(result, _v.IsSet());
		return *this;
	}

	BasicType<T>& operator++()
	{
		return (*this)+=1;
	}

	BasicType<T>& operator++(int)
	{
		return (*this) += 1;
	}

#pragma endregion //CHANGE BY VALUE

#pragma region COMPARE VAR WITH VAR

	template <typename S>
	static void SendCompareMSG(BasicType<T>& a, BasicType<S>& b, CompareOper co, bool result)
	{
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = result;
		m.oper_compare.comp_type = co;
		m.oper_compare.is1var = true;
		m.oper_compare.is2var = true;
		m.oper_compare.var1 = a._v;
		m.oper_compare.var2 = b._v;

		CodeAnimation* ca = CodeAnimation::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	template <typename S>
	bool operator==(BasicType<S> &b)
	{
		bool res = (_value == b._value);
		SendCompareMSG(*this, b, CompareOper::EQUAL, res);
		return res;
	}

	template <typename S>
	bool operator!=(BasicType<S>& b)
	{
		bool res = (_value != b._value);
		SendCompareMSG(*this, b, CompareOper::NOT_EQUAL, res);
		return res;
	}

	template <typename S>
	bool operator>(BasicType<S>& b)
	{
		bool res = (_value > b._value);
		SendCompareMSG(*this, b, CompareOper::GREATER, res);
		return res;
	}

	template <typename S>
	bool operator>=(BasicType<S>& b)
	{
		bool res = (_value >= b._value);
		SendCompareMSG(*this, b, CompareOper::EQ_GREATER, res);
		return res;
	}

	template <typename S>
	bool operator<(BasicType<S>& b)
	{
		bool res = (_value < b._value);
		SendCompareMSG(*this, b, CompareOper::LESSER, res);
		return res;
	}

	template <typename S>
	bool operator<=(BasicType<S>& b)
	{
		bool res = (_value <= b._value);
		SendCompareMSG(*this, b, CompareOper::EQ_LESSER, res);
		return res;
	}

	

#pragma endregion //COMPARE VAR WITH VAR
	
#pragma region COMPARE VAR WITH VALUE

	template <typename S>
	static void SendCompareMSG(S &a, BasicType<T>& b, CompareOper co, bool result)
	{
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = result;
		m.oper_compare.comp_type = co;
		m.oper_compare.is1var = false;
		m.oper_compare.is2var = true;
		SetValue(m.oper_compare.value1.value, a);
		m.oper_compare.value1.type = GetType(a);
		m.oper_compare.var2 = b._v;

		CodeAnimation* ca = CodeAnimation::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	template <typename S>
	static void SendCompareMSG(BasicType<T>& a, S &b, CompareOper co, bool result)
	{
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = result;
		m.oper_compare.comp_type = co;
		m.oper_compare.is1var = true;
		m.oper_compare.is2var = false;
		m.oper_compare.var1 = a._v;
		SetValue(m.oper_compare.value2.value, b);
		m.oper_compare.value2.type = GetType(b);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	template <typename S>
	bool operator==(S b)
	{
		bool res = (_value == b);
		SendCompareMSG(*this, b, CompareOper::EQUAL, res);
		return res;
	}

	template <typename S>
	bool operator!=(S b)
	{
		bool res = (_value != b);
		SendCompareMSG(*this, b, CompareOper::NOT_EQUAL, res);
		return res;
	}

	template <typename S>
	bool operator>(S b)
	{
		bool res = (_value > b);
		SendCompareMSG(*this, b, CompareOper::GREATER, res);
		return res;
	}

	template <typename S>
	bool operator>=(S b)
	{
		bool res = (_value >= b);
		SendCompareMSG(*this, b, CompareOper::EQ_GREATER, res);
		return res;
	}

	template <typename S>
	bool operator<(S b)
	{
		bool res = (_value < b);
		SendCompareMSG(*this, b, CompareOper::LESSER, res);
		return res;
	}

	template <typename S>
	bool operator<=(S b)
	{
		bool res = (_value <= b);
		SendCompareMSG(*this, b, CompareOper::EQ_LESSER, res);
		return res;
	}

	//FRIENDS
	template <typename A, typename S>
	friend bool operator== <T>(S a, BasicType<A>& b);

	template <typename A, typename S>
	friend bool operator!= <T>(S a, BasicType<A>& b);

	template <typename A, typename S>
	friend bool operator> <T>(S a, BasicType<A>& b);

	template <typename A, typename S>
	friend bool operator>= <T>(S a, BasicType<A>& b);

	template <typename A, typename S>
	friend bool operator< <T>(S a, BasicType<A>& b);

	template <typename A, typename S>
	friend bool operator<= <T>(S a, BasicType<A>& b);
#pragma endregion //COMPARE VAR WITH VALUE
	
	template <typename A>
	friend std::ostream& operator<< <T>(std::ostream& out, BasicType<A> a);
};


// SPECIALIZATIONS

typedef BasicType<int> INT;
typedef BasicType<float> FLOAT;
typedef BasicType<double> DOUBLE;
typedef BasicType<bool> BOOL;
typedef BasicType<char> CHAR;