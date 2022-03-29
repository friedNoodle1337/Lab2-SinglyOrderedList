#include <iostream>
#include "SinglyOrderedList.h"

int main()
{
	SinglyOrderedList list1;

	std::cout << "========== Inserting items ==========\n\n";
	list1.insertItem(2);
	list1.outAll();
	list1.insertItem(5);
	list1.outAll();
	list1.insertItem(3);
	list1.outAll();
	list1.insertItem(4);
	list1.outAll();
	list1.insertItem(1);
	list1.outAll();
	std::cout << "Inserting 3...\n";
	list1.insertItem(3);

	std::cout << "\noutAll() was before and this is std::cout: " << list1 << "\n";

	std::cout << "========== Searching ==========\n";
	std::cout << "\nSearching 2...\n";
	if (list1.searchItem(2) == true)
	{
		std::cout << "Yes! " << list1 << "Searching 6...\n";
		if (list1.searchItem(6) == false)
		{
			std::cout << "No! " << list1 << "Search is working!\n";
		}
		else 
		{
			std::cout << "Yes!\nSearch is not working!\n";
		}
	}

	std::cout << "\n========== Deleting ==========\n";
	std::cout << "\nDeleting 2...\n";
	list1.deleteItem(2);
	list1.outAll();
	std::cout << "Deleting 5...\n";
	list1.deleteItem(5);
	list1.outAll();
	std::cout << "Deleting 1...\n";
	list1.deleteItem(1);
	list1.outAll();
	std::cout << "\n";

	std::cout << "========== Adding one list to another ==========\n\n";
	SinglyOrderedList list2;

	list2.insertItem(2);
	list2.insertItem(5);
	list2.insertItem(1);

	std::cout << list2;
	std::cout << "Adding list2 to list1...\n";
	list1.addList(std::move(list2));

	std::cout << "list1: " << list1 << "list2: " << list2 << "\n";

	list2.insertItem(2);
	list2.insertItem(5);
	list2.insertItem(1);

	std::cout << "========== Remove from list ==========\n\n";
	std::cout << "list1 before removing(): " << list1 << "list2 before removing(): " << list2;
	std::cout << "Removing list2 from list1...\n";
	list1.removeFromList(std::move(list2));

	std::cout << "list1 after removing(): " << list1 << "list2 after removing(): " << list2 << "\n";

	list1.insertItem(1);
	list1.insertItem(5);

	std::cout << "========== Cross lists ==========\n\n";
	std::cout << "list1: " << list1 << "list2: " << list2;
	SinglyOrderedList list3 = crossLists(std::move(list1), std::move(list2));
	std::cout << "New list: list3\n" << "list3: " << list3 << "list1 : " << list1 << "list2 : " << list2 << "\n";

	std::cout << "Done! Everything is working. Exiting programm...\n";
	return 0;
}