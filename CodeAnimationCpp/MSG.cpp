#include "MSG.h"

using namespace std;

char DataTypeNames[6][10] = { "undefined", "int", "float", "double", "bool", "char" };
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
	default: s = "undefined"; break;
	}
	return s;
}

string MSG::DebugString()
{
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
		s += "\"";
		break;

	case MsgType::SET_VAR_VALUE:
		s += "Set variable \"";
		s += set_var_value.name;
		s += "\" value ";
		s += GetValue<set_var_value.dataType>(set_var_value.value);
		s += "\"";
		break;

	case MsgType::OPER_IF:
		cout << "Operator if is checking expression. Expression result is ";
		if (m.oper_if.result)
			cout << "TRUE";
		else
			cout << "FALSE";
		cout << "." << endl;
		break;

	case MsgType::OPER_COMPARE:
		cout << "Checking equality of ";
		if (m.oper_compare.is1var)
			cout << "variable \"" << m.oper_compare.name1 << "\"";
		cout << " and ";
		if (m.oper_compare.is2var)
			cout << "variable \"" << m.oper_compare.name2 << "\"." << endl;
		cout << "Result is ";
		if (m.oper_compare.result)
			cout << "EQUAL." << endl;
		else
			cout << "DIFFERENT VALUES." << endl;
		break;

	case MsgType::OPER_WHILE_START:
		cout << "Started cycle while." << endl;
		break;

	case MsgType::OPER_WHILE_CHECK:
		cout << "Operator while is checking expression. Expression result is ";
		if (m.oper_while.result)
			cout << "TRUE. Cycle continues." << endl;
		else
			cout << "FALSE. Cycle broke." << endl;
		break;

	default:
		cout << "Got bad message, typed: " << (int)m.type << endl;
		break;
	}
}
