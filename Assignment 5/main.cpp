#include<iostream>
#include<cstdlib>
#include "bst.cpp"

using namespace std;

int main()
{
	
	tree<int> T;
	while(true) {
		int choice;
		cout << " Choose an operation:\n 1. Insert items into tree.\n 2. Delete items from tree.\n 3. In-order tree traversal\n 4. Search\n 5. Exit" << endl;
		cin >> choice;
		if(choice >= 1 && choice <= 5) {
			system("clear");
			switch(choice) {
				case 1 : 	// Insert
				{
					int newItem;
					cout << " Enter item to insert : ";
					cin >> newItem;
					T.insert(newItem);
					cout << " The new item has been added successfully" << endl;
				}
				break;
				
				case 2: 	// Delete
				{
					int delItem;
					cout << " Enter the item you want to delete : ";
					cin >> delItem;
					/*if(T.del(delItem) == NULL)		// unsuccessful deletion
						cout << " The item could not be deleted for some reason!" << endl;
					else
						cout << delItem << " has been successfully removed!\n";*/
				}
				break;
				
				case 3: 	// Tree traversal
				{
					T.inorder_print();
				}
				break;
				
				case 4: 	// Search
				{
					int searchItem;
					cout << "Enter item to search for : ";
					cin >> searchItem;
					if(T.search(searchItem) == NULL)
						cout << " The item wasn't found, try a different query!" << endl;
					else
						cout << searchItem << " is present in the tree!" << endl;
				}
				break;
				
				case 5:		// exit
				{
					exit(0);
				}
				break;
			}
		}
	}
	return 0;
}
