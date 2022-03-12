#include "DataTypes.h"

using namespace std;

namespace ca {
	char DataTypeNames[6][10] = { "undefined", "int", "float", "double", "bool", "char" };

	DataType GetType(int a) { return DataType::INT; }
	DataType GetType(float a) { return DataType::FLOAT; }
	DataType GetType(double a) { return DataType::DOUBLE; }
	DataType GetType(bool a) { return DataType::BOOL; }
	DataType GetType(char a) { return DataType::CHAR; }

	string DataTypeToString(DataType& t)
	{
		int x = static_cast<int>(t);
		if (x > 5 || x < 0) { x = 0; t = DataType::UNDEFINED; }
		return string(ca::DataTypeNames[x]);
	}

	string UniValue::ToString(DataType t)
	{
		string s = "";
		switch (t)
		{
		case DataType::INT: s = to_string(_int); break;
		case DataType::FLOAT: s = to_string(_float); break;
		case DataType::DOUBLE: s = to_string(_double); break;
		case DataType::BOOL: s = _bool ? "TRUE" : "FALSE"; break;
		case DataType::CHAR: s = s + "\'" + _char + "\'"; break;
		default: s = "UNDEFINED"; break;
		}
		return s;
	}

	void UniValue::SetValue(int v) { _int = v; }
	void UniValue::SetValue(float v) { _float = v; }
	void UniValue::SetValue(double v) { _double = v; }
	void UniValue::SetValue(bool v) { _bool = v; }
	void UniValue::SetValue(char v) { _char = v; }

	int UniValue::GetValue(int v) {	return _int; }
	float UniValue::GetValue(float v) {	return _float; }
	double UniValue::GetValue(double v) {	return _double; }
	bool UniValue::GetValue(bool v) {	return _bool; }
	char UniValue::GetValue(char v) {	return _char; }
}