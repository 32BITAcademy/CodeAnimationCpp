#pragma once
#include<string>
#include"DataTypes.h"

namespace ca
{
	struct Value;

	template <typename T>
	Value operator+(T a, Value b);

	template <typename T>
	Value operator-(T a, Value b);

	template <typename T>
	Value operator*(T a, Value b);

	template <typename T>
	Value operator/(T a, Value b);

	template <typename T>
	Value operator%(T a, Value b);

	template <typename T>
	Value operator==(T a, Value b);

	template <typename T>
	Value operator!=(T a, Value b);

	template <typename T>
	Value operator>=(T a, Value b);

	template <typename T>
	Value operator>(T a, Value b);

	template <typename T>
	Value operator<=(T a, Value b);

	template <typename T>
	Value operator<(T a, Value b);

	struct Value
	{
		UniValue uv;
		DataType type;
		bool isGarbage = true;

		Value();
		Value(const Value&);
		Value(int v);
		Value(float v);
		Value(double v);
		Value(bool v);
		Value(char v);

		std::string GetOnlyValue();
		std::string GetShortString();
		std::string GetFullString();

		void SetValue(Value& b);

		template <typename T>
		void SetValue(T v)
		{
			isGarbage = false;
			switch (type)
			{
			case DataType::INT: uv.SetValue((int)v); break;
			case DataType::FLOAT: uv.SetValue((float)v); break;
			case DataType::DOUBLE: uv.SetValue((double)v); break;
			case DataType::BOOL: uv.SetValue((bool)v); break;
			case DataType::CHAR: uv.SetValue((char)v); break;
			}
		}

		template <typename T>
		void SetType(T v)
		{
			type = GetType(v);
		}
		
		template <typename T>
		void SetFull(T v)
		{
			type = GetType(v);
			uv.SetValue(v);
		}

		void Copy(Value& b);

		Value& operator=(Value& b);
		
		template <typename T>
		Value& operator=(T b);

		Value operator+(Value& b);
		Value operator-(Value& b);
		Value operator*(Value& b);
		Value operator/(Value& b);
		Value operator%(Value& b);

		template <typename T>
		Value operator+(T b);

		template <typename T>
		Value operator-(T b);

		template <typename T>
		Value operator*(T b);

		template <typename T>
		Value operator/(T b);

		template <typename T>
		Value operator%(T b);

		template <typename T>
		friend Value operator+(T a, Value b);

		template <typename T>
		friend Value operator-(T a, Value b);

		template <typename T>
		friend Value operator*(T a, Value b);

		template <typename T>
		friend Value operator/(T a, Value b);

		template <typename T>
		friend Value operator%(T a, Value b);

		Value operator==(Value& b);
		Value operator!=(Value& b);
		Value operator>=(Value& b);
		Value operator>(Value& b);
		Value operator<=(Value& b);
		Value operator<(Value& b);

		template <typename T>
		Value operator==(T b);

		template <typename T>
		Value operator!=(T b);

		template <typename T>
		Value operator>=(T b);

		template <typename T>
		Value operator>(T b);

		template <typename T>
		Value operator<=(T b);

		template <typename T>
		Value operator<(T b);

		template <typename T>
		friend Value operator==(T a, Value b);

		template <typename T>
		friend Value operator!=(T a, Value b);

		template <typename T>
		friend Value operator>=(T a, Value b);

		template <typename T>
		friend Value operator>(T a, Value b);

		template <typename T>
		friend Value operator<=(T a, Value b);

		template <typename T>
		friend Value operator<(T a, Value b);

		Value operator!();
		Value operator&&(Value& b);
		Value operator||(Value& b);

		Value operator&&(bool b);
		Value operator||(bool b);

		friend Value operator&&(bool a, Value b);
		friend Value operator||(bool a, Value b);

		bool GetBool();
	};
	

	Value operator&&(bool a, Value b);
	Value operator||(bool a, Value b);
}