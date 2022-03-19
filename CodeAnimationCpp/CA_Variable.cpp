#include "CA_Variable.h"

namespace ca {

	CA_Variable::CA_Variable(string n, Value v, Vector2f pos) :
		type(v.type), name(n)
	{
		float quarter = VariableSize.y / 4;
		char str[30];
		string val = "";
		string digits = "%.";

		string type_name;
		Color back_color, font_color;

		switch (type)
		{
		case DataType::INT:
			type_name = "i";
			back_color = CA_Color::IntBack;
			font_color = CA_Color::IntFont;
			if (!v.isGarbage)
			{
				sprintf_s(str, "%i", v.uv._int);
				val = str;
			}
			break;

		case DataType::FLOAT:
			type_name = "f";
			back_color = CA_Color::FloatBack;
			font_color = CA_Color::FloatFont;
			if (!v.isGarbage)
			{
				digits += DigitsAfterPoint;
				digits += "f";
				sprintf_s(str, digits.c_str(), v.uv._float);
				val = str;
			}
			break;

		case DataType::DOUBLE:
			type_name = "d";
			back_color = CA_Color::DoubleBack;
			font_color = CA_Color::DoubleFont;
			if (!v.isGarbage)
			{
				digits += DigitsAfterPoint;
				digits += "lf";
				sprintf_s(str, digits.c_str(), v.uv._double);
				val = str;
			}
			break;

		case DataType::BOOL:
			type_name = "b";
			back_color = CA_Color::BoolBack;
			font_color = CA_Color::BoolFont;
			if (!v.isGarbage)
			{
				if (v.uv._bool)
					val = "True";
				else
					val = "False";
			}
			break;

		case DataType::CHAR:
			type_name = "c";
			back_color = CA_Color::CharBack;
			font_color = CA_Color::CharFont;
			if (!v.isGarbage)
			{
				val += "'";
				val += v.uv._char;
				val += "'";
			}
			break;
		}

		block_type = new CA_TextBlock({ quarter, quarter }, back_color,
			1, CA_Color::OutlineUsual, OutlineThicknessHighlighted, CA_Color::OutlineHighlighted,
			type_name, FontSizeName, font_color);
		block_name = new CA_TextBlock({ (float)VariableSize.x - quarter, quarter }, back_color,
			1, CA_Color::OutlineUsual, OutlineThicknessHighlighted, CA_Color::OutlineHighlighted,
			name, FontSizeName, font_color);
		block_value = new CA_TextBlock({ (float)VariableSize.x, 3 * quarter }, back_color,
			1, CA_Color::OutlineUsual, OutlineThicknessHighlighted, CA_Color::OutlineHighlighted,
			val, FontSizeValue, font_color);

		SetPosition(pos);
	}

	CA_Variable::~CA_Variable()
	{
		delete block_type;
		delete block_name;
		delete block_value;
	}

	void CA_Variable::Draw(RenderWindow& win)
	{
		block_type->Draw(win);
		block_name->Draw(win);
		block_value->Draw(win);
	}

	void CA_Variable::Highlight(bool on)
	{
		highlighted = on;
	}

	void CA_Variable::SetPosition(Vector2f pos)
	{
		float a = VariableSize.y / 4;
		float w = VariableSize.x;
		block_type->SetPos({ pos.x - w / 2 + a / 2, pos.y - 1.5f*a});
		block_name->SetPos({ pos.x + a / 2, pos.y - 1.5f * a });
		block_value->SetPos({ pos.x, pos.y + 0.5f * a });
	}
	void CA_Variable::ChangeValue(Value v)
	{
		string val = "";
		string digits = "%.";
		char str[30];

		if (!v.isGarbage)
		{
			switch (type)
			{
			case DataType::INT:
				sprintf_s(str, "%i", v.uv._int);
				val = str;
				break;

			case DataType::FLOAT:
				digits += DigitsAfterPoint;
				digits += "f";
				sprintf_s(str, digits.c_str(), v.uv._float);
				val = str;
				break;

			case DataType::DOUBLE:
				digits += DigitsAfterPoint;
				digits += "lf";
				sprintf_s(str, digits.c_str(), v.uv._double);
				val = str;
				break;

			case DataType::BOOL:
				if (v.uv._bool)
					val = "True";
				else
					val = "False";
				break;

			case DataType::CHAR:
				val += "'";
				val += v.uv._char;
				val += "'";
				break;
			}
		}
		block_value->ChangeText(val);
	}
}