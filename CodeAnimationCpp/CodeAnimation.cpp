#include "CodeAnimation.h"
#include "AlgorithmicOperators.h"
#include <iostream>
using namespace sf;
using namespace std;

CodeAnimation* CodeAnimation::instance = nullptr;

CodeAnimation::CodeAnimation() : thread(&CodeAnimation::MainCycle, this), msgs(), mutex(), animating(false)
{
	debug_on = false;
	win_width = VideoMode::getDesktopMode().width / 2;
	win_height = VideoMode::getDesktopMode().height / 2;
	//win = new RenderWindow(VideoMode(win_width, win_height), "Code Animation");
	//win->setPosition({ (int)VideoMode::getDesktopMode().width , 0 });
}

CodeAnimation* CodeAnimation::GetInstance()
{
	if (!instance) instance = new CodeAnimation();
	return instance;
}

void CodeAnimation::MainCycle()
{
	if (debug_on)
		cout << "Started MainCycle!" << endl;
	while (true)
	{
		//sf::Event event;
		//while (win->pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		win->close();
		//}
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

				case MsgType::SET_VAR_VALUE:
					break;

				case MsgType::SET_VAR_VAR:
					break;

				case MsgType::OPER_IF:
					break;

				case MsgType::OPER_WHILE_START:
					break;

				case MsgType::OPER_WHILE_CHECK:
					break;

				case MsgType::OPER_CHANGE_BY_VALUE:
					break;

				case MsgType::OPER_CHANGE_BY_VAR:
					break;

				case MsgType::OPER_COMPARE:
					break;

				default:
					break;
				}
				animating = false;

				if (debug_on)
				{
					if (m.type == MsgType::OPER_WHILE_CHECK)
						for (int i = 0; i < code_depth*4 - 1; i++)
							cout << " ";
					else
						for (int i = 0; i < code_depth*4; i++)
							cout << " ";
					
					cout << m.DebugString() << endl;

					if (m.type == MsgType::OPER_WHILE_START)
					{
						code_depth++;
					}

					if (m.type == MsgType::OPER_WHILE_CHECK && !m.oper_while.result)
					{
						code_depth--;
						for (int i = 0; i < code_depth; i++)
							cout << "    ";
						cout << "Cycle While stopped" << endl;
					}
				}
			}
		}
		mutex.unlock();

		sleep(milliseconds(16));
		//win->clear();
		//win->display();
	}
	delete win;
}

CodeAnimation::~CodeAnimation()
{
	thread.terminate();
	delete win;
}

void CodeAnimation::Init()
{
	CodeAnimation* ca = CodeAnimation::GetInstance();
	ca->thread.launch();
}

void CodeAnimation::Quit()
{
	if (!CodeAnimation::instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void CodeAnimation::DebugMode(bool on)
{
	GetInstance()->debug_on = on;
}

void CodeAnimation::Send(MSG& m)
{
	animating = true;
	mutex.lock();
	msgs.push_back(m);
	mutex.unlock();
}

bool CodeAnimation::IsAnimating()
{
	return animating;
}

void CodeAnimation::WaitEndOfAnimation(int ms)
{
	while (animating) { sleep(milliseconds(ms)); }
}