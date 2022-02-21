#pragma once
#include<string>
#include "Variable.h"

namespace ca {

	enum class MsgType {
		ERROR, QUIT, CREATE_VAR, CREATE_ARR, SET_VAR, SET_ARR,
		OPER_IF, OPER_WHILE_START, OPER_WHILE_CHECK, OPER_FOR_START, OPER_FOR_CHECK,
		OPER_CHANGE_BY, OPER_SIGN, OPER_ARITHMETIC, OPER_COMPARE, OPER_LOGIC
	};

	enum class ChangeOper { INCREASE_BY, DECREASE_BY, MULTIPLY_BY, DIVIDE_BY, MODULO_BY };
	enum class SignOper { PLUS, MINUS };
	enum class ArithmeticOper { ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, MODULO };
	enum class CompareOper { EQUAL, GREATER, EQ_GREATER, LESSER, EQ_LESSER, NOT_EQUAL };
	enum class LogicOper { AND, OR, NOT };

	struct MSG
	{
		MsgType type = MsgType::ERROR;
		union {
			struct {
				Variable var;
				Value value;
			} create_var;

			/*struct {
			} create_arr;*/

			struct {
				Variable varWhat;
				bool isByVar;
				union {
					Variable varBy;
					Value valueBy;
				};
				Value result;
			} set_var;

			/*struct {
			} set_arr*/

			struct {
				ChangeOper change_type;
				Variable varWhat;
				bool isByVar;
				union {
					Variable varBy;
					Value valueBy;
				};
				Value result;
			} oper_change_by;

			struct {
				SignOper sign_type;
				bool isVar;
				union {
					Variable var;
					Value value;
				};
				Value result;
			} oper_sign;

			struct {
				ArithmeticOper arithm_type;
				bool is1var;
				bool is2var;
				union {
					Variable var1;
					Value value1;
				};
				union {
					Variable var2;
					Value value2;
				};
				Value result;
			} oper_arithm;

			struct {
				LogicOper logic_type;
				bool is1var;
				bool is2var;
				union {
					Variable var1;
					Value value1;
				};
				union {
					Variable var2;
					Value value2;
				};
				Value result;
			} oper_logic;

			struct {
				CompareOper comp_type;
				bool is1var;
				bool is2var;
				union {
					Variable var1;
					Value value1;
				};
				union {
					Variable var2;
					Value value2;
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

}