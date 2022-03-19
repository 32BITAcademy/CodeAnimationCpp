#include "CodeAnimationController.h"
#include "AlgorithmicOperators.h"
#include "MSG.h"
#include <iostream>
using namespace sf;
using namespace std;

namespace ca {

	CodeAnimationController* CodeAnimationController::instance = nullptr;

	CodeAnimationController::CodeAnimationController() : thread(&CodeAnimationController::MainCycle, this),
		msgs(), mutex(), animating(false), animator()
	{
		debug_on = false;
	}

	CodeAnimationController* CodeAnimationController::GetInstance()
	{
		if (!instance) instance = new CodeAnimationController();
		return instance;
	}

	void CodeAnimationController::MainCycle()
	{
		win_width = VideoMode::getDesktopMode().width / 2;
		win_height = VideoMode::getDesktopMode().height;
		win = new RenderWindow(VideoMode(win_width, win_height), "Code Animation");
		win->setPosition({ win_width , 0 });
		win->setActive();

		if (debug_on)
			cout << "Started MainCycle!" << endl;
		while (true)
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

					case MsgType::CREATE_ARR:
						break;

					case MsgType::CREATE_VAR:
						break;

					case MsgType::SET_VAR:
						break;

					case MsgType::OPER_IF:
						break;

					case MsgType::OPER_WHILE_START:
						break;

					case MsgType::OPER_WHILE_CHECK:
						break;

					case MsgType::OPER_CHANGE_BY:
						break;

					case MsgType::OPER_COMPARE:
						break;

					default:
						break;
					}

					if (debug_on)
					{
						if (m.type == MsgType::OPER_WHILE_CHECK || m.type == MsgType::OPER_FOR_CHECK)
							for (int i = 0; i < code_depth * 4 - 1; i++)
								cout << " ";
						else
							for (int i = 0; i < code_depth * 4; i++)
								cout << " ";

						cout << m.DebugString() << endl;

						if (m.type == MsgType::OPER_WHILE_START || m.type == MsgType::OPER_FOR_START)
						{
							code_depth++;
						}

						if (m.type == MsgType::OPER_WHILE_CHECK && !m.oper_while.result ||
							m.type == MsgType::OPER_FOR_CHECK && !m.oper_for.result)
						{
							code_depth--;
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
		delete win;
	}

	CodeAnimationController::~CodeAnimationController()
	{
		thread.terminate();
		delete win;
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