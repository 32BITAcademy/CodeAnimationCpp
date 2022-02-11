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
		switch (_type)
		{
		case DataType::INT: m.create_var.value._int = (int)v; break;
		case DataType::FLOAT: m.create_var.value._float = (float)v; break;
		case DataType::DOUBLE: m.create_var.value._double = (double)v; break;
		case DataType::BOOL: m.create_var.value._bool = (bool)v; break;
		case DataType::CHAR: m.create_var.value._char = (char)v; break;
		}
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
		strcpy_s(m.set_var_var.name, NAME_LENGTH, _name);
		strcpy_s(m.set_var_var.var_name, NAME_LENGTH, b._name);
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return *this;
	}

	template <typename S>
	bool operator==(BasicType<S> &b)
	{
		bool res = (_value == b._value);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = res;
		m.oper_compare.type = CompareOper::EQUAL;
		m.oper_compare.is1var = true;
		m.oper_compare.is2var = true;
		strcpy_s(m.oper_compare.name1, NAME_LENGTH, _name);
		strcpy_s(m.oper_compare.name2, NAME_LENGTH, b._name);
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return res;
	}

	template <typename S>
	bool operator>(BasicType<S>& b)
	{
		bool res = (_value == b._value);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = res;
		m.oper_compare.type = CompareOper::EQUAL;
		m.oper_compare.is1var = true;
		m.oper_compare.is2var = true;
		strcpy_s(m.oper_compare.name1, NAME_LENGTH, _name);
		strcpy_s(m.oper_compare.name2, NAME_LENGTH, b._name);
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return res;
	}

	template <typename S>
	bool operator==(S &b)
	{
		bool res = (_value == b);

		CodeAnimation* ca = CodeAnimation::GetInstance();
		MSG m;
		m.type = MsgType::OPER_COMPARE;
		m.oper_compare.result = res;
		m.oper_compare.type = CompareOper::EQUAL;
		m.oper_compare.is1var = true;
		m.oper_compare.is2var = false;
		strcpy_s(m.oper_compare.name1, NAME_LENGTH, _name);
		strcpy_s(m.oper_compare.name2, NAME_LENGTH, "value");
		ca->Send(m);

		ca->WaitEndOfAnimation();
		return res;
	}

	friend bool operator==(int a, BasicType<T> &b);
};

typedef BasicType<int> Int;
typedef BasicType<float> Float;
typedef BasicType<double> Double;
typedef BasicType<bool> Bool;
typedef BasicType<char> Char;

template <typename T>
bool operator==(int a, BasicType<T> &b)
{
	bool res = (a == b._value);

	CodeAnimation* ca = CodeAnimation::GetInstance();
	MSG m;
	m.type = MsgType::OPER_COMPARE;
	m.oper_compare.result = res;
	m.oper_compare.type = CompareOper::EQUAL;
	m.oper_compare.is1var = false;
	m.oper_compare.is2var = true;
	strcpy_s(m.oper_compare.name1, NAME_LENGTH, "value");
	strcpy_s(m.oper_compare.name2, NAME_LENGTH, b._name);
	ca->Send(m);

	ca->WaitEndOfAnimation();
	return res;
}