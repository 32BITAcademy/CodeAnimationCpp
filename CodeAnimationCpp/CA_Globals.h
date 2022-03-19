#pragma once
#include <SFML/Graphics.hpp>

namespace ca {

	extern sf::Vector2i VariableSize;
	extern int VariableGap;

	extern sf::Font MainFont;

	extern float FontSizeName;
	extern float FontSizeValue;
	
	extern float OutlineThicknessHighlighted;

	extern int DigitsAfterPoint;
	
	class CA_Color
	{
	public:
		static sf::Color IntFont;
		static sf::Color FloatFont;
		static sf::Color DoubleFont;
		static sf::Color BoolFont;
		static sf::Color CharFont;

		static sf::Color IntBack;
		static sf::Color FloatBack;
		static sf::Color DoubleBack;
		static sf::Color BoolBack;
		static sf::Color CharBack;

		static sf::Color OutlineUsual;
		static sf::Color OutlineHighlighted;

	};

}