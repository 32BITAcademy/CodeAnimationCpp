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

		Variable& operator=(Variable& b);

		template <typename T>
		Variable& operator=(T b);

		Value operator+(Variable& b);
		Value operator-(Variable& b);
		Value operator*(Variable& b);
		Value operator/(Variable& b);
		Value operator%(Variable& b);

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

		Value operator==(Variable& b);
		Value operator!=(Variable& b);
		Value operator>=(Variable& b);
		Value operator> (Variable& b);
		Value operator<=(Variable& b);
		Value operator< (Variable& b);

		Value operator==(Value& b);
		Value operator!=(Value& b);
		Value operator>=(Value& b);
		Value operator> (Value& b);
		Value operator<=(Value& b);
		Value operator< (Value& b);

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

		Value operator!();
		Value operator&&(Variable& b);
		Value operator||(Variable& b);

		Value operator&&(Value& b);
		Value operator||(Value& b);

		Value operator&&(bool b);
		Value operator||(bool b);

		operator bool();
	};
	
}