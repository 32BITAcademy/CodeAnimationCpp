#pragma once
#include "CodeAnimation.h"
#include <type_traits>

namespace ca {

	template <typename T> class BasicType;

	template <typename A>
	std::ostream& operator<<(std::ostream& out, BasicType<A> a)
	{
		return out << a.real_value;
	}

#pragma region COMPARE VALUE WITH VAR

	template <typename A, typename S>
	bool operator==(S a, BasicType<A>& b)
	{
		bool res = (a == b.real_value);
		SendCompareMSG(a, b, CompareOper::EQUAL, res);
		return res;
	}

	template <typename A, typename S>
	bool operator!=(S a, BasicType<A>& b)
	{
		bool res = (a != b.real_value);
		SendCompareMSG(a, b, CompareOper::NOT_EQUAL, res);
		return res;
	}

	template <typename A, typename S>
	bool operator>(S a, BasicType<A>& b)
	{
		bool res = (a > b.real_value);
		SendCompareMSG(a, b, CompareOper::GREATER, res);
		return res;
	}

	template <typename A, typename S>
	bool operator>=(S a, BasicType<A>& b)
	{
		bool res = (a >= b.real_value);
		SendCompareMSG(a, b, CompareOper::EQ_GREATER, res);
		return res;
	}

	template <typename A, typename S>
	bool operator<(S a, BasicType<A>& b)
	{
		bool res = (a < b.real_value);
		SendCompareMSG(a, b, CompareOper::LESSER, res);
		return res;
	}

	template <typename A, typename S>
	bool operator<=(S a, BasicType<A>& b)
	{
		bool res = (a <= b.real_value);
		SendCompareMSG(a, b, CompareOper::EQ_LESSER, res);
		return res;
	}

#pragma endregion //COMPARE VALUE WITH VAR

	template <typename T>
	class BasicType
	{
		T real_value;
		Variable var;

		BasicType() {}
	public:

#pragma region CONSTRUCTORS

		BasicType(const char* name) : real_value(0) {
			if (std::is_same<T, int>::value) var.value.type = DataType::INT;
			if (std::is_same<T, float>::value) var.value.type = DataType::FLOAT;
			if (std::is_same<T, double>::value) var.value.type = DataType::DOUBLE;
			if (std::is_same<T, bool>::value) var.value.type = DataType::BOOL;
			if (std::is_same<T, char>::value) var.value.type = DataType::CHAR;
			strcpy_s(var.name, NAME_LENGTH, name);
			var.value.isGarbage = true;

			CodeAnimation* ca = CodeAnimation::GetInstance();
			MSG m;
			m.type = MsgType::CREATE_VAR;
			m.create_var.var = var;
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		template  <typename S>
		BasicType(const char* name, S v) {
			if (std::is_same<T, int>::value) var.value.type = DataType::INT;
			if (std::is_same<T, float>::value) var.value.type = DataType::FLOAT;
			if (std::is_same<T, double>::value) var.value.type = DataType::DOUBLE;
			if (std::is_same<T, bool>::value) var.value.type = DataType::BOOL;
			if (std::is_same<T, char>::value) var.value.type = DataType::CHAR;
			strcpy_s(var.name, NAME_LENGTH, name);
			real_value = (T)v;
			var.SetValue(real_value);

			CodeAnimation* ca = CodeAnimation::GetInstance();
			MSG m;
			m.type = MsgType::CREATE_VAR;
			m.create_var.var = var;
			m.create_var.value.SetValue(v);
			m.create_var.value.type = GetType(v);
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		BasicType(const BasicType& b) {
			var = b.var;
			real_value = b.real_value;
		}

		~BasicType() {}

#pragma endregion //CONSTRUCTORS

#pragma region SETTERS

		T value() { return real_value; }
		void value(T v, bool not_garbage = true) { real_value = v; if (not_garbage) var.SetValue(v); }
		DataType type() { return var.value.type; }
		const char* name() { return var.name; }

		template <typename S>
		BasicType<T>& operator=(BasicType<S>& b)
		{
			CodeAnimation* ca = CodeAnimation::GetInstance();
			MSG m;
			m.type = MsgType::SET_VAR;
			m.set_var.varWhat = var;
			m.set_var.isByVar = true;
			m.set_var.varBy = b.var;

			real_value = (T)b.real_value;
			var.SetValue(real_value);

			m.set_var.result = var.value;
			ca->Send(m);

			ca->WaitEndOfAnimation();
			return *this;
		}

		template <typename S>
		BasicType<T>& operator=(S b)
		{
			CodeAnimation* ca = CodeAnimation::GetInstance();
			MSG m;
			m.type = MsgType::SET_VAR;
			m.set_var.varWhat = var;
			m.set_var.isByVar = false;
			m.set_var.valueBy.type = GetType(b);
			m.set_var.valueBy.SetValue(b);

			real_value = (T)b;
			var.SetValue(real_value);

			m.set_var.result = var.value;
			ca->Send(m);

			ca->WaitEndOfAnimation();
			return *this;
		}

#pragma endregion //SETTERS

#pragma region CHANGE BY VAR

		template <typename S>
		static void SendChangeByMSG(BasicType<T>& a, BasicType<S>& b, ChangeOper co, T result)
		{
			MSG m;
			m.type = MsgType::OPER_CHANGE_BY;
			m.oper_change_by.change_type = co;
			m.oper_change_by.varWhat = a.var;
			m.oper_change_by.isByVar = true;
			m.oper_change_by.varBy = b.var;

			if (a.var.IsSet() && b.var.IsSet())
			{
				m.oper_change_by.result.type = GetType(result);
				m.oper_change_by.result.SetValue(result);
			}
			else
			{
				m.oper_change_by.result.type = GetType(result);
				m.oper_change_by.result.isGarbage = true;
			}

			CodeAnimation* ca = CodeAnimation::GetInstance();
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		template <typename S>
		BasicType<T>& operator+=(BasicType<S>& b)
		{
			T result = real_value + b.real_value;
			SendChangeByMSG(*this, b, ChangeOper::INCREASE_BY, result);
			value(result, var.IsSet() && b.var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator-=(BasicType<S>& b)
		{
			T result = real_value - b.real_value;
			SendChangeByMSG(*this, b, ChangeOper::DECREASE_BY, result);
			value(result, var.IsSet() && b.var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator*=(BasicType<S>& b)
		{
			T result = real_value * b.real_value;
			SendChangeByMSG(*this, b, ChangeOper::MULTIPLY_BY, result);
			value(result, var.IsSet() && b.var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator/=(BasicType<S>& b)
		{
			T result = real_value / b.real_value;
			SendChangeByMSG(*this, b, ChangeOper::DIVIDE_BY, result);
			value(result, var.IsSet() && b.var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator%=(BasicType<S>& b)
		{
			T result = real_value % b.real_value;
			SendChangeByMSG(*this, b, ChangeOper::MODULO_BY, result);
			value(result, var.IsSet() && b.var.IsSet());
			return *this;
		}

#pragma endregion //CHANGE BY VAR

#pragma region CHANGE BY VALUE

		template <typename S>
		static void SendChangeByMSG(BasicType<T>& a, S& b, ChangeOper co, T result)
		{
			MSG m;
			m.type = MsgType::OPER_CHANGE_BY;
			m.oper_change_by.change_type = co;
			m.oper_change_by.varWhat = a.var;
			m.oper_change_by.isByVar = false;
			m.oper_change_by.valueBy.type = GetType(b);
			m.oper_change_by.valueBy.SetValue(b);

			if (a.var.IsSet())
			{
				m.oper_change_by.result.type = GetType(result);
				m.oper_change_by.result.SetValue(result);
			}
			else
			{
				m.oper_change_by.result.type = GetType(result);
				m.oper_change_by.result.isGarbage = true;
			}

			CodeAnimation* ca = CodeAnimation::GetInstance();
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		template <typename S>
		BasicType<T>& operator+=(S b)
		{
			T result = real_value + b;
			SendChangeByMSG(*this, b, ChangeOper::INCREASE_BY, result);
			value(result, var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator-=(S b)
		{
			T result = real_value - b;
			SendChangeByMSG(*this, b, ChangeOper::DECREASE_BY, result);
			value(result, var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator*=(S b)
		{
			T result = real_value * b;
			SendChangeByMSG(*this, b, ChangeOper::MULTIPLY_BY, result);
			value(result, var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator/=(S b)
		{
			T result = real_value / b;
			SendChangeByMSG(*this, b, ChangeOper::DIVIDE_BY, result);
			value(result, var.IsSet());
			return *this;
		}

		template <typename S>
		BasicType<T>& operator%=(S b)
		{
			T result = real_value % b;
			SendChangeByMSG(*this, b, ChangeOper::MODULO_BY, result);
			value(result, var.IsSet());
			return *this;
		}

		BasicType<T>& operator++()
		{
			return (*this) += 1;
		}

		BasicType<T>& operator++(int)
		{
			return (*this) += 1;
		}

		BasicType<T>& operator--()
		{
			return (*this) -= 1;
		}

		BasicType<T>& operator--(int)
		{
			return (*this) -= 1;
		}

#pragma endregion //CHANGE BY VALUE

#pragma region COMPARE VAR WITH VAR

		template <typename S>
		static void SendCompareMSG(BasicType<T>& a, BasicType<S>& b, CompareOper co, bool result)
		{
			MSG m;
			m.type = MsgType::OPER_COMPARE;
			m.oper_compare.result = result;
			m.oper_compare.comp_type = co;
			m.oper_compare.is1var = true;
			m.oper_compare.is2var = true;
			m.oper_compare.var1 = a.var;
			m.oper_compare.var2 = b.var;

			CodeAnimation* ca = CodeAnimation::GetInstance();
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		template <typename S>
		bool operator==(BasicType<S>& b)
		{
			bool res = (real_value == b.real_value);
			SendCompareMSG(*this, b, CompareOper::EQUAL, res);
			return res;
		}

		template <typename S>
		bool operator!=(BasicType<S>& b)
		{
			bool res = (real_value != b.real_value);
			SendCompareMSG(*this, b, CompareOper::NOT_EQUAL, res);
			return res;
		}

		template <typename S>
		bool operator>(BasicType<S>& b)
		{
			bool res = (real_value > b.real_value);
			SendCompareMSG(*this, b, CompareOper::GREATER, res);
			return res;
		}

		template <typename S>
		bool operator>=(BasicType<S>& b)
		{
			bool res = (real_value >= b.real_value);
			SendCompareMSG(*this, b, CompareOper::EQ_GREATER, res);
			return res;
		}

		template <typename S>
		bool operator<(BasicType<S>& b)
		{
			bool res = (real_value < b.real_value);
			SendCompareMSG(*this, b, CompareOper::LESSER, res);
			return res;
		}

		template <typename S>
		bool operator<=(BasicType<S>& b)
		{
			bool res = (real_value <= b.real_value);
			SendCompareMSG(*this, b, CompareOper::EQ_LESSER, res);
			return res;
		}

#pragma endregion //COMPARE VAR WITH VAR

#pragma region COMPARE VAR WITH VALUE

		template <typename S>
		static void SendCompareMSG(S& a, BasicType<T>& b, CompareOper co, bool result)
		{
			MSG m;
			m.type = MsgType::OPER_COMPARE;
			m.oper_compare.result = result;
			m.oper_compare.comp_type = co;
			m.oper_compare.is1var = false;
			m.oper_compare.is2var = true;
			SetValue(m.oper_compare.value1.value, a);
			m.oper_compare.value1.type = GetType(a);
			m.oper_compare.var2 = b.var;

			CodeAnimation* ca = CodeAnimation::GetInstance();
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		template <typename S>
		static void SendCompareMSG(BasicType<T>& a, S& b, CompareOper co, bool result)
		{
			MSG m;
			m.type = MsgType::OPER_COMPARE;
			m.oper_compare.result = result;
			m.oper_compare.comp_type = co;
			m.oper_compare.is1var = true;
			m.oper_compare.is2var = false;
			m.oper_compare.var1 = a.var;
			SetValue(m.oper_compare.value2.value, b);
			m.oper_compare.value2.type = GetType(b);

			CodeAnimation* ca = CodeAnimation::GetInstance();
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		template <typename S>
		bool operator==(S b)
		{
			bool res = (real_value == b);
			SendCompareMSG(*this, b, CompareOper::EQUAL, res);
			return res;
		}

		template <typename S>
		bool operator!=(S b)
		{
			bool res = (real_value != b);
			SendCompareMSG(*this, b, CompareOper::NOT_EQUAL, res);
			return res;
		}

		template <typename S>
		bool operator>(S b)
		{
			bool res = (real_value > b);
			SendCompareMSG(*this, b, CompareOper::GREATER, res);
			return res;
		}

		template <typename S>
		bool operator>=(S b)
		{
			bool res = (real_value >= b);
			SendCompareMSG(*this, b, CompareOper::EQ_GREATER, res);
			return res;
		}

		template <typename S>
		bool operator<(S b)
		{
			bool res = (real_value < b);
			SendCompareMSG(*this, b, CompareOper::LESSER, res);
			return res;
		}

		template <typename S>
		bool operator<=(S b)
		{
			bool res = (real_value <= b);
			SendCompareMSG(*this, b, CompareOper::EQ_LESSER, res);
			return res;
		}

#pragma endregion //COMPARE VAR WITH VALUE

#pragma region FRIENDS

		template <typename A, typename S>
		friend bool operator== <T>(S a, BasicType<A>& b);

		template <typename A, typename S>
		friend bool operator!= <T>(S a, BasicType<A>& b);

		template <typename A, typename S>
		friend bool operator> <T>(S a, BasicType<A>& b);

		template <typename A, typename S>
		friend bool operator>= <T>(S a, BasicType<A>& b);

		template <typename A, typename S>
		friend bool operator< <T>(S a, BasicType<A>& b);

		template <typename A, typename S>
		friend bool operator<= <T>(S a, BasicType<A>& b);
		
		template <typename A>
		friend std::ostream& operator<< <T>(std::ostream& out, BasicType<A> a);
#pragma endregion //FRIENDS

	};

}

// SPECIALIZATIONS

typedef ca::BasicType<int> INT;
typedef ca::BasicType<float> FLOAT;
typedef ca::BasicType<double> DOUBLE;
typedef ca::BasicType<bool> BOOL;
typedef ca::BasicType<char> CHAR;