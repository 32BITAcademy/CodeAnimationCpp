#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <list>
#include "CodeAnimator.h"

namespace ca {
	struct MSG;

	class CodeAnimationController
	{
	private:
		static CodeAnimationController* instance;

		bool initialized = false;
		bool debug_on;
		sf::Thread thread;
		int win_height, win_width;
		sf::RenderWindow* win;
		std::list<MSG> msgs;
		sf::Mutex mutex;
		bool animating;

		int code_depth = 0;

		CodeAnimator animator;

		CodeAnimationController();

		bool isRunning;
		void MainCycle();

	public:
		void Send(MSG& m);
		bool IsAnimating();
		void WaitEndOfAnimation(int ms = 16);

		~CodeAnimationController();
		static CodeAnimationController* GetInstance();
		static void Init();
		static void Quit();
		static void DebugMode(bool on = true);
	};
}