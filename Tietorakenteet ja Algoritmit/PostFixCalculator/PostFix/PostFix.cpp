#include "PostFix.h"
#include <iostream>

using namespace std;

Stack Number;

void PostFix::instructions()
/*
Pre: None
Post: Prints instructions 
*/
{
	cout << "Use the following oprations to use the calculator" << endl;
	cout << "Operation push to stack:                      ?"   << endl;
	cout << "Operation print top of the stack:             =" << endl;
	cout << "Oprations to do matemathical operations:      +  -  *  /" << endl;
	cout << "Operation to switxc two latest entries:       x" << endl;
	cout << "Operation to sum all entries:                 s" << endl;
	cout << "Operation to calculate average of all enries: a" << endl;
	cout << "Operation to shut down:                       q" << endl;

}

char PostFix::get_operation()
/*
Pre: None
Post: Gets users choise of operation and send it to do_operation.
Waits until operation on is valid.
*/
{
	bool wait = true;
	char operation;
	cout << "Select operation: ";

	while (wait == true) {
		cin >> operation;
		operation = tolower(operation);

		if (operation == '?' || operation == '=' || operation == '+' ||
			operation == '-' || operation == '*' || operation == '/' ||
			operation == 'q' || operation == 'x' || operation == 's' ||
			operation == 'a')
			wait = false;

		else {
			instructions();
			cout << "Select operation: ";
		}
	}
	return operation;
}

bool PostFix::do_operation(char operation)
/*
Pre: Parameter specifies operation
Post: Operation specifies what user wants to do with the calculator.
Calculator will run until user choose operation q and turns off the calculator
*/

{
	double a, b, sum, avg;
	int counter;

	switch (operation) {
	case '?':
		cout << "Enter a number: ";
		cin >> a;
		Number.push(a);
		break;

	case '=':
		if (!Number.empty()) {
			Number.top(a);
			cout << a << endl;
		}
		else
			cout << "Stack is empty" << endl;
		break;

	case '+':
		if (Number.empty())
			cout << "Stack is empty" << endl;
		else {
			Number.top(a);
			Number.pop();
			if (Number.empty()) {
				cout << "Only one entry" << endl;
				break;
			}
			Number.top(b);
			Number.pop();
			Number.push(a + b);
		}
		break;
	case '-':
		if (Number.empty())
			cout << "Stack is empty" << endl;
		else {
			Number.top(a);
			Number.pop();
			if (Number.empty()) {
				cout << "Only one entry" << endl;
				break;
			}
			Number.top(b);
			Number.pop();
			Number.push(b - a);
		}
		break;
	case '*':
		if (Number.empty())
			cout << "Stack is empty" << endl;
		else {
			Number.top(a);
			Number.pop();
			if (Number.empty()) {
				cout << "Only one entry" << endl;
				break;
			}
			Number.top(b);
			Number.pop();
			Number.push(a * b);
		}
		break;
	case '/':
		if (Number.empty())
			cout << "Stack is empty" << endl;
		else {
			Number.top(a);
			Number.pop();
			if (Number.empty()) {
				cout << "Only one entry" << endl;
				break;
			}
			Number.top(b);
			Number.pop();
			Number.push(b / a);
		}
		break;
	case 'x':
		if (Number.empty())
			cout << "Stack is empty" << endl;
		else {
			Number.top(a);
			Number.pop();
			if (Number.empty()) {
				cout << "Only one entry" << endl;
				break;
			}
			Number.top(b);
			Number.pop();
			Number.push(a);
			Number.push(b);
		}
		break;
	case 's':
		sum = 0;
		while (!Number.empty()) {
			Number.top(a);
			sum = sum + a;
			Number.pop();
		}
		Number.push(sum);
		break;
	case 'a':
		sum = 0;
		counter = 0;
		avg = 0;
		while (!Number.empty()) {
			Number.top(a);
			sum = sum + a;
			Number.pop();
			counter++;
		}
		avg = sum / counter;
		Number.push(avg);
		break;
	case 'q':
		cout << "Turning off the calculator";
		return false;
	}
	return true;
}