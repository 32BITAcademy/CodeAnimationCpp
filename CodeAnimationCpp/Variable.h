#pragma once
#include "Value.h"
#define NAME_LENGTH 200

namespace ca {

	struct Variable
	{
		char name[NAME_LENGTH];
		Value value;

		std::string GetOnlyValue();
		std::string GetShortString();
		std::string GetFullString();
		bool IsSet();

		template <typename T>
		void SetValue(T v)
		{
			value.SetValue(v);
		}

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

		bool operator==(Variable& b);
		bool operator!=(Variable& b);
		bool operator>=(Variable& b);
		bool operator> (Variable& b);
		bool operator<=(Variable& b);
		bool operator< (Variable& b);

		bool operator==(Value& b);
		bool operator!=(Value& b);
		bool operator>=(Value& b);
		bool operator> (Value& b);
		bool operator<=(Value& b);
		bool operator< (Value& b);

		template <typename T>
		bool operator==(T b);

		template <typename T>
		bool operator!=(T b);

		template <typename T>
		bool operator>=(T b);

		template <typename T>
		bool operator>(T b);

		template <typename T>
		bool operator<=(T b);

		template <typename T>
		bool operator<(T b);
	};
	
}