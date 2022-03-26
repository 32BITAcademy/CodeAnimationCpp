#pragma once
#include "CA_TextBlock.h"

using namespace std;

namespace ca {

	class CA_CodePanel
	{
		string label_str;
		string code_str;
		CA_TextBlock* code;
		CA_TextBlock* label;

	public:
		CA_CodePanel(int win_width);
		~CA_CodePanel();

		void SetCode(string s);
		void SetLabel(string s);
		void Draw(sf::RenderWindow& win);
	};


}