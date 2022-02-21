#pragma once
#include<string>
#include"DataTypes.h"

namespace ca
{
	struct Value
	{
		UniValue uv;
		DataType type;
		bool isGarbage = true;

		std::string GetOnlyValue();
		std::string GetShortString();
		std::string GetFullString();

		template <typename T>
		void SetValue(T v)
		{
			uv.SetValue(v);
			isGarbage = false;
		}

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

		bool operator==(Value& b);
		bool operator!=(Value& b);
		bool operator>=(Value& b);
		bool operator>(Value& b);
		bool operator<=(Value& b);
		bool operator<(Value& b);

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