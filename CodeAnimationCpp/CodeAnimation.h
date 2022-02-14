#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <list>
#include "MSG.h"

class CodeAnimation
{
private:
	static CodeAnimation* instance;
	
	bool debug_on;
	sf::Thread thread;
	int win_height, win_width;
	sf::RenderWindow* win;
	std::list<MSG> msgs;
	sf::Mutex mutex;
	bool animating;

	int code_depth = 0;
	
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
	static void DebugMode(bool on = true);
};