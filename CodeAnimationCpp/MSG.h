#pragma once
#include<string>

enum class MsgType{ ERROR, QUIT, CREATE_VAR, CREATE_ARR, SET_VAR, SET_ARR,
					OPER_IF, OPER_WHILE_START, OPER_WHILE_CHECK, OPER_FOR_START, OPER_FOR_CHECK,
					OPER_CHANGE_BY, OPER_SIGN, OPER_ARITHMETIC, OPER_COMPARE, OPER_LOGIC };

enum class DataType{ UNDEFINED, INT, FLOAT, DOUBLE, BOOL, CHAR };

DataType GetType(int a);
DataType GetType(float a);
DataType GetType(double a);
DataType GetType(bool a);
DataType GetType(char a);

enum class ChangeOper{ INCREASE_BY, DECREASE_BY, MULTIPLY_BY, DIVIDE_BY, MODULO_BY };
enum class SignOper{ PLUS, MINUS };
enum class ArithmeticOper{ ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, MODULO };
enum class CompareOper{ EQUAL, GREATER, EQ_GREATER, LESSER, EQ_LESSER, NOT_EQUAL };
enum class LogicOper{ AND, OR, NOT };

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

void CA_SetValue(MsgValue& m, int v);
void CA_SetValue(MsgValue& m, float v);
void CA_SetValue(MsgValue& m, double v);
void CA_SetValue(MsgValue& m, bool v);
void CA_SetValue(MsgValue& m, char v);

std::string CA_ConvertValueToString(MsgValue& m, DataType t);

struct ValueDescription
{
	MsgValue value;
	DataType type;
	bool isGarbage = true;

	std::string GetValue();
	std::string GetShortString();
	std::string GetFullString();

	template <typename T>
	void SetValue(T v)
	{
		CA_SetValue(value, v);
		isGarbage = false;
	}
};

struct VariableDescription
{
	char name[NAME_LENGTH];
	ValueDescription value;

	std::string GetValue();
	std::string GetFullString();
	bool IsSet();

	template <typename T>
	void SetValue(T v)
	{
		value.SetValue(v);
	}
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
			VariableDescription varWhat;
			bool isByVar;
			union {
				VariableDescription varBy;
				ValueDescription valueBy;
			};
			ValueDescription result;
		} set_var;

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
			ChangeOper change_type;
			VariableDescription varWhat;
			bool isByVar;
			union {
				VariableDescription varBy;
				ValueDescription valueBy;
			};
			ValueDescription result;
		} oper_change_by;

		struct {
			SignOper sign_type;
			bool isVar;
			union {
				VariableDescription var;
				ValueDescription value;
			};
			ValueDescription result;
		} oper_sign;

		struct {
			ArithmeticOper arithm_type;
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
			ValueDescription result;
		} oper_arithm;

		struct {
			LogicOper logic_type;
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
			ValueDescription result;
		} oper_logic;

		struct {
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
			bool result;
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

