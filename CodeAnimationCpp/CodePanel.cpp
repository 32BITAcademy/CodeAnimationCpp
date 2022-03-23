#include "CodePanel.h"
#include <iostream>

namespace ca {

	CodePanel::CodePanel(int win_width) : label_str("Code"), code_str("Initializing")
	{
		label = new CA_TextBlock({ CodeLabelWidth, CodePanelHeight }, CA_Color::CodePanelBack,
			1, sf::Color::Black, 1, sf::Color::Black,
			label_str, CodePanelFontSize, CA_Color::CodePanelFont);
		code = new CA_TextBlock({ win_width - CodeLabelWidth, CodePanelHeight }, CA_Color::CodePanelBack,
			1, sf::Color::Black, 1, sf::Color::Black,
			code_str, CodePanelFontSize, CA_Color::CodePanelFont);

		label->SetPos({ CodeLabelWidth / 2, CodePanelHeight / 2 });
		code->SetPos({ win_width/2 + CodeLabelWidth / 2, CodePanelHeight / 2 });

		std::cout << win_width / 2 + CodeLabelWidth / 2 << " " << CodePanelHeight / 2 << endl;
	}

	CodePanel::~CodePanel()
	{
		delete label;
		delete code;
	}

	void CodePanel::SetCode(string s)
	{
		code->ChangeText(s);
	}

	void CodePanel::SetLabel(string s)
	{
		label->ChangeText(s);
	}

	void CodePanel::Draw(sf::RenderWindow& win)
	{
		label->Draw(win);
		code->Draw(win);
	}

}