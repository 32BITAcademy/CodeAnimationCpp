#pragma once
#include <string>
#include "CA_TextBlock.h"

using namespace std;

namespace ca {

	class CA_Variable
	{
		string type, name, value;
		CA_TextBlock block_name, block_value;
	};

}