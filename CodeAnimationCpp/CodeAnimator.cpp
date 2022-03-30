#include "CodeAnimator.h"
#include "CA_Globals.h"

using namespace sf;
using namespace std;

namespace ca {

	CodeAnimator::CodeAnimator(int w, int h) : win_width(w), win_height(h), 
		vars_count(0), vars(), panel(w) //, blocks()
	{
		vars_in_ver = (win_height - VariableGap - CodePanelHeight) / ((int)VariableSize.y + VariableGap);
		vars_in_hor = (win_width  - VariableGap) / ((int)VariableSize.x + VariableGap);

		MainFont.loadFromFile("resources\\trebuc.ttf");
		/*CA_TextBlock* a;
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
		blocks["OK"] = a;*/
	}

	CodeAnimator::~CodeAnimator()
	{
		for (auto x : vars)
			delete x.second;
		vars.clear();
	}

	void CodeAnimator::Send(MSG& m)
	{
		Vector2f pos;

		switch (m.type)
		{
		case MsgType::CREATE_VAR:
			pos.x = VariableGap + (vars_count / vars_in_ver * (VariableSize.x + VariableGap)) + VariableSize.x / 2;
			pos.y = VariableGap + (vars_count % vars_in_ver * (VariableSize.y + VariableGap)) + VariableSize.y / 2 + CodePanelHeight;
			vars[m.create_var.var.name] = new CA_Variable(m.create_var.var.name, m.create_var.var.value, pos);
			vars_count++;
			break;

		case MsgType::SET_VAR:
			if (m.set_var.isByVar)
				vars[m.set_var.varWhat.name]->ChangeValue(m.set_var.result);
			else
				vars[m.set_var.varWhat.name]->ChangeValue(m.set_var.result);
			break;
		}
	}

	void CodeAnimator::Update(sf::Time dt)
	{
		;
	}

	void CodeAnimator::Draw(sf::RenderWindow& win)
	{
		panel.Draw(win);

		for (auto x : vars) //blocks)
		{
			x.second->Draw(win);
		}
	}

	void CodeAnimator::Quit()
	{
		for (auto x : vars)
			delete x.second;
		vars.clear();
	}

}