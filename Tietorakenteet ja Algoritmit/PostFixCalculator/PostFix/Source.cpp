#include "Stack.h"
#include "PostFix.h"

int main()
/*
Pre: None
Post: Calculator runs.
*/
{
	PostFix calc;
	calc.instructions();
	while (calc.do_operation(calc.get_operation()));
}