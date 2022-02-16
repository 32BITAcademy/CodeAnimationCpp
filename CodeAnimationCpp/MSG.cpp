#include "MSG.h"

using namespace std;

char DataTypeNames[6][10] = { "undefined", "int", "float", "double", "bool", "char" };

DataType GetType(int a) { return DataType::INT; }
DataType GetType(float a) { return DataType::FLOAT; }
DataType GetType(double a) { return DataType::DOUBLE; }
DataType GetType(bool a) { return DataType::BOOL; }
DataType GetType(char a) { return DataType::CHAR; }

char* CA_NameOf(DataType& t)
{
	int x = static_cast<int>(t);
	if (x > 5 || x < 0) { x = 0; t = DataType::UNDEFINED; }
	return DataTypeNames[x];
}

void CA_SetValue(MsgValue& m, int v) { m._int = v; }
void CA_SetValue(MsgValue& m, float v) { m._float = v; }
void CA_SetValue(MsgValue& m, double v) { m._double = v; }
void CA_SetValue(MsgValue& m, bool v) { m._bool = v; }
void CA_SetValue(MsgValue& m, char v) { m._char = v; }

string CA_ConvertValueToString(MsgValue& m, DataType t)
{
	string s;
	switch (t)
	{
	case DataType::INT: s = to_string(m._int); break;
	case DataType::FLOAT: s = to_string(m._float); break;
	case DataType::DOUBLE: s = to_string(m._double); break;
	case DataType::BOOL: s = m._bool ? "TRUE" : "FALSE"; break;
	case DataType::CHAR: s = "\'"; s += m._char; s+= +"\'"; break;
	default: s = "UNDEFINED"; break;
	}
	return s;
}

MSG::MSG() {
	type = MsgType::ERROR;
}

MSG::MSG(const MSG& m) {
	type = m.type;
	switch (type)
	{
	case MsgType::CREATE_VAR: create_var = m.create_var; break;
		//case MsgType::CREATE_ARR: create_arr = m.create_arr; break;

	case MsgType::SET_VAR: set_var = m.set_var; break;
		//case MsgType::SET_ARR: set_arr = m.set_arr; break;

	case MsgType::OPER_IF: oper_if = m.oper_if; break;
	case MsgType::OPER_WHILE_START: break;
	case MsgType::OPER_WHILE_CHECK: oper_while = m.oper_while; break;
	case MsgType::OPER_FOR_START: break;
	case MsgType::OPER_FOR_CHECK: oper_for = m.oper_for; break;

	case MsgType::OPER_CHANGE_BY: oper_change_by = m.oper_change_by; break;
	case MsgType::OPER_SIGN: oper_sign = m.oper_sign; break;
	case MsgType::OPER_ARITHMETIC: oper_arithm = m.oper_arithm; break;
	case MsgType::OPER_COMPARE: oper_compare = m.oper_compare; break;
	case MsgType::OPER_LOGIC: oper_logic = m.oper_logic; break;
	}
}

string MSG::DebugString()
{
	//MsgValue v;
	string s = "";
	switch (type)
	{
	case MsgType::ERROR:
		s += "Error message";
		break;
	case MsgType::QUIT:
		s += "Quit message";
		break;
	/*case MsgType::CREATE_ARR:
		s += "Created array \"";
		s += create_arr.name;
		s += "\" of ";
		s += CA_NameOf(create_arr.dataType);
		s += ", size = ";
		s += create_arr.size;
		if (create_arr.isSet)
		{
			s += ", with " + CA_GetValueString(create_arr.value, create_arr.dataType);
		}
		break;*/

	case MsgType::CREATE_VAR:
		s = s + "Created variable \"" + create_var.var.name + "\" of " + CA_NameOf(create_var.var.value.type);
		if (create_var.var.IsSet())
		{
			s += ", with " + create_var.value.GetFullString();
		}
		break;

	case MsgType::SET_VAR:
		s += "Set " + set_var.varWhat.GetFullString() + " " + 
			((set_var.isByVar) ? ("value of " + set_var.varBy.GetFullString()) : set_var.valueBy.GetFullString())
			+ ", result is " + set_var.result.GetShortString();
		break;

	case MsgType::OPER_CHANGE_BY:
		s += "Changed " + oper_change_by.varWhat.GetFullString() + " with operator ";
		switch (oper_change_by.change_type)
		{
		case ChangeOper::INCREASE_BY: s += "+="; break;
		case ChangeOper::DECREASE_BY: s += "-="; break;
		case ChangeOper::MULTIPLY_BY: s += "*="; break;
		case ChangeOper::DIVIDE_BY: s += "/="; break;
		case ChangeOper::MODULO_BY: s += "%="; break;
		default: s += "UNKNOWN"; break;
		}
		s += " by " + ((oper_change_by.isByVar) ? oper_change_by.varBy.GetFullString() : oper_change_by.valueBy.GetFullString())
			+ ", result is " + oper_change_by.result.GetShortString();
		break;

	case MsgType::OPER_SIGN:
		s += "Calculated ";
		if (oper_sign.sign_type == SignOper::MINUS) s += "minus";
		else s += "plus";
		s += " value of " + ((oper_sign.isVar) ? oper_sign.var.GetFullString() : oper_sign.value.GetFullString())
			+ ", result is " + oper_sign.result.GetShortString();
		break;

	case MsgType::OPER_ARITHMETIC:
		s += "Calculated ";
		if (oper_arithm.is1var) s += oper_arithm.var1.GetFullString();
		else s += oper_arithm.value1.GetFullString();
		s += " ";
		switch (oper_arithm.arithm_type)
		{
		case ArithmeticOper::ADDITION: s += "+"; break;
		case ArithmeticOper::SUBTRACTION: s += "-"; break;
		case ArithmeticOper::MULTIPLICATION: s += "*"; break;
		case ArithmeticOper::DIVISION: s += "/"; break;
		case ArithmeticOper::MODULO: s += "%"; break;
		}
		s += " ";
		if (oper_arithm.is2var) s += oper_arithm.var2.GetFullString();
		else s += oper_arithm.value2.GetFullString();
		s += ", result is " + oper_arithm.result.GetShortString();
		break;

	case MsgType::OPER_COMPARE:
		s += "Compared ";
		if (oper_compare.is1var) s += oper_compare.var1.GetFullString();
		else s += oper_compare.value1.GetFullString();
		s += " and ";
		if (oper_compare.is2var) s += oper_compare.var2.GetFullString();
		else s += oper_compare.value2.GetFullString();
		s += " with operator ";
		switch (oper_compare.comp_type)
		{
		case CompareOper::EQUAL: s += "=="; break;
		case CompareOper::EQ_GREATER: s += ">="; break;
		case CompareOper::EQ_LESSER: s += "<="; break;
		case CompareOper::GREATER: s += ">"; break;
		case CompareOper::LESSER: s += "<"; break;
		case CompareOper::NOT_EQUAL: s += "!="; break;
		default: s += "UNKNOWN"; break;
		}
		s += ", result is ";
		s += oper_compare.result ? "TRUE" : "FALSE";
		break;

	case MsgType::OPER_LOGIC:
		s += "Calculated ";

		if (oper_logic.logic_type == LogicOper::NOT)
		{
			s += "NOT ";
			if (oper_logic.is1var) s += oper_logic.var1.GetFullString();
			else s += oper_logic.value1.GetFullString();
		}
		else
		{
			if (oper_logic.is1var) s += oper_logic.var1.GetFullString();
			else s += oper_logic.value1.GetFullString();
			s += " ";
			switch (oper_logic.logic_type)
			{
			case LogicOper::AND: s += "AND"; break;
			case LogicOper::OR: s += "OR"; break;
			}
			s += " ";
			if (oper_logic.is2var) s += oper_logic.var2.GetFullString();
			else s += oper_logic.value2.GetFullString();
		}
		s += ", result is " + oper_logic.result.GetShortString();
		break;

	case MsgType::OPER_IF:
		s += "Operator if selected ";
		if (oper_if.result)
			s += "TRUE";
		else
			s += "FALSE";
		s += " branch";
		break;

	case MsgType::OPER_WHILE_START:
		s += "Started cycle While";
		break;

	case MsgType::OPER_WHILE_CHECK:
		s += "Operator While checked cycle condition, result is ";
		if (oper_while.result)
			s += "TRUE. Cycle While continues";
		else
			s += "FALSE.";
		break;

	case MsgType::OPER_FOR_START:
		s += "Started cycle For";
		break;

	case MsgType::OPER_FOR_CHECK:
		s += "Operator For checked cycle condition, result is ";
		if (oper_for.result)
			s += "TRUE. Cycle For continues";
		else
			s += "FALSE.";
		break;

	default:
		s += "Got bad message, it's type id: ";
		s += (int)type;
		break;
	}

	return s;
}

std::string ValueDescription::GetValue()
{
	if (isGarbage) return "_GARBAGE_";
	return CA_ConvertValueToString(value, type);
}

std::string ValueDescription::GetShortString()
{
	return "{" + GetValue() + "} (" + CA_NameOf(type) + ")";
}

std::string ValueDescription::GetFullString()
{
	return "value " + GetValue() + " (" + CA_NameOf(type) + ")";
}

std::string VariableDescription::GetValue()
{
	return value.GetValue();
}

std::string VariableDescription::GetFullString()
{
	string s = "variable \"";
	s = s + name + "\" ";
	if (IsSet())
		s += value.GetShortString();
	else
		s = s + "{_GARBAGE_} (" + CA_NameOf(value.type) + ")";
	return s;
}

bool VariableDescription::IsSet()
{
	return !value.isGarbage;
}