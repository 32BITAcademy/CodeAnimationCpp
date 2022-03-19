#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "CA_TextBlock.h"

namespace ca {
	class CodeAnimator
	{
		std::map<std::string, CA_TextBlock*> blocks;

	public:
		CodeAnimator();
		~CodeAnimator();

		void Update(sf::Time dt);
		void Draw(sf::RenderWindow& win);
	};
}