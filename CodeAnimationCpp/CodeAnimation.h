#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <list>
#include "MSG.h"

class CodeAnimation
{
private:
	static CodeAnimation* instance;
	
	sf::Thread thread;
	int win_height, win_width;
	sf::RenderWindow* win;
	std::list<MSG> msgs;
	sf::Mutex mutex;
	bool animating;
	
	CodeAnimation();
	void MainCycle();

public:
	void Send(MSG& m);
	bool IsAnimating();
	void WaitEndOfAnimation(int ms = 16);

	~CodeAnimation();
	static CodeAnimation* GetInstance();
	static void Init();
	static void Quit();
};