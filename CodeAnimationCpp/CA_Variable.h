#pragma once
#include <string>
#include "CA_TextBlock.h"
#include "MSG.h"

using namespace std;
using namespace sf;

namespace ca {

	class CA_Variable
	{
		DataType type;
		string name, value;
		CA_TextBlock *block_type, *block_name, *block_value;

		bool highlighted;

	public:
		CA_Variable(string n, Value v, Vector2f pos);
		~CA_Variable();

		void Draw(RenderWindow& win);
		void Highlight(bool on = true);
		void SetPosition(Vector2f pos);
		void ChangeValue(Value v);
	};

}