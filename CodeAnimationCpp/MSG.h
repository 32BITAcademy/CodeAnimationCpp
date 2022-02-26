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
			struct CR_VAR{
				Variable var;
				Value value;
				
				CR_VAR& operator=(const CR_VAR& b) {
					var = b.var;
					value = b.value;
					return *this;
				}
			} create_var;

			/*struct {
			} create_arr;*/

			struct SET_VAR{
				Variable varWhat;
				bool isByVar;
				union {
					Variable varBy;
					Value valueBy;
				};
				Value result;
				
				SET_VAR& operator=(const SET_VAR& b) {
					varWhat = b.varWhat;
					isByVar = b.isByVar;
					if (isByVar)
						varBy = b.varBy;
					else
						valueBy = b.valueBy;
					return *this;
				}
			} set_var;

			/*struct {
			} set_arr*/

			struct CH_VAR{
				ChangeOper change_type;
				Variable varWhat;
				bool isByVar;
				union {
					Variable varBy;
					Value valueBy;
				};
				Value result;

				CH_VAR& operator=(const CH_VAR &b) {
					change_type = b.change_type;
					varWhat = b.varWhat;
					result = b.result;
					isByVar = b.isByVar;
					if (isByVar)
						varBy = b.varBy;
					else
						valueBy = b.valueBy;
					return *this;
				}
			} oper_change_by;

			struct SI_OPER{
				SignOper sign_type;
				bool isVar;
				union {
					Variable var;
					Value value;
				};
				Value result;

				SI_OPER& operator=(const SI_OPER &b) {
					sign_type = b.sign_type;
					result = b.result;
					isVar = b.isVar;
					if (isVar)
						var = b.var;
					else
						value = b.value;
					return *this;
				}
			} oper_sign;

			struct AR_OPER{
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

				AR_OPER& operator=(const AR_OPER &b) {
					arithm_type = b.arithm_type;
					result = b.result;
					is1var = b.is1var;
					is2var = b.is2var;
					if (is1var)
						var1 = b.var1;
					else
						value1 = b.value1;
					if (is2var)
						var2 = b.var2;
					else
						value2 = b.value2;
					return *this;
				}
			} oper_arithm;

			struct LO_OPER{
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

				LO_OPER& operator=(const LO_OPER &b) {
					logic_type = b.logic_type;
					result = b.result;
					is1var = b.is1var;
					is2var = b.is2var;
					if (is1var)
						var1 = b.var1;
					else
						value1 = b.value1;
					if (is2var)
						var2 = b.var2;
					else
						value2 = b.value2;
					return *this;
				}
			} oper_logic;

			struct CO_OPER{
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
				Value result;

				CO_OPER& operator=(const CO_OPER &b) {
					comp_type = b.comp_type;
					result = b.result;
					is1var = b.is1var;
					is2var = b.is2var;
					if (is1var)
						var1 = b.var1;
					else
						value1 = b.value1;
					if (is2var)
						var2 = b.var2;
					else
						value2 = b.value2;
					return *this;
				}
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