#pragma once
#include<string>

namespace ca {
	enum class DataType { UNDEFINED, INT, FLOAT, DOUBLE, BOOL, CHAR };

	DataType GetType(int a);
	DataType GetType(float a);
	DataType GetType(double a);
	DataType GetType(bool a);
	DataType GetType(char a);

	extern char DataTypeNames[6][10];
	std::string DataTypeToString(DataType& t);

	union UniValue {
		int _int;
		float _float;
		double _double;
		bool _bool;
		char _char;

		std::string ToString(DataType t);
		void SetValue(int v);
		void SetValue(float v);
		void SetValue(double v);
		void SetValue(char v);
		void SetValue(bool v);

		int GetValue(int v);
		float GetValue(float v);
		double GetValue(double v);
		char GetValue(char v);
		bool GetValue(bool v);
	};
}