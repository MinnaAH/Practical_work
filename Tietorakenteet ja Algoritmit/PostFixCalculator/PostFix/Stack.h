#pragma once
#include "Utility.h" //Error_code

const int maxstack = 1000;  
class Stack {
public:
	typedef double Stack_entry;

	Stack();
	bool empty() const;
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Error_code push(const Stack_entry &item);

private:
	int count;
	Stack_entry entry[maxstack];
};