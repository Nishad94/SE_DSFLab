#include<iostream>
#include<stdlib.h>
#include "hash.cpp"

int main()
{
  hashTable h;
  while(1){
    system("clear");
    cout << "1. Add data.\n2. Remove data.\n3. Search data\n4. Display hash table\n5. Exit" << endl;
    int c;
    cin >> c;
    int n;
    switch(c){
    case 1:
      cout << "Number of entries to add : ";
      int t;
      cin >> t;
      while(t--){
	cout << "Enter integer : ";
	cin >> n;
	h.hashInsert(n);
      }
      break;

    case 2:
      cout << "Enter integer you want to delete : ";
      cin >> n;
      if(h.hashRemove(n))
	cout << n << " has been successfully removed!" << endl;
      else
	cout << n << " is not present in the table!" << endl;
      break;

    case 3:
      cout << "Enter search term : ";
      cin >> n;
      if(h.hashSearch(n))
	cout << n << " is present in the table.." << endl;
      else
	cout << n << " is not present in the table.." << endl;
      break;

    case 4:
      h.displayTable();
      break;
  
    case 5:
      exit(0);
    }
    cout << "Press 1 to continue, 0 to exit: ";
    int t;
    cin >> t;
    if(t == 0)
      break;
  }
  return 0;
}
