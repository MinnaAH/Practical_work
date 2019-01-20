#pragma once
#include "Utility.h"
#include "Node.h"

const int max_list = 10000;

template <class List_entry>
class List {
public:
	//  methods of the List ADT
	List();
	int size() const;
	bool full() const;
	inline void clear() { count = 0; }
	void traverse(void(*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code insert(int position, const List_entry &x);

protected:
	//  data members for a contiguous list implementation
	int count;
	List_entry entry[max_list];
};

template <class List_entry>
class List_node {
public:
	List_node();
	void clear();
	//Error_code replace(int position, const List_entry &x);
	//Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);

	//  Specifications for the methods of the list ADT go here.
	//  The following methods replace compiler-generated defaults.
	~List_node();
protected:
	int count;
	mutable int current_position;
	Node<List_entry> *head;
	mutable Node<List_entry> *current;

	//  The following auxiliary function is used to locate list positions
	Node<List_entry> *set_position(int position) const;
};

template <class List_entry>
int List<List_entry>::size() const
/*
Post: The function returns the number of entries in the List.
*/
{
	return count;
}


template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
	  where n is the number of entries in the List, the function succeeds:
	  Any entry formerly at position and all later entries have their
	  position numbers increased by 1 and x is inserted at position of the List.
	  Else: The function fails with a diagnostic error code.
*/
{
	if (full())
		return overflow;

	if (position < 0 || position > count)
		return utility_range_error;

	for (int i = count - 1; i >= position; i--)
		entry[i + 1] = entry[i];

	entry[position] = x;
	count++;
	return success;
}


template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &))
/*
Post: The action specified by function (*visit) has been performed on every
	  entry of the List, beginning at position 0 and doing each in turn.
*/
{
	for (int i = 0; i < count; i++)
		(*visit)(entry[i]);
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
	if (position < 0 || position > count - 1)
		return utility_range_error;

	x = entry[position];

	return success;
}

template <class List_entry>
List<List_entry>::List()
{
	count = 0;
}

template <class List_entry>
bool List<List_entry>::full() const
{
	return this->count == max_list;
}

template <class List_entry>
Error_code List_node<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
	  where n is the number of entries in the List, the function succeeds:
	  Any entry formerly at position and all later entries have their position
	  numbers increased by 1, and x is inserted at position of the List.
	  Else: The function fails with a diagnostic error code.
*/
{
	if (position < 0 || position > count)
		return utility_range_error;
	Node<List_entry> *new_node, *previous, *following;
	if (position > 0) {
		previous = set_position(position - 1);
		following = previous->next;
	}
	else following = head;
	new_node = new Node<List_entry>(x, following);
	if (new_node == NULL)
		return overflow;
	if (position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count++;
	return success;
}


template <class List_entry>
Node<List_entry> *List_node<List_entry>::set_position(int position) const
/*
Pre:  position is a valid position in the List; 0 <= position < count.
Post: Returns a pointer to the Node in position.
*/
{
	Node<List_entry> *q = head;
	for (int i = 0; i < position; i++) q = q->next;
	return q;
}

template <class List_entry>
void List_node<List_entry>::clear()
{
	;
}

template <class List_entry>
List_node<List_entry>::~List_node()
{
	;
}

template <class List_entry>
List_node<List_entry>::List_node()
{
	this->count = 0;
	this->current_position = -1;
	this->head = NULL;
	this->current = NULL;
}
