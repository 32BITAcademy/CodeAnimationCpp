#include "MSG.h"

using namespace std;

char DataTypeNames[6][10] = { "undefined", "int", "float", "double", "bool", "char" };

DataType GetType(int a) { return DataType::INT; }
DataType GetType(float a) { return DataType::FLOAT; }
DataType GetType(double a) { return DataType::DOUBLE; }
DataType GetType(bool a) { return DataType::BOOL; }
DataType GetType(char a) { return DataType::CHAR; }

char* nameof(DataType& t)
{
	int x = static_cast<int>(t);
	if (x > 5 || x < 0) { x = 0; t = DataType::UNDEFINED; }
	return DataTypeNames[x];
}

void SetValue(MsgValue& m, int v) { m._int = v; }
void SetValue(MsgValue& m, float v) { m._float = v; }
void SetValue(MsgValue& m, double v) { m._double = v; }
void SetValue(MsgValue& m, bool v) { m._bool = v; }
void SetValue(MsgValue& m, char v) { m._char = v; }
void SetValue(MsgValue& m, MsgValue& v) { m = v; }

string GetValueString(MsgValue& m, DataType t)
{
	string s;
	switch (t)
	{
	case DataType::INT: s = m._int; break;
	case DataType::FLOAT: s = m._float; break;
	case DataType::DOUBLE: s = m._double; break;
	case DataType::BOOL: s = m._bool ? "TRUE" : "FALSE"; break;
	case DataType::CHAR: s = "\'" + m._char; s += "\'"; break;
	default: s = "UNDEFINED"; break;
	}
	return s;
}

string MSG::DebugString()
{
	MsgValue v;
	string s = "";
	switch (type)
	{
	case MsgType::ERROR:
		s += "Error message";
		break;
	case MsgType::QUIT:
		s += "Quit message";
		break;
	case MsgType::CREATE_ARR:
		s += "Created array \"";
		s += create_arr.name;
		s += "\" of ";
		s += nameof(create_arr.dataType);
		s += ", size = ";
		s += create_arr.size;
		if (create_arr.isSet)
		{
			s += ", with value " + GetValueString(create_arr.value, create_arr.dataType);
		}
		break;

	case MsgType::CREATE_VAR:
		s += "Created variable \"";
		s += create_var.name;
		s += "\" of ";
		s += nameof(create_arr.dataType);
		if (create_var.isSet)
		{
			s += ", with value " + GetValueString(create_var.value, create_var.dataType);
		}
		break;

	case MsgType::SET_VAR_VAR:
		s += "Set variable \"";
		s += set_var_var.name;
		s += "\" value of variable \"";
		s += set_var_var.var_name;
		s += "\" {" + GetValueString(set_var_var.value, set_var_var.dataType) + "}";
		break;

	case MsgType::SET_VAR_VALUE:
		v = set_var_value.value;
		s += "Set variable \"";
		s += set_var_value.name;
		s += "\" value " + GetValueString(set_var_value.value, set_var_value.dataType);
		break;

	case MsgType::OPER_IF:
		s += "Operator if selected ";
		if (oper_if.result)
			s += "TRUE";
		else
			s += "FALSE";
		s += " branch";
		break;

	case MsgType::OPER_COMPARE:
		s += "Compared ";
		v = oper_compare.value1;
		if (oper_compare.is1var)
		{
			s += "variable \"";
			s += oper_compare.name1;
			s += "\" {" + GetValueString(oper_compare.value1, oper_compare.dataType1) + "}";
		}
		else
		{
			s += "value " + GetValueString(oper_compare.value1, oper_compare.dataType1);
		}
		s += " and ";
		v = oper_compare.value2;
		if (oper_compare.is2var)
		{
			s += "variable \"";
			s += oper_compare.name2;
			s += "\" {" + GetValueString(oper_compare.value2, oper_compare.dataType2) + "}";
		}
		else
		{
			s += "value " + GetValueString(oper_compare.value1, oper_compare.dataType1);
		}
		s += " with operator ";
		switch (oper_compare.comp_type)
		{
		case CompareOper::EQUAL: s += "=="; break;
		case CompareOper::EQ_GREATER: s += ">="; break;
		case CompareOper::EQ_LESSER: s += "<="; break;
		case CompareOper::GREATER: s += ">"; break;
		case CompareOper::LESSER: s += "<"; break;
		case CompareOper::NOT_EQUAL: s += "!="; break;
		default: s += "UNDEFINED"; break;
		}
		s += ". Result is ";
		s += oper_compare.result ? "TRUE" : "FALSE";
		break;

	case MsgType::OPER_WHILE_START:
		s += "Started operator while";
		break;

	case MsgType::OPER_WHILE_CHECK:
		s += "Operator while checked cycle condition, result is ";
		if (oper_while.result)
			s += "TRUE. Cycle continues";
		else
			s += "FALSE. Cycle broke";
		break;

	default:
		s += "Got bad message, it's type id: ";
		s += (int)type;
		break;
	}

	return s;
}
