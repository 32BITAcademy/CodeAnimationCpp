#pragma once
#include "Value.h"
#define NAME_LENGTH 200

namespace ca {

	struct Variable
	{
	public:
		char name[NAME_LENGTH];
		Value value;

		Variable(const Variable& v);
		Variable(const char* n, DataType t);
		Variable(const char* n, int v);
		Variable(const char* n, float v);
		Variable(const char* n, double v);
		Variable(const char* n, bool v);
		Variable(const char* n, char v);

		std::string GetOnlyValue();
		std::string GetShortString();
		std::string GetFullString();
		bool IsSet();

		template <typename T>
		void SetValue(T v)
		{
			value.SetValue(v);
		}

		const Variable& operator=(const Variable& b);
		const Variable& operator=(const Value& b);

		Value operator+(const Variable& b);
		Value operator-(const Variable& b);
		Value operator*(const Variable& b);
		Value operator/(const Variable& b);
		Value operator%(const Variable& b);

		Value operator+(const Value& b);
		Value operator-(const Value& b);
		Value operator*(const Value& b);
		Value operator/(const Value& b);
		Value operator%(const Value& b);

		Value operator==(const Variable& b);
		Value operator!=(const Variable& b);
		Value operator>=(const Variable& b);
		Value operator> (const Variable& b);
		Value operator<=(const Variable& b);
		Value operator< (const Variable& b);

		Value operator==(const Value& b);
		Value operator!=(const Value& b);
		Value operator>=(const Value& b);
		Value operator> (const Value& b);
		Value operator<=(const Value& b);
		Value operator< (const Value& b);

		Value operator!();
		Value operator&&(const Variable& b);
		Value operator||(const Variable& b);

		Value operator&&(const Value& b);
		Value operator||(const Value& b);

		bool GetBool();
	};
}