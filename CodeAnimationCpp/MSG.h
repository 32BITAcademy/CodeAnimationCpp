#pragma once
#include<string>

enum class MsgType{ ERROR, QUIT, CREATE_VAR, CREATE_ARR, SET_VAR_VALUE, SET_VAR_VAR, SET_ARR_VALUE, SET_ARR_VAR,
					OPER_IF, OPER_WHILE_START, OPER_WHILE_CHECK,
					OPER_COMPARE};
enum class DataType{ UNDEFINED, INT, FLOAT, DOUBLE, BOOL, CHAR };
enum class CompareOper{ EQUAL, GREATER, EQ_GREATER, LESSER, EQ_LESSER, NOT_EQUAL };

extern char DataTypeNames[6][10];
char* nameof(DataType& t);

union MsgValue{
	int _int;
	float _float;
	double _double;
	bool _bool;
	char _char;
};

#define NAME_LENGTH 200

void SetValue(MsgValue& m, int v);
void SetValue(MsgValue& m, float v);
void SetValue(MsgValue& m, double v);
void SetValue(MsgValue& m, bool v);
void SetValue(MsgValue& m, char v);

template<DataType t>
struct ValueType;
template<> struct ValueType<DataType::INT> { typedef int mytype; };
template<> struct ValueType<DataType::FLOAT> { typedef float mytype; };
template<> struct ValueType<DataType::DOUBLE> { typedef double mytype; };
template<> struct ValueType<DataType::BOOL> { typedef bool mytype; };
template<> struct ValueType<DataType::CHAR> { typedef char mytype; };

template <DataType t>
typename ValueType<t>::mytype GetValue(MsgValue& m);

template<> int GetValue<DataType::INT>(MsgValue& m) { return m._int; }
template<> float GetValue<DataType::FLOAT>(MsgValue& m) { return m._float; }
template<> double GetValue<DataType::DOUBLE>(MsgValue& m) { return m._double; }
template<> bool GetValue<DataType::BOOL>(MsgValue& m) { return m._bool; }
template<> char GetValue<DataType::CHAR>(MsgValue& m) { return m._char; }

std::string GetValueString(MsgValue& m, DataType t);

struct MSG
{
	MsgType type = MsgType::ERROR;
	union {
		struct {
			bool result;
		} oper_if;

		struct {
			bool result;
		} oper_while;

		struct {
			bool result;
			CompareOper type;
			bool is1var;
			bool is2var;
			char name1[NAME_LENGTH];
			char name2[NAME_LENGTH];
			MsgValue value1;
			MsgValue value2;
		} oper_compare;

		struct{
			DataType dataType = DataType::INT;
			char name[NAME_LENGTH];
			bool isSet = false;
			MsgValue value;
		} create_var;

		struct {
			DataType dataType = DataType::INT;
			char name[NAME_LENGTH];
			int size = 1;
			bool isSet = false;
			MsgValue value;
		} create_arr;

		struct {
			DataType dataType = DataType::INT;
			char name[NAME_LENGTH];
			MsgValue value;
		} set_var_value;

		struct {
			DataType dataType = DataType::INT;
			char name[NAME_LENGTH];
			char var_name[NAME_LENGTH];
		} set_var_var;

		struct {
			DataType dataType = DataType::INT;
			char name[NAME_LENGTH];
			MsgValue value;
			int index;
		} set_arr_value;

		struct {
			DataType dataType = DataType::INT;
			char name[NAME_LENGTH];
			char var_name[NAME_LENGTH];
			int index;
		} set_arr_var;
	};

	MSG() {
		type = MsgType::ERROR;
	}
	MSG(const MSG& m) {
		type = m.type;
		switch (type)
		{
		case MsgType::CREATE_VAR: create_var = m.create_var; break;
		case MsgType::CREATE_ARR: create_arr = m.create_arr; break;

		case MsgType::SET_VAR_VALUE: set_var_value = m.set_var_value; break;
		case MsgType::SET_VAR_VAR: set_var_var = m.set_var_var; break;
		case MsgType::SET_ARR_VALUE: set_arr_value = m.set_arr_value; break;
		case MsgType::SET_ARR_VAR: set_arr_var = m.set_arr_var; break;

		case MsgType::OPER_IF: oper_if = m.oper_if; break;
		case MsgType::OPER_WHILE_CHECK: oper_while = m.oper_while; break;

		case MsgType::OPER_COMPARE: oper_compare = m.oper_compare; break;
		}
	}
	~MSG() { }
	std::string DebugString();
};

