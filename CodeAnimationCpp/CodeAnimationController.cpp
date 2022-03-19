#include "CodeAnimationController.h"
#include "AlgorithmicOperators.h"
#include "MSG.h"
#include <iostream>
using namespace sf;
using namespace std;

namespace ca {

	CodeAnimationController* CodeAnimationController::instance = nullptr;

	CodeAnimationController::CodeAnimationController() : thread(&CodeAnimationController::MainCycle, this),
		msgs(), mutex(), animating(false),
		win_width(VideoMode::getDesktopMode().width / 2),
		win_height(VideoMode::getDesktopMode().height),
		animator(win_width, win_height),
		isRunning(true), debug_on(false), win(nullptr)
	{
	}

	CodeAnimationController* CodeAnimationController::GetInstance()
	{
		if (!instance) instance = new CodeAnimationController();
		return instance;
	}

	void CodeAnimationController::MainCycle()
	{
		win = new RenderWindow(VideoMode(win_width, win_height), "Code Animation");
		win->setPosition({ win_width , 0 });
		win->setActive();

		if (debug_on)
			cout << "[CA-DEBUG] Started MainCycle!" << endl;
		while (isRunning)
		{
			Event event;
			while (win->pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					win->close();
					exit(1);
				}
			}
			mutex.lock();
			{
				while (!msgs.empty())
				{
					MSG m = msgs.front();
					msgs.pop_front();
					switch (m.type)
					{
					case MsgType::ERROR:
						break;

					case MsgType::QUIT:
						win->close();
						break;

					default:
						break;
					}

					animator.Send(m);

					if (debug_on)
					{
						cout << "[CA-DEBUG] ";
						for (int i = 0; i < code_depth; i++)
							cout << "    ";
						if (m.type == MsgType::OPER_WHILE_CHECK || m.type == MsgType::OPER_FOR_CHECK)
							cout << "\b";

						cout << m.DebugString() << endl;

						if (m.type == MsgType::OPER_WHILE_START || m.type == MsgType::OPER_FOR_START)
						{
							code_depth++;
						}

						if (m.type == MsgType::OPER_WHILE_CHECK && !m.oper_while.result ||
							m.type == MsgType::OPER_FOR_CHECK && !m.oper_for.result)
						{
							code_depth--;
							cout << "[CA-DEBUG] ";
							for (int i = 0; i < code_depth; i++)
								cout << "    ";
							cout << "Cycle stopped" << endl;
						}
					}
				}
			}
			mutex.unlock();

			
			sleep(milliseconds(16));
			
			win->clear(Color::White);

			animator.Draw(*win);
			
			win->display();
		}
		animator.Quit();
		win->close();
		delete win;
	}

	CodeAnimationController::~CodeAnimationController()
	{
		animator.Quit();
		thread.terminate();
	}

	void CodeAnimationController::Init()
	{
		CodeAnimationController* ca = CodeAnimationController::GetInstance();
		if (ca->initialized) return;

		ca->thread.launch();
		ca->initialized = true;
	}

	void CodeAnimationController::Quit()
	{
		instance->isRunning = false;
		sleep(seconds(100));
		if (instance)
		{
			if (!instance->initialized) return;
			delete instance;
			instance = nullptr;
		}
	}

	void CodeAnimationController::DebugMode(bool on)
	{
		GetInstance()->debug_on = on;
	}

	void CodeAnimationController::Send(MSG& m)
	{
		mutex.lock();
		msgs.push_back(m);
		mutex.unlock();
		sleep(seconds(0.2));
	}

	bool CodeAnimationController::IsAnimating()
	{
		return animating;
	}

	void CodeAnimationController::WaitEndOfAnimation(int ms)
	{
		while (animating) { sleep(milliseconds(ms)); }
	}
}