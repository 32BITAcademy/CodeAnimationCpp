#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "CA_Globals.h"

using namespace sf;

namespace ca {
	class CA_TextBlock
	{
		RectangleShape shape;
		Text text;
		bool highlighted;
		int base_font_size;

		float usual_outline, high_outline;
		Color usual_outcolor, high_outcolor;
	
	public:
		CA_TextBlock(Vector2f size, Color back_color,
			float u_outline, Color u_out_color, float h_outline, Color h_out_color,
			std::string str, unsigned int font_size, Color text_color);
		~CA_TextBlock();

		void Draw(RenderWindow& win);
		void Highlight(bool on = true);
		void SetPos(Vector2f pos);
		void ChangeText(std::string str);
	};
}