#pragma once
#include "List.h"

template <class Record>
class List_Sortable :public List<Record> {
public:   //  Add prototypes for sorting methods here.
	void insertion_sort();
	void print();
	void selection_sort();
	void quick_sort();

private: //  Add prototypes for auxiliary functions here.
	int max_key(int low, int high);
	void swap(int low, int high);
	void recursive_quick_sort(int low, int high);
	int partition(int low, int high);
};

template <class Record>
class List_Sortable_node :public List_node<Record> {
public:   //  Add prototypes for sorting methods here.
	void insertion_sort_node();

private: //  Add prototypes for auxiliary functions here.
};


template <class Record>
void List_Sortable<Record>::insertion_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
	  the keys in all the  entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the contiguous List implementation of
	  Chapter 6
*/
{
	int first_unsorted;    //  position of first unsorted entry
	int position;          //  searches sorted part of list
	Record current;        //  holds the entry temporarily removed from list

	for (first_unsorted = 1; first_unsorted < this->count; first_unsorted++)
		if (this->entry[first_unsorted] < this->entry[first_unsorted - 1]) {
			position = first_unsorted;
			current = this->entry[first_unsorted];         //  Pull unsorted entry out of the list.
			do {               //  Shift all entries until the proper position is found.
				this->entry[position] = this->entry[position - 1];
				position--;                           //  position is empty.
			} while (position > 0 && this->entry[position - 1] > current);
			this->entry[position] = current;
		}
}

template <class Record>
void List_Sortable<Record>::print()
{
	for (int i = 0; i < this->count; i++)
		cout << this->entry[i] << " ";
	cout << endl;
}

template <class Record>
void List_Sortable<Record>::selection_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
	  the keys in all the entries are sorted into nondecreasing order.
Uses: max_key, swap.
*/
{
	for (int position = this->count - 1; position > 0; position--) {
		int max = max_key(0, position);
		swap(max, position);
	}
}


template <class Record>
int List_Sortable<Record>::max_key(int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list and low <= high.
Post: The position of the entry between low and high with the largest
	  key is returned.
Uses: The class Record, the contiguous List implementation of Chapter 6.
*/
{
	int largest, current;
	largest = low;
	for (current = low + 1; current <= high; current++)
		if (this->entry[largest] < this->entry[current])
			largest = current;
	return largest;
}


template <class Record>
void List_Sortable<Record>::swap(int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list.
Post: The entry at position low is swapped with the entry at position high.
Uses: The contiguous List implementation of Chapter 6.
*/
{
	Record temp;
	temp = this->entry[low];
	this->entry[low] = this->entry[high];
	this->entry[high] = temp;
}


template <class Record>
void List_Sortable<Record>::quick_sort()
/*
Post: The entries of the Sortable_list have been rearranged so
	  that their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6, recursive_quick_sort.
*/
{
	recursive_quick_sort(0, this->count - 1);
}


template <class Record>
void List_Sortable<Record>::recursive_quick_sort(int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list.
Post: The entries of the Sortable_list have been
	  rearranged so that their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6,
	  recursive_quick_sort, and partition.
*/
{
	int pivot_position;
	if (low < high) {   //   Otherwise, no sorting is needed.
		pivot_position = partition(low, high);
		recursive_quick_sort(low, pivot_position - 1);
		recursive_quick_sort(pivot_position + 1, high);
	}
}


template <class Record>
int List_Sortable<Record>::partition(int low, int high)
/*
Pre:  low and high are valid positions of the Sortable_list, with low <= high.
Post: The center (or left center) entry in the range between indices
	  low and high of the Sortable_list
	  has been chosen as a pivot.  All entries of the Sortable_list
	  between indices low and high, inclusive, have been
	  rearranged so that those with keys less than the pivot come
	  before the pivot and the remaining entries come
	  after the pivot.  The final position of the pivot is returned.
Uses: swap(int i, int j) (interchanges entries in positions
	  i and j of a Sortable_list), the contiguous List implementation
	  of Chapter 6, and methods for the class Record.
*/
{
	Record pivot;
	int i,            //  used to scan through the list
		last_small;   //  position of the last key less than pivot
	swap(low, (low + high) / 2);
	pivot = this->entry[low];   //  First entry is now pivot.
	last_small = low;
	for (i = low + 1; i <= high; i++)
		/*
		At the beginning of each iteration of this loop, we have the following
		conditions:
				If low < j <= last_small then entry[j].key < pivot.
				If last_small < j < i then entry[j].key >= pivot.
		*/
		if (this->entry[i] < pivot) {
			last_small = last_small + 1;
			swap(last_small, i);  //  Move large entry to right and small to left.
		}
	swap(low, last_small);      //  Put the pivot into its proper position.
	return last_small;
}

template <class Record>
void List_Sortable_node<Record>::insertion_sort_node()
/*
Post: The entries of the Sortable_list have been rearranged so that
	  the keys in all the entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the linked List implementation of Chapter 6.
*/
{
	Node<Record>  *first_unsorted,  //  the first unsorted node to be inserted
		*last_sorted,     //  tail of the sorted sublist
		*current,         //  used to traverse the sorted sublist
		*trailing;        //  one position behind current

	if (this->head != NULL) {          //  Otherwise, the empty list is already sorted.
		last_sorted = this->head;       //  The first node alone makes a sorted sublist.
		while (last_sorted->next != NULL) {
			first_unsorted = last_sorted->next;
			if (first_unsorted->entry < (this->head)->entry) {
				//  Insert *first_unsorted at the head of the sorted list:
				last_sorted->next = first_unsorted->next;
				first_unsorted->next = this->head;
				this->head = first_unsorted;
			}
			else {
				//  Search the sorted sublist to insert *first_unsorted:
				trailing = this->head;
				current = trailing->next;
				while (first_unsorted->entry > current->entry) {
					trailing = current;
					current = trailing->next;
				}

				//  *first_unsorted now belongs between *trailing and *current.

				if (first_unsorted == current)
					last_sorted = first_unsorted;  //  already in right position
				else {
					last_sorted->next = first_unsorted->next;
					first_unsorted->next = current;
					trailing->next = first_unsorted;
				}
			}
		}
	}
}
