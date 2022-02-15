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

	BasicType();
public:
	BasicType(const char* name) {
		if (std::is_same<T, int>::value) _v.value.type = DataType::INT;
		if (std::is_same<T, float>::value) _v.value.type = DataType::FLOAT;
		if (std::is_same<T, double>::value) _v.value.type = DataType::DOUBLE;
		if (std::is_same<T, bool>::value) _v.value.type = DataType::BOOL;
		if (std::is_same<T, char>::value) _v.value.type = DataType::CHAR;
		strcpy_s(_v.name, NAME_LENGTH, name);
		_v.isSet = false;

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::CREATE_VAR;
		m.create_var.var = _v;
		ca->Send(m);

		while (ca->IsAnimating()) sf::sleep(sf::milliseconds(16));
	}

	template  <typename S>
	BasicType(const char* name, S v) {
		if (std::is_same<T, int>::value) _v.value.type = DataType::INT;
		if (std::is_same<T, float>::value) _v.value.type = DataType::FLOAT;
		if (std::is_same<T, double>::value) _v.value.type = DataType::DOUBLE;
		if (std::is_same<T, bool>::value) _v.value.type = DataType::BOOL;
		if (std::is_same<T, char>::value) _v.value.type = DataType::CHAR;
		strcpy_s(_v.name, NAME_LENGTH, name);
		_v.isSet = true;
		SetValue(_v.value.value, (T)v);
		_value = (T)v;

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::CREATE_VAR;
		m.create_var.var = _v;
		SetValue(m.create_var.value.value, v);
		m.create_var.value.type = GetType(v);
		ca->Send(m);

		while (ca->IsAnimating()) sf::sleep(sf::milliseconds(16));
	}

	BasicType(const BasicType& b) { 
		_v = b._v;
		_value = b._value;
	}
	~BasicType() {}

	T value() { return _value; }
	void value(T v) { _value = v; }
	DataType type() { return _v.value.type; }
	const char* name() { return _v.name; }

	template <typename S>
	BasicType<T>& operator=(BasicType<S> &b)
	{
		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::SET_VAR_VAR;
		m.set_var_var.varD = _v;
		m.set_var_var.varS = b._v;
		ca->Send(m);
		
		_value = b._value;
		SetValue(_v.value.value, _value);
		_v.isSet = true;

		ca->WaitEndOfAnimation();
		return *this;
	}

	template <typename S>
	BasicType<T>& operator=(S b)
	{
		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::SET_VAR_VALUE;
		m.set_var_value.var = _v;
		SetValue(m.set_var_value.value.value, b);
		m.set_var_value.value.type = GetType(b);
		ca->Send(m);

		_value = b;
		SetValue(_v.value.value, _value);
		_v.isSet = true;

		ca->WaitEndOfAnimation();
		return *this;
	}

	template <typename S>
	BasicType<T>& operator+=(BasicType<S>& b)
	{
		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::OPER_CHANGE_BY_VAR;
		m.oper_change_var.change_oper = ChangeOper::INCREASE;
		m.oper_change_var.varWHAT = _v;
		m.oper_change_var.varBY = b._v;

		_value += b._value;
		SetValue(_v.value.value, _value);
		
		m.oper_change_var.result = _v.value;
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
	}

	template <typename S>
	BasicType<T>& operator+=(S b)
	{
		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::OPER_CHANGE_BY_VALUE;
		m.oper_change_value.change_oper = ChangeOper::INCREASE;
		m.oper_change_value.var = _v;
		SetValue(m.oper_change_value.value.value, b);
		m.oper_change_value.value.type = GetType(b);

		_value += b;
		SetValue(_v.value.value, _value);

		m.oper_change_value.result = _v.value;
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
	}

	template <typename S>
	BasicType<T>& operator++(S b)
	{
		return (*this)+=1;
	}

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