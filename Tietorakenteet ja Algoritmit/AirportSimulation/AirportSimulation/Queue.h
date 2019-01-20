/*
Tietorakenteet ja algoritmit -  2. harjoitystyö
Minna Hannula
*/
#pragma once
#include "Utility.h"

enum Error_code {
	success, fail, utility_range_error, underflow, overflow, fatal,
	not_present, duplicate_error, entry_inserted, entry_found,
	internal_error
};

class Queue {
public:
	Queue();
	bool empty() const;
	Error_code serve();
	Error_code append(const Queue_entry &item);
	Error_code retrieve(Queue_entry &item) const;

protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};

class Extended_queue : public Queue {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);
};