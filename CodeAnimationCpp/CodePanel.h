#pragma once
#include "CA_TextBlock.h"

using namespace std;

namespace ca {

	class CodePanel
	{
		string label_str;
		string code_str;
		CA_TextBlock* code;
		CA_TextBlock* label;

	public:
		CodePanel(int win_width);
		~CodePanel();

		void SetCode(string s);
		void SetLabel(string s);
		void Draw(sf::RenderWindow& win);
	};


}