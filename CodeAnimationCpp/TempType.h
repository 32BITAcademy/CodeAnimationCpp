#pragma once
#include "BasicTypes.h"

namespace ca {

	class TempType
	{
	public:
		Value val;

		TempType(Value value);
		TempType(const TempType& b);

	private:
		static void SendArithmeticByMSG(TempType& a, TempType& b, ArithmeticOper ao, Value result);
		
		template <typename T>
		static void SendArithmeticByMSG(TempType& a, BasicType<T>& b, ArithmeticOper ao, Value result);

		template <typename T>
		static void SendArithmeticByMSG(TempType& a, T& b, ArithmeticOper ao, Value result);

		template <typename T>
		static void SendArithmeticByMSG(T& a, TempType& b, ArithmeticOper ao, Value result);

	public:
		TempType operator+(TempType& b);
		TempType operator-(TempType& b);
		TempType operator*(TempType& b);
		TempType operator/(TempType& b);
		TempType operator%(TempType& b);

		template <typename T>
		TempType operator+(T b);

		template <typename T>
		TempType operator-(T b);

		template <typename T>
		TempType operator*(T b);

		template <typename T>
		TempType operator/(T b);

		template <typename T>
		TempType operator%(T b);

		template <typename T>
		friend TempType operator+(T a, TempType& b);

		template <typename T>
		friend TempType operator-(T a, TempType& b);

		template <typename T>
		friend TempType operator*(T a, TempType& b);

		template <typename T>
		friend TempType operator/(T a, TempType& b);

		template <typename T>
		friend TempType operator%(T a, TempType& b);
	};

}