#include "MSG.h"

using namespace std;

namespace ca {
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
		string s = "[CA-DEBUG] ";

#ifdef DETAILED_DEBUG_STRINGS
		switch (type)
		{
		case MsgType::ERROR:
			s += "Error message";
			break;
		case MsgType::QUIT:
			s += "Quit message";
			break;
			/*case MsgType::CREATE_ARR:
				break;*/

		case MsgType::CREATE_VAR:
			s = s + "Created variable \"" + create_var.var.name + "\" of " + DataTypeToString(create_var.var.value.type);
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
			s += oper_compare.result.GetBool() ? "TRUE" : "FALSE";
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

#else

		switch (type)
		{
		case MsgType::ERROR:
			s += "Error";
			break;
		case MsgType::QUIT:
			s += "Quit";
			break;
			/*case MsgType::CREATE_ARR:
				break;*/

		case MsgType::CREATE_VAR:
			s = s + "def " +  DataTypeToString(create_var.var.value.type) + " " + create_var.var.name;
			if (create_var.var.IsSet())
			{
				s += "(" + create_var.value.GetOnlyValue() + ")";
			}
			break;

		case MsgType::SET_VAR:
			s += set_var.varWhat.GetShortString() + " = " +
				((set_var.isByVar) ? set_var.varBy.GetShortString() : set_var.valueBy.GetShortString())
				+ " -> " + set_var.result.GetShortString();
			break;

		case MsgType::OPER_CHANGE_BY:
			s += oper_change_by.varWhat.GetShortString() + " ";
			switch (oper_change_by.change_type)
			{
			case ChangeOper::INCREASE_BY: s += "+="; break;
			case ChangeOper::DECREASE_BY: s += "-="; break;
			case ChangeOper::MULTIPLY_BY: s += "*="; break;
			case ChangeOper::DIVIDE_BY: s += "/="; break;
			case ChangeOper::MODULO_BY: s += "%="; break;
			default: s += "UNKNOWN"; break;
			}
			s += ((oper_change_by.isByVar) ? oper_change_by.varBy.GetShortString() : oper_change_by.valueBy.GetShortString())
				+ " -> " + oper_change_by.result.GetShortString();
			break;

		case MsgType::OPER_SIGN:
			if (oper_sign.sign_type == SignOper::MINUS) s += "minus";
			else s += "plus";
			s += " " + ((oper_sign.isVar) ? oper_sign.var.GetShortString() : oper_sign.value.GetShortString())
				+ " -> " + oper_sign.result.GetShortString();
			break;

		case MsgType::OPER_ARITHMETIC:
			if (oper_arithm.is1var) s += oper_arithm.var1.GetShortString();
			else s += oper_arithm.value1.GetShortString();
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
			if (oper_arithm.is2var) s += oper_arithm.var2.GetShortString();
			else s += oper_arithm.value2.GetShortString();
			s += " -> " + oper_arithm.result.GetShortString();
			break;

		case MsgType::OPER_COMPARE:
			if (oper_compare.is1var) s += oper_compare.var1.GetShortString();
			else s += oper_compare.value1.GetShortString();
			s += " ";
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
			s += " ";
			if (oper_compare.is2var) s += oper_compare.var2.GetShortString();
			else s += oper_compare.value2.GetShortString();
			s += " -> ";
			s += oper_compare.result.GetBool() ? "TRUE" : "FALSE";
			break;

		case MsgType::OPER_LOGIC:
			if (oper_logic.logic_type == LogicOper::NOT)
			{
				s += "not ";
				if (oper_logic.is1var) s += oper_logic.var1.GetShortString();
				else s += oper_logic.value1.GetShortString();
			}
			else
			{
				if (oper_logic.is1var) s += oper_logic.var1.GetShortString();
				else s += oper_logic.value1.GetShortString();
				s += " ";
				switch (oper_logic.logic_type)
				{
				case LogicOper::AND: s += "and"; break;
				case LogicOper::OR: s += "or"; break;
				}
				s += " ";
				if (oper_logic.is2var) s += oper_logic.var2.GetShortString();
				else s += oper_logic.value2.GetShortString();
			}
			s += " -> " + oper_logic.result.GetShortString();
			break;

		case MsgType::OPER_IF:
			s += "if -> ";
			if (oper_if.result)
				s += "TRUE";
			else
				s += "FALSE";
			break;

		case MsgType::OPER_WHILE_START:
			s += "Start While";
			break;

		case MsgType::OPER_WHILE_CHECK:
			s += "While condition -> ";
			if (oper_while.result)
				s += "TRUE";
			else
				s += "FALSE";
			break;

		case MsgType::OPER_FOR_START:
			s += "Start For";
			break;

		case MsgType::OPER_FOR_CHECK:
			s += "For condition -> ";
			if (oper_for.result)
				s += "TRUE";
			else
				s += "FALSE";
			break;

		default:
			s += "Bad message: ";
			s += (int)type;
			break;
		}

#endif

		return s;
	}
}