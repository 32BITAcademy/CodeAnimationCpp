#pragma once
#include "CodeAnimationController.h"
#include "MSG.h"
#include <type_traits>

namespace ca {

	template <typename T> class BasicType;

	void SendChangeByMSG(Variable a, Variable b, ChangeOper co, Value result);
	void SendChangeByMSG(Variable a, Value b, ChangeOper co, Value result);
	
	void SendArithmeticMSG(Variable a, Variable b, ArithmeticOper ao, Value result);
	void SendArithmeticMSG(Value a, Variable b, ArithmeticOper ao, Value result);
	void SendArithmeticMSG(Variable a, Value b, ArithmeticOper ao, Value result);
	void SendArithmeticMSG(Value a, Value b, ArithmeticOper ao, Value result);

	void SendCompareMSG(Variable a, Variable b, CompareOper co, Value result);
	void SendCompareMSG(Value a, Variable b, CompareOper co, Value result);
	void SendCompareMSG(Variable a, Value b, CompareOper co, Value result);
	void SendCompareMSG(Value a, Value b, CompareOper co, Value result);

	template <typename A>
	std::ostream& operator<<(std::ostream& out, BasicType<A> a)
	{
		return out << a.real_value;
	}

#pragma region COMPARE VALUE WITH VAR

	template <typename A, typename S>
	bool operator==(S a, BasicType<A>& b)
	{
		Value res = Value(a) == b.var;
		SendCompareMSG(Value(a), b.var, CompareOper::EQUAL, res);
		return res.GetBool();
	}

	template <typename A, typename S>
	bool operator!=(S a, BasicType<A>& b)
	{
		Value res = Value(a) != b.var;
		SendCompareMSG(Value(a), b.var, CompareOper::NOT_EQUAL, res);
		return res.GetBool();
	}

	template <typename A, typename S>
	bool operator>(S a, BasicType<A>& b)
	{
		Value res = Value(a) > b.var;
		SendCompareMSG(Value(a), b.var, CompareOper::GREATER, res);
		return res.GetBool();
	}

	template <typename A, typename S>
	bool operator>=(S a, BasicType<A>& b)
	{
		Value res = Value(a) >= b.var;
		SendCompareMSG(Value(a), b.var, CompareOper::EQ_GREATER, res);
		return res.GetBool();
	}

	template <typename A, typename S>
	bool operator<(S a, BasicType<A>& b)
	{
		Value res = Value(a) < b.var;
		SendCompareMSG(Value(a), b.var, CompareOper::LESSER, res);
		return res.GetBool();
	}

	template <typename A, typename S>
	bool operator<=(S a, BasicType<A>& b)
	{
		Value res = Value(a) <= b.var;
		SendCompareMSG(Value(a), b.var, CompareOper::EQ_LESSER, res);
		return res.GetBool();
	}

#pragma endregion //COMPARE VALUE WITH VAR

	template <typename T>
	class BasicType
	{
		static_assert(std::is_fundamental<T>::value, "BasicType can only be used for fundamental types (like int, float, bool, etc.)");
	public:

		T real_value;
		Variable var;

#pragma region CONSTRUCTORS

		BasicType(const char* name) : real_value(T(0)), var(name, GetType(T(0))) {
			real_value = (T)0;
			var.value.isGarbage = true;
			var.value.SetType((T)0);

			CodeAnimationController* ca = CodeAnimationController::GetInstance();
			MSG m;
			m.type = MsgType::CREATE_VAR;
			m.create_var.var = var;
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		template  <typename S>
		BasicType(const char* name, S v) : real_value(T(v)), var(name, GetType(T(v))) {
			strcpy_s(var.name, NAME_LENGTH, name);
			real_value = (T)v;
			var.value.SetFull(real_value);

			CodeAnimationController* ca = CodeAnimationController::GetInstance();
			MSG m;
			m.type = MsgType::CREATE_VAR;
			m.create_var.var = var;
			m.create_var.value.SetFull(v);
			ca->Send(m);

			ca->WaitEndOfAnimation();
		}

		BasicType(const BasicType& b) : var(b.var) {
			real_value = b.real_value;
		}

		~BasicType() {}

		operator bool()
		{
			return var.GetBool();
		}

#pragma endregion //CONSTRUCTORS

#pragma region SETTERS

		T value() { return real_value; }
		void value(T v, bool not_garbage = true) { real_value = v; if (not_garbage) var.SetValue(v); }
		DataType type() { return var.value.type; }
		const char* name() { return var.name; }

		template <typename S>
		BasicType<T>& operator=(BasicType<S>& b)
		{
			CodeAnimationController* ca = CodeAnimationController::GetInstance();
			MSG m;
			m.type = MsgType::SET_VAR;
			m.set_var.varWhat = var;
			m.set_var.isByVar = true;
			m.set_var.varBy = b.var;

			real_value = (T)b.real_value;
			var.value = b.var.value;

			m.set_var.result = var.value;
			ca->Send(m);

			ca->WaitEndOfAnimation();
			return *this;
		}

		template <typename S>
		BasicType<T>& operator=(S b)
		{
			CodeAnimationController* ca = CodeAnimationController::GetInstance();
			MSG m;
			m.type = MsgType::SET_VAR;
			m.set_var.varWhat = var;
			m.set_var.isByVar = false;
			m.set_var.valueBy.SetFull(b);

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
		BasicType<T>& operator+=(BasicType<S>& b)
		{
			Variable a(var);
			var = var + b.var;
			SendChangeByMSG(a, b.var, ChangeOper::INCREASE_BY, var.value);
			real_value += b.real_value;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator-=(BasicType<S>& b)
		{
			Variable a(var);
			var = var - b.var;
			SendChangeByMSG(a, b.var, ChangeOper::DECREASE_BY, var.value);
			real_value -= b.real_value;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator*=(BasicType<S>& b)
		{
			Variable a(var);
			var = var * b.var;
			SendChangeByMSG(a, b.var, ChangeOper::MULTIPLY_BY, var.value);
			real_value *= b.real_value;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator/=(BasicType<S>& b)
		{
			Variable a(var);
			var /= b.var;
			SendChangeByMSG(a, b.var, ChangeOper::DIVIDE_BY, var.value);
			real_value /= b.real_value;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator%=(BasicType<S>& b)
		{
			Variable a(var);
			var %= b.var;
			SendChangeByMSG(a, b.var, ChangeOper::MODULO_BY, var.value);
			real_value %= b.real_value;
			return *this;
		}

#pragma endregion //CHANGE BY VAR

#pragma region CHANGE BY VALUE
		
		template <typename S>
		BasicType<T>& operator+=(S b)
		{
			Variable a(var);
			var = var.value + Value(b);
			SendChangeByMSG(a, Value(b), ChangeOper::INCREASE_BY, var.value);
			real_value += b;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator-=(S b)
		{
			Variable a(var);
			var = var - Value(b);
			SendChangeByMSG(a, Value(b), ChangeOper::DECREASE_BY, var.value);
			real_value -= b;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator*=(S b)
		{
			Variable a = var;
			var = var * Value(b);
			SendChangeByMSG(a, Value(b), ChangeOper::MULTIPLY_BY, var.value);
			real_value *= b;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator/=(S b)
		{
			Variable a(var);
			var.value = var.value / Value(b);
			SendChangeByMSG(a, b, ChangeOper::DIVIDE_BY, var.value);
			real_value /= b;
			return *this;
		}

		template <typename S>
		BasicType<T>& operator%=(S b)
		{
			Variable a = var;
			var.value = var.value % Value(b);
			SendChangeByMSG(a, b, ChangeOper::MODULO_BY, var.value);
			real_value %= b;
			return *this;
		}

		BasicType<T>& operator++()
		{
			return (*this) += 1;
		}

		BasicType<T> operator++(int)
		{
			BasicType<T> tmp(*this);
			(*this) += 1;
			return tmp;
		}

		BasicType<T>& operator--()
		{
			return (*this) -= 1;
		}

		BasicType<T> operator--(int)
		{
			BasicType<T> tmp(*this);
			(*this) -= 1;
			return tmp;
		}

#pragma endregion //CHANGE BY VALUE

#pragma region COMPARE VAR WITH VAR

		template <typename S>
		bool operator==(BasicType<S>& b)
		{
			Value res = var == b.var;
			SendCompareMSG(var, b.var, CompareOper::EQUAL, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator!=(BasicType<S>& b)
		{
			Value res = var != b.var;
			SendCompareMSG(var, b.var, CompareOper::NOT_EQUAL, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator>(BasicType<S>& b)
		{
			Value res = var > b.var;
			SendCompareMSG(var, b.var, CompareOper::GREATER, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator>=(BasicType<S>& b)
		{
			Value res = var >= b.var;
			SendCompareMSG(var, b.var, CompareOper::EQ_GREATER, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator<(BasicType<S>& b)
		{
			Value res = var < b.var;
			SendCompareMSG(var, b.var, CompareOper::LESSER, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator<=(BasicType<S>& b)
		{
			Value res = var <= b.var;
			SendCompareMSG(var, b.var, CompareOper::EQ_LESSER, res);
			return res.GetBool();
		}

#pragma endregion //COMPARE VAR WITH VAR

#pragma region COMPARE VAR WITH VALUE

		template <typename S>
		bool operator==(S b)
		{
			Value res = var == Value(b);
			SendCompareMSG(var, Value(b), CompareOper::EQUAL, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator!=(S b)
		{
			Value res = var != Value(b);
			SendCompareMSG(var, Value(b), CompareOper::NOT_EQUAL, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator>(S b)
		{
			Value res = var > Value(b);
			SendCompareMSG(var, Value(b), CompareOper::GREATER, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator>=(S b)
		{
			Value res = var >= Value(b);
			SendCompareMSG(var, Value(b), CompareOper::EQ_GREATER, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator<(S b)
		{
			Value res = var < Value(b);
			SendCompareMSG(var, Value(b), CompareOper::LESSER, res);
			return res.GetBool();
		}

		template <typename S>
		bool operator<=(S b)
		{
			Value res = var <= Value(b);
			SendCompareMSG(var, Value(b), CompareOper::EQ_LESSER, res);
			return res.GetBool();
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