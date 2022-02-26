//#pragma once
//#include "BasicTypes.h"
//
//namespace ca {
//
//	class TempType
//	{
//	public:
//		Value value;
//
//		TempType(Value v);
//		TempType(const TempType& b);
//
//		const TempType operator+(TempType& b);
//		const TempType operator-(TempType& b);
//		const TempType operator*(TempType& b);
//		const TempType operator/(TempType& b);
//		const TempType operator%(TempType& b);
//
//		template <typename T>
//		const TempType operator+(T b);
//
//		template <typename T>
//		const TempType operator-(T b);
//
//		template <typename T>
//		const TempType operator*(T b);
//
//		template <typename T>
//		const TempType operator/(T b);
//
//		template <typename T>
//		const TempType operator%(T b);
//
//		template <typename T>
//		const TempType operator+(BasicType<T>& b);
//
//		template <typename T>
//		const TempType operator-(BasicType<T>& b);
//
//		template <typename T>
//		const TempType operator*(BasicType<T>& b);
//
//		template <typename T>
//		const TempType operator/(BasicType<T>& b);
//
//		template <typename T>
//		const TempType operator%(BasicType<T>& b);
//	};
//
//	template <typename T>
//	const TempType operator+(T a, TempType& b);
//
//	template <typename T>
//	const TempType operator-(T a, TempType& b);
//
//	template <typename T>
//	const TempType operator*(T a, TempType& b);
//
//	template <typename T>
//	const TempType operator/(T a, TempType& b);
//
//	template <typename T>
//	const TempType operator%(T a, TempType& b);
//
//	template <typename T>
//	const TempType operator+(BasicType<T>& a, TempType& b);
//
//	template <typename T>
//	const TempType operator-(BasicType<T>& a, TempType& b);
//
//	template <typename T>
//	const TempType operator*(BasicType<T>& a, TempType& b);
//
//	template <typename T>
//	const TempType operator/(BasicType<T>& a, TempType& b);
//
//	template <typename T>
//	const TempType operator%(BasicType<T>& a, TempType& b);