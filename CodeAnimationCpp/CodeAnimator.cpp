#include "CodeAnimator.h"
#include "CA_Globals.h"

using namespace sf;
using namespace std;

namespace ca {

	sf::Font MainFont;

	CodeAnimator::CodeAnimator() : blocks()
	{
		srand(time(0));
		MainFont.loadFromFile("resources\\trebuc.ttf");
		CA_TextBlock* a;
		string s = "";
		for (int i = 1; i <= 20; i++)
		{
			char str[100];
			_itoa_s(rand() % 10, str, 100, 10);
			s += str;
			a = new CA_TextBlock({ 100, 50 }, Color::Cyan, 5, Color::Blue, 10, Color::Red,
				s, 30, Color::Black);
			a->SetPos({100, float(25 + 50*i)});
			blocks[s] = a;
		}

		a = new CA_TextBlock({ 100, 200 }, Color::Green, 5, Color::Blue, 10, Color::Red,
			"OK", 30, Color::Black);
		a->SetPos({ 500, 300 });
		blocks["OK"] = a;
	}

	CodeAnimator::~CodeAnimator()
	{
		
	}

	void CodeAnimator::Update(sf::Time dt)
	{
		;
	}

	void CodeAnimator::Draw(sf::RenderWindow& win)
	{
		for (auto x : blocks)
		{
			x.second->Draw(win);
		}
	}

}