#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "CA_Variable.h"

namespace ca {
	class CodeAnimator
	{
		int win_height, win_width;
		int vars_in_hor;
		int vars_in_ver;
		int vars_count;
		std::map<std::string, CA_Variable*> vars;


		//std::map<std::string, CA_TextBlock*> blocks;

	public:
		CodeAnimator();
		~CodeAnimator();

		void SetWinSize(int w, int h);
		void Send(MSG& m);
		void Update(sf::Time dt);
		void Draw(sf::RenderWindow& win);
	};
}