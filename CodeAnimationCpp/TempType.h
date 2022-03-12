#pragma once
#include "BasicTypes.h"

namespace ca {

	class TempType
	{
	public:
		Value value;

		TempType(Value v);
		TempType(const TempType& b);

		operator bool();

		const TempType operator+(const TempType& b);
		const TempType operator-(const TempType& b);
		const TempType operator*(const TempType& b);
		const TempType operator/(const TempType& b);
		const TempType operator%(const TempType& b);

		bool operator==(const TempType& b);
		bool operator!=(const TempType& b);
		bool operator>=(const TempType& b);
		bool operator>(const TempType& b);
		bool operator<=(const TempType& b);
		bool operator<(const TempType& b);

		bool operator!();
		bool operator&&(const TempType& b);
		bool operator||(const TempType& b);

		template <typename T>
		const TempType operator+(T b);
		template <typename T>
		const TempType operator-(T b);
		template <typename T>
		const TempType operator*(T b);
		template <typename T>
		const TempType operator/(T b);
		template <typename T>
		const TempType operator%(T b);

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

		template <typename T>
		bool operator&&(T b);
		template <typename T>
		bool operator||(T b);

		template <typename T>
		const TempType operator+(const BasicType<T>& b);
		template <typename T>
		const TempType operator-(const BasicType<T>& b);
		template <typename T>
		const TempType operator*(const BasicType<T>& b);
		template <typename T>
		const TempType operator/(const BasicType<T>& b);
		template <typename T>
		const TempType operator%(const BasicType<T>& b);

		template <typename T>
		bool operator==(const BasicType<T>& b);
		template <typename T>
		bool operator!=(const BasicType<T>& b);
		template <typename T>
		bool operator>=(const BasicType<T>& b);
		template <typename T>
		bool operator>(const BasicType<T>& b);
		template <typename T>
		bool operator<=(const BasicType<T>& b);
		template <typename T>
		bool operator<(const BasicType<T>& b);

		template <typename T>
		bool operator&&(const BasicType<T>& b);
		template <typename T>
		bool operator||(const BasicType<T>& b);
	};

	template <typename T>
	const TempType operator+(T a, const TempType& b);
	template <typename T>
	const TempType operator-(T a, const TempType& b);
	template <typename T>
	const TempType operator*(T a, const TempType& b);
	template <typename T>
	const TempType operator/(T a, const TempType& b);
	template <typename T>
	const TempType operator%(T a, const TempType& b);

	template <typename T>
	bool operator==(T a, const TempType& b);
	template <typename T>
	bool operator!=(T a, const TempType& b);
	template <typename T>
	bool operator>=(T a, const TempType& b);
	template <typename T>
	bool operator>(T a, const TempType& b);
	template <typename T>
	bool operator<=(T a, const TempType& b);
	template <typename T>
	bool operator<(T a, const TempType& b);

	template <typename T>
	bool operator&&(T a, const TempType& b);
	template <typename T>
	bool operator||(T a, const TempType& b);

	template <typename T>
	const TempType operator+(const BasicType<T>& a, const TempType& b);
	template <typename T>
	const TempType operator-(const BasicType<T>& a, const TempType& b);
	template <typename T>
	const TempType operator*(const BasicType<T>& a, const TempType& b);
	template <typename T>
	const TempType operator/(const BasicType<T>& a, const TempType& b);
	template <typename T>
	const TempType operator%(const BasicType<T>& a, const TempType& b);

	template <typename T, typename S>
	const TempType operator+(const BasicType<T>& a, S b);
	template <typename T, typename S>
	const TempType operator-(const BasicType<T>& a, S b);
	template <typename T, typename S>
	const TempType operator*(const BasicType<T>& a, S b);
	template <typename T, typename S>
	const TempType operator/(const BasicType<T>& a, S b);
	template <typename T, typename S>
	const TempType operator%(const BasicType<T>& a, S b);
}