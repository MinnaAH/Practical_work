#pragma once
#include "Stack.h"

class PostFix
{
public:
	void instructions();
	char get_operation();
	bool do_operation(char operation);
};

