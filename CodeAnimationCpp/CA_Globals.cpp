#include "CA_Globals.h"

using namespace sf;

namespace ca {

	sf::Vector2i VariableSize = { 128, 96 };
	int VariableGap = 16;

	sf::Font MainFont;
	float FontSizeName = 20;
	float FontSizeValue = 46;

	float OutlineThicknessHighlighted = 5;
	int DigitsAfterPoint = 2;

	float CodePanelHeight = 100;
	float CodeLabelWidth = 250;
	float CodePanelFontSize = 50;

	sf::Color CA_Color::IntFont(0, 0, 128);
	sf::Color CA_Color::FloatFont(100, 80, 0);
	sf::Color CA_Color::DoubleFont(100, 0, 0);
	sf::Color CA_Color::BoolFont(0, 100, 0);
	sf::Color CA_Color::CharFont(128, 0, 80);

	sf::Color CA_Color::IntBack(128, 192, 255);
	sf::Color CA_Color::FloatBack(255, 224, 128);
	sf::Color CA_Color::DoubleBack(255, 160, 128);
	sf::Color CA_Color::BoolBack(192, 255, 192);
	sf::Color CA_Color::CharBack(255, 192, 255);

	sf::Color CA_Color::OutlineUsual(0, 0, 0);
	sf::Color CA_Color::OutlineHighlighted(255, 0, 0);

	sf::Color CA_Color::CodePanelFont(255, 255, 255);
	sf::Color CA_Color::CodePanelBack(0, 40, 40);
}