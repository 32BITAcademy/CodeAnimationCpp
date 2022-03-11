#pragma once
#include<string>
#include"DataTypes.h"

namespace ca
{
	struct Variable;

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

		void Set(const Value& b);

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
			isGarbage = false;
		}

		void Copy(Value& b);

		const Value& operator=(const Value& b);

		friend const Value operator+ (const Value& a, const Value& b);
		friend const Value operator- (const Value& a, const Value& b);
		friend const Value operator* (const Value& a, const Value& b);
		friend const Value operator/ (const Value& a, const Value& b);
		friend const Value operator% (const Value& a, const Value& b);
		friend const Value operator==(const Value& a, const Value& b);
		friend const Value operator!=(const Value& a, const Value& b);
		friend const Value operator>=(const Value& a, const Value& b);
		friend const Value operator> (const Value& a, const Value& b);
		friend const Value operator<=(const Value& a, const Value& b);
		friend const Value operator< (const Value& a, const Value& b);
		friend const Value operator&&(const Value& a, const Value& b);
		friend const Value operator||(const Value& a, const Value& b);
		friend const Value operator! (const Value& a);

		/*Value operator+(const Variable& b);
		Value operator-(const Variable& b);
		Value operator*(const Variable& b);
		Value operator/(const Variable& b);
		Value operator%(const Variable& b);

		Value operator==(const Variable& b);
		Value operator!=(const Variable& b);
		Value operator>=(const Variable& b);
		Value operator>(const Variable& b);
		Value operator<=(const Variable& b);
		Value operator<(const Variable& b);

		Value operator&&(const Variable& b);
		Value operator||(const Variable& b);*/

		bool GetBool();
	};

	const Value operator+ (const Value& a, const Value& b);
	const Value operator- (const Value& a, const Value& b);
	const Value operator* (const Value& a, const Value& b);
	const Value operator/ (const Value& a, const Value& b);
	const Value operator% (const Value& a, const Value& b);
	const Value operator==(const Value& a, const Value& b);
	const Value operator!=(const Value& a, const Value& b);
	const Value operator>=(const Value& a, const Value& b);
	const Value operator> (const Value& a, const Value& b);
	const Value operator<=(const Value& a, const Value& b);
	const Value operator< (const Value& a, const Value& b);
	const Value operator&&(const Value& a, const Value& b);
	const Value operator||(const Value& a, const Value& b);
	const Value operator! (const Value& a);
}