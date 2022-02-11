#include "CodeAnimation.h"
#include "AlgorithmicOperators.h"
#include <iostream>
using namespace sf;
using namespace std;
CodeAnimation* CodeAnimation::instance = nullptr;

CodeAnimation::CodeAnimation() : thread(&CodeAnimation::MainCycle, this), msgs(), mutex(), animating(false)
{
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
					cout << "CodeAnimation::ERROR message type recieved" << endl;
					break;
				case MsgType::QUIT:
					win->close();
					break;
				case MsgType::CREATE_ARR:
					cout << "Creating array \"" << m.create_arr.name << "\" of " << nameof(m.create_arr.dataType) <<
					", size = " << m.create_arr.size;
					if (m.create_arr.isSet)
					{
						cout << ", with value ";
						switch (m.create_arr.dataType)
						{
						case DataType::INT: cout << m.create_arr.value._int; break;
						case DataType::FLOAT: cout << m.create_arr.value._float; break;
						case DataType::DOUBLE: cout << m.create_arr.value._double; break;
						case DataType::BOOL: cout << m.create_arr.value._bool; break;
						case DataType::CHAR: cout << m.create_arr.value._char; break;
						default: cout << "undefined"; break;
						}
					}
					cout << "." << endl;
					break;

				case MsgType::CREATE_VAR:
					cout << "Creating variable \"" << m.create_var.name << "\" of " << nameof(m.create_arr.dataType);
					if (m.create_var.isSet)
					{
						cout << ", with value ";
						switch (m.create_var.dataType)
						{
						case DataType::INT: cout << m.create_var.value._int; break;
						case DataType::FLOAT: cout << m.create_var.value._float; break;
						case DataType::DOUBLE: cout << m.create_var.value._double; break;
						case DataType::BOOL: cout << m.create_var.value._bool; break;
						case DataType::CHAR: cout << m.create_var.value._char; break;
						default: cout << "undefined"; break;
						}
					}
					cout << "." << endl;
					break;

				case MsgType::SET_VAR_VAR:
					cout << "Set variable \"" << m.set_var_var.name << "\" value of variable \"" << m.set_var_var.var_name
						<< "\"." << endl;
					break;

				case MsgType::OPER_IF:
					cout << "Operator if is checking expression. Expression result is ";
					if (m.oper_if.result)
						cout << "TRUE";
					else
						cout << "FALSE";
					cout << "." << endl;
					break;

				case MsgType::OPER_COMPARE:
					cout << "Checking equality of ";
					if (m.oper_compare.is1var)
						cout << "variable \"" << m.oper_compare.name1 << "\"";
					cout << " and ";
					if (m.oper_compare.is2var)
						cout << "variable \"" << m.oper_compare.name2 << "\"." << endl;
					cout << "Result is ";
					if (m.oper_compare.result)
						cout << "EQUAL." << endl;
					else
						cout << "DIFFERENT VALUES." << endl;
					break;

				case MsgType::OPER_WHILE_START:
					cout << "Started cycle while." << endl;
					break;

				case MsgType::OPER_WHILE_CHECK:
					cout << "Operator while is checking expression. Expression result is ";
					if (m.oper_while.result)
						cout << "TRUE. Cycle continues." << endl;
					else
						cout << "FALSE. Cycle broke." << endl;
					break;

				default:
					cout << "Got bad message, typed: " << (int)m.type << endl;
					break;
				}
				animating = false;
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