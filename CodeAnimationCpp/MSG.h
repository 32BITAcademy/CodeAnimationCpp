#pragma once
#include<string>

enum class MsgType{ ERROR, QUIT, CREATE_VAR, CREATE_ARR, SET_VAR_VALUE, SET_VAR_VAR, SET_ARR_VALUE, SET_ARR_VAR,
					OPER_IF, OPER_WHILE_START, OPER_WHILE_CHECK,
					OPER_COMPARE};
enum class DataType{ UNDEFINED, INT, FLOAT, DOUBLE, BOOL, CHAR };
enum class CompareOper{ EQUAL, GREATER, EQ_GREATER, LESSER, EQ_LESSER, NOT_EQUAL };

char DataTypeNames[6][10] = { "undefined", "int", "float", "double", "bool", "char" };
char* nameof(DataType &t)
{
	int x = static_cast<int>(t);
	if (x > 5 || x < 0) { x = 0; t = DataType::UNDEFINED; }
	return DataTypeNames[x];
}

#define NAME_LENGTH 200

union MsgValue{
	int _int;
	float _float;
	double _double;
	bool _bool;
	char _char;
};

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
};

