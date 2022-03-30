#include "CA_CodePanel.h"
#include <iostream>

namespace ca {

	CA_CodePanel::CA_CodePanel(int win_width) : label_str("Code"), code_str("Initializing")
	{
		label = new CA_TextBlock({ CodeLabelWidth, CodePanelHeight }, CA_Color::CodePanelBack,
			1, sf::Color::White, 1, sf::Color::White,
			label_str, CodePanelFontSize, CA_Color::CodePanelFont);
		code = new CA_TextBlock({ win_width - CodeLabelWidth, CodePanelHeight }, CA_Color::CodePanelBack,
			1, sf::Color::White, 1, sf::Color::White,
			code_str, CodePanelFontSize, CA_Color::CodePanelFont);

		label->SetPos({ CodeLabelWidth / 2, CodePanelHeight / 2 });
		code->SetPos({ win_width/2 + CodeLabelWidth / 2, CodePanelHeight / 2 });

		std::cout << win_width / 2 + CodeLabelWidth / 2 << " " << CodePanelHeight / 2 << endl;
	}

	CA_CodePanel::~CA_CodePanel()
	{
		delete label;
		delete code;
	}

	void CA_CodePanel::SetCode(string s)
	{
		code->ChangeText(s);
	}

	void CA_CodePanel::SetLabel(string s)
	{
		label->ChangeText(s);
	}

	void CA_CodePanel::Draw(sf::RenderWindow& win)
	{
		label->Draw(win);
		code->Draw(win);
	}

}