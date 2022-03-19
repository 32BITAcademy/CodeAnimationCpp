#include "CA_TextBlock.h"
#include "CA_Globals.h"

#define TEXT_MARGIN_X 4
#define TEXT_MARGIN_Y 2

using namespace std;
using namespace sf;

namespace ca {

	CA_TextBlock::CA_TextBlock(Vector2f size, Color back_color,
		float u_outline, Color u_out_color, float h_outline, Color h_out_color,
		string str, unsigned int font_size, Color text_color) :
		shape(size), text(str, MainFont, font_size), highlighted(false),
		usual_outline(u_outline), usual_outcolor(u_out_color), high_outline(h_outline), high_outcolor(h_out_color)
	{
		shape.setFillColor(back_color);
		shape.setOutlineThickness(usual_outline);
		shape.setOutlineColor(usual_outcolor);
		shape.setOrigin(size.x / 2, size.y / 2);

		text.setFillColor(text_color);
		FloatRect r = text.getGlobalBounds();
		shape.setSize({ r.width, r.height });
		/*if (r.width >= size.x - TEXT_MARGIN_X)
		{
			float scale = (size.x - TEXT_MARGIN_X) / r.width;
			text.setCharacterSize(scale*font_size);
		}
		else if (r.height >= size.y - TEXT_MARGIN_Y)
		{
			float scale = (size.y - TEXT_MARGIN_Y) / r.height;
			text.setCharacterSize(scale * font_size);
		}*/
	}

	CA_TextBlock::~CA_TextBlock()
	{
	}

	void CA_TextBlock::Draw(RenderWindow& win)
	{
		win.draw(shape);
		win.draw(text);
	}

	void CA_TextBlock::Highlight(bool on)
	{
		if (on == highlighted) return;
		highlighted = on;
		if (highlighted)
		{
			shape.setOutlineThickness(high_outline);
			shape.setOutlineColor(high_outcolor);
		}
		else
		{
			shape.setOutlineThickness(usual_outline);
			shape.setOutlineColor(usual_outcolor);
		}
	}

	void CA_TextBlock::SetPos(Vector2f pos)
	{
		shape.setPosition(pos);
		FloatRect r = text.getGlobalBounds();
		r.left = pos.x - r.width / 2;
		r.top = pos.y - r.height / 2;
		text.setPosition(r.left, r.top);
	}
}