#pragma once
#include "CodeAnimation.h"
#include <type_traits>



template <typename T>
class BasicType
{
	bool set = false;
	T _value;
	DataType _type;
	char _name[NAME_LENGTH];

	BasicType();
public:
	BasicType(const char* name) : set(false) {
		if (std::is_same<T, int>::value) _type = DataType::INT;
		if (std::is_same<T, float>::value) _type = DataType::FLOAT;
		if (std::is_same<T, double>::value) _type = DataType::DOUBLE;
		if (std::is_same<T, bool>::value) _type = DataType::BOOL;
		if (std::is_same<T, char>::value) _type = DataType::CHAR;
		strcpy_s(_name, NAME_LENGTH, name);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::CREATE_VAR;
		m.create_var.dataType = _type;
		strcpy_s(m.create_var.name, NAME_LENGTH, _name);
		m.create_var.isSet = set;
		ca->Send(m);

		while (ca->IsAnimating()) sf::sleep(sf::milliseconds(16));
	}
	BasicType(const char* name, T v) : _value(v), set(true) {
		if (std::is_same<T, int>::value) _type = DataType::INT;
		if (std::is_same<T, float>::value) _type = DataType::FLOAT;
		if (std::is_same<T, double>::value) _type = DataType::DOUBLE;
		if (std::is_same<T, bool>::value) _type = DataType::BOOL;
		if (std::is_same<T, char>::value) _type = DataType::CHAR;
		strcpy_s(_name, NAME_LENGTH, name);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::CREATE_VAR;
		m.create_var.dataType = _type;
		strcpy_s(m.create_var.name, NAME_LENGTH, name);
		m.create_var.isSet = set;
		SetValue(m.create_var.value, v);
		ca->Send(m);

		while (ca->IsAnimating()) sf::sleep(sf::milliseconds(16));
	}
	BasicType(const BasicType& b) { 
		_value = b._value; 
		_type = b._type; 
		strcpy_s(_name, NAME_LENGTH, b._name);
	}
	~BasicType() {}

	T value() { return _value; }
	void value(T v) { _value = v; }
	DataType type() { return _type; }
	const char* name() { return _name; }

	BasicType<T>& operator=(BasicType<T> &b)
	{
		_value = b._value;

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::SET_VAR_VAR;
		m.set_var_var.dataType = _type;
		SetValue(m.set_var_var.value, b._value);
		strcpy_s(m.set_var_var.name, NAME_LENGTH, _name);
		strcpy_s(m.set_var_var.var_name, NAME_LENGTH, b._name);
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
	}

	BasicType<T>& operator=(T b)
	{
		_value = b;

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::SET_VAR_VALUE;
		m.set_var_value.dataType = _type;
		strcpy_s(m.set_var_value.name, NAME_LENGTH, _name);
		SetValue(m.set_var_value.value, b);
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
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
		strcpy_s(m.oper_compare.name1, NAME_LENGTH, a._name);
		strcpy_s(m.oper_compare.name2, NAME_LENGTH, b._name);
		SetValue(m.oper_compare.value1, a._value);
		SetValue(m.oper_compare.value2, b._value);
		m.oper_compare.dataType1 = a._type;
		m.oper_compare.dataType2 = b._type;

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
		strcpy_s(m.oper_compare.name1, NAME_LENGTH, "value");
		strcpy_s(m.oper_compare.name2, NAME_LENGTH, b._name);
		SetValue(m.oper_compare.value1, a);
		SetValue(m.oper_compare.value2, b._value);
		m.oper_compare.dataType1 = GetType(a);
		m.oper_compare.dataType2 = b._type;

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
		strcpy_s(m.oper_compare.name1, NAME_LENGTH, a._name);
		strcpy_s(m.oper_compare.name2, NAME_LENGTH, "value");
		SetValue(m.oper_compare.value1, a._value);
		SetValue(m.oper_compare.value2, b);
		m.oper_compare.dataType1 = a._type;
		m.oper_compare.dataType2 = GetType(b);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		ca->Send(m);

		ca->WaitEndOfAnimation();
	}

	template <typename S>
	bool operator==(S &b)
	{
		bool res = (_value == b);
		SendCompareMSG(*this, b, CompareOper::EQUAL, res);
		return res;
	}

	template <typename S>
	bool operator!=(S& b)
	{
		bool res = (_value != b);
		SendCompareMSG(*this, b, CompareOper::NOT_EQUAL, res);
		return res;
	}

	template <typename S>
	bool operator>(S& b)
	{
		bool res = (_value > b);
		SendCompareMSG(*this, b, CompareOper::GREATER, res);
		return res;
	}

	template <typename S>
	bool operator>=(S& b)
	{
		bool res = (_value >= b);
		SendCompareMSG(*this, b, CompareOper::EQ_GREATER, res);
		return res;
	}

	template <typename S>
	bool operator<(S& b)
	{
		bool res = (_value < b);
		SendCompareMSG(*this, b, CompareOper::LESSER, res);
		return res;
	}

	template <typename S>
	bool operator<=(S& b)
	{
		bool res = (_value <= b);
		SendCompareMSG(*this, b, CompareOper::EQ_LESSER, res);
		return res;
	}

	 FRIENDS
	template <typename S>
	friend bool operator==(S &a, BasicType<T>& b);

	template <typename S>
	friend bool operator!=(S &a, BasicType<T>& b);

	template <typename S>
	friend bool operator>(S &a, BasicType<T>& b);

	template <typename S>
	friend bool operator>=(S &a, BasicType<T>& b);

	template <typename S>
	friend bool operator<(S &a, BasicType<T>& b);

	template <typename S>
	friend bool operator<=(S &a, BasicType<T>& b);
#pragma endregion //COMPARE VAR WITH VALUE
	
};

template <typename T, typename S>
bool operator==(S &a, BasicType<T>& b)
{
	bool res = (a == b._value);
	SendCompareMSG(a, b, CompareOper::EQUAL, res);
	return res;
}


typedef BasicType<int> INT;
typedef BasicType<float> FLOAT;
typedef BasicType<double> DOUBLE;
typedef BasicType<bool> BOOL;
typedef BasicType<char> CHAR;