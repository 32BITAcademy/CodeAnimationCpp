#pragma once
#include<string>

enum class MsgType{ ERROR, QUIT, CREATE_VAR, CREATE_ARR, SET_VAR_VALUE, SET_VAR_VAR, SET_ARR_VALUE, SET_ARR_VAR,
					OPER_IF, OPER_WHILE_START, OPER_WHILE_CHECK, OPER_FOR_START, OPER_FOR_CHECK,
					OPER_COMPARE, OPER_CHANGE_BY_VALUE, OPER_CHANGE_BY_VAR };

enum class DataType{ UNDEFINED, INT, FLOAT, DOUBLE, BOOL, CHAR };

DataType GetType(int a);
DataType GetType(float a);
DataType GetType(double a);
DataType GetType(bool a);
DataType GetType(char a);

enum class CompareOper{ EQUAL, GREATER, EQ_GREATER, LESSER, EQ_LESSER, NOT_EQUAL };
enum class ChangeOper{ INCREASE };

extern char DataTypeNames[6][10];
char* CA_NameOf(DataType& t);

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

std::string CA_ConvertValueToString(MsgValue& m, DataType t);

struct ValueDescription
{
	MsgValue value;
	DataType type;

	std::string GetValue();
	std::string GetShortString();
	std::string GetFullString();
};

struct VariableDescription
{
	char name[NAME_LENGTH];
	bool isSet;
	ValueDescription value;

	std::string GetValue();
	std::string GetFullString();
};

struct MSG
{
	MsgType type = MsgType::ERROR;
	union {
		struct{
			VariableDescription var;
			ValueDescription value;
		} create_var;

		/*struct {
			DataType dataType = DataType::UNDEFINED;
			char name[NAME_LENGTH];
			int size = 1;
			bool isSet = false;
			MsgValue value;
		} create_arr;*/

		struct {
			VariableDescription var;
			ValueDescription value;
		} set_var_value;

		struct {
			VariableDescription varD;
			VariableDescription varS;
		} set_var_var;

		/*struct {
			DataType dataType = DataType::UNDEFINED;
			char name[NAME_LENGTH];
			MsgValue value;
			int index;
		} set_arr_value;*/

		/*struct {
			DataType dataType = DataType::UNDEFINED;
			char name[NAME_LENGTH];
			char var_name[NAME_LENGTH];
			int index;
		} set_arr_var;*/

		struct {
			ChangeOper change_oper;
			VariableDescription var;
			ValueDescription value;
			ValueDescription result;
		} oper_change_value;

		struct {
			ChangeOper change_oper;
			VariableDescription varWHAT;
			VariableDescription varBY;
			ValueDescription result;
		} oper_change_var;

		struct {
			bool result;
			CompareOper comp_type;
			bool is1var;
			bool is2var;
			union {
				VariableDescription var1;
				ValueDescription value1;
			};
			union {
				VariableDescription var2;
				ValueDescription value2;
			};
		} oper_compare;

		struct {
			bool result;
		} oper_if;

		struct {
			bool result;
		} oper_while;

		struct {
			bool result;
		} oper_for;
	};

	MSG();
	MSG(const MSG& m);
	~MSG() { }
	std::string DebugString();
};

