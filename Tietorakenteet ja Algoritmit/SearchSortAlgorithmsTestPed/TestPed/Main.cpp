/*Tietorakenteet ja Algoritmit, Harjoitustyö 3
Minna Hannula*/

#include"List.h"
#include "List_Sortable.h"
#include"Random.h"
#include"Key.h"
typedef int Record;

Error_code sequential_search(const List<Record> &the_list, const Key &target, int &position)
/*
Post: If the Recors in the the_list has a Key equal to target, then  position locates such entry and a code
of success is returned. Otherwise not_present is returned.
Uses: Methods of classes List and Record
*/
{
	int s = the_list.size();
	for (position = 0; position < s; position++) {
		Record data;
		the_list.retrieve(position, data);
		if (data == target)
			return success;
	}
	return not_present;
}

Error_code binary_search(const List<Record> &the_list, const Key &target, int position) 
/*
Post: If the Recors in the the_list has a Key equal to target, then  position locates such entry and a code
of success is returned. Otherwise not_present is returned.
Uses: Methods of classes List and Record
*/
{
	Record data;
	int bottom = 0;
	int top = the_list.size() - 1;

	while (bottom < top) {
		int mid = (bottom + top) / 2;
		the_list.retrieve(mid, data);

		if (data < target)
			bottom = mid + 1;
		else
			top = mid;
	}

	if (top < bottom)
		return not_present;
	else {
		position = bottom;
		the_list.retrieve(bottom, data);
		if (data == target)
			return success;
		else
			return not_present;
	}
}

void compareSearch(const List<Record> &list, int random) 
/*
Post: Binary and sequential serches.
Uses: Methods of classes List, Record and Key and methods binary_search and sequential_search
*/
{
	int position;
	Key key;
	cout << "---------------------------------------------------" << endl;
	cout << "Value of the target: " << random << endl;
	cout << "--- Sequential search ---" << endl;
	if (sequential_search(list, random, position) == success) {
		cout << "Key was found from the list." << endl;
		cout << "Position of the key: " << position << endl;
		cout << "Comparisons: " << key.comparisons << endl;
	}
	else {
		cout << "Key was not found from the list." << endl;
		cout << "Comparisons: " << key.comparisons << endl;
	}
	key.comparisons = 0;

	cout << endl << endl;
	cout << "--- Binary search ---" << endl;
	if (binary_search(list, random, position) == success) {
		cout << "Key was found from the list." << endl;
		cout << "Position of the key: " << position << endl;
		cout <<  "Comparisons: " << key.comparisons << endl;
	}
	else {
		cout << "Key was not found from the list." << endl;
		cout << "Comparisons: " << key.comparisons << endl;
	}
	key.comparisons = 0;
}

int main() 
/*
Post: User chooses sort or search algorithms. Program prints the result of algoritms
Uses: Methods of classes List, List_Sortable, Record, Random and methods serach
*/
{
	int choice, entries, searches, random, low, high, x,
		materiaSize, itemNumber;
	Key key;
	List<Record> list;
	List_Sortable<Record> list_sortable;
	Random number;
	//User menu
	cout << "Welcome to the test ped program. Choose either serching or sorting." << endl
		<< "[1] Sequential searc algorithm" << endl
		<< "[2] Compare serach algorithms" << endl
		<< "[3] Sort algorithms" << endl
		<< "Your choice: ";
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 1:
		int position;
		
		cout << "--- Seaquential search ---" << endl
			<< "Binary search from material" << endl;
		cout << "Insert the number of items: ";
		cin >> entries;

		//Create material, items 1,3,5... First position 0
		for (int i = 1; i <= entries; i++) {
			list.insert(i - 1, (2 * i - 1));
		}

		cout << "The Key value is drawn between two numbers." << endl;
		cout << "Insert range low value: ";
		cin >> low;
		cout << "Insert range high value: ";
		cin >> high;

		random = number.random_integer(low, high);

		cout << "--- Sequential search ---" << endl << endl;
		cout << "Value of the target: " << random << endl;
		if (sequential_search(list, random, position) == success) {
			cout << "Key was found from the list." << endl;
			cout << "Position of the key: " << position << endl;
			cout << "Comparisons: " << key.comparisons << endl;
		}
		else {
			cout << "Key was not found from the list." << endl;
			cout << "Comparisons: " << key.comparisons << endl;
		}
		key.comparisons = 0;

		break;
	case 2:
		cout << "--- Compare search algorithms ---" << endl
			<< "Compares sequential and binary search." << endl;
		cout << "Insert the number of items: ";
		cin >> entries;
		cout << "How many times search algoritms will run: ";
		cin >> searches;

		//Create material, items 1,3,5... First position 0
		for (int i = 1; i <= entries; i++) {
			list.insert(i - 1, (2 * i - 1));
		}

		cout << "The Key value is drawn between two numbers." << endl;
		cout << "Insert range low value: ";
		cin >> low;
		cout << "Insert range high value: ";
		cin >> high;

		//Search and get random integer
		for (int i = 0; i < searches; i++) {
			random = number.random_integer(low, high);
			compareSearch(list, random);
		}
		break;
	case 3:
		cout << "--- Sort algorithms ---" << endl
			<< "Sorts randomly created material from the smallest to the largest integer." << endl;
		cout << "Insert the size of sortable material: ";
		cin >> materiaSize;
		cout << endl;
		cout << "Material items are drawn from range." << endl
			<< "Lowest value of the range is 0." << endl
			<< "Highest value is ten times the size of the material." << endl;

		//Create material
		for (int i = 1; i <= materiaSize; i++) {
			list_sortable.insert(i - 1, number.random_integer(0, 10 * materiaSize));
		}

		cout << "Insert a number of items you would like to print from the list: ";
		cin >> itemNumber;
		cout << endl;

		//Material before sorting
		cout << "--- Material before being sorted ---" << endl;
		for (int j = 0; j < itemNumber; j++) {
			list_sortable.retrieve(j, x);
			cout << x << " ";
		}
		cout << endl;

		//Material after sorting
		cout << "--- Material after being sorted ---" << endl;
		list_sortable.insertion_sort();
		for (int j = 0; j < itemNumber; j++) {
			list_sortable.retrieve(j, x);
			cout << x << " ";
		}
		cout << endl;
		break;
	}

	system("pause");
}


