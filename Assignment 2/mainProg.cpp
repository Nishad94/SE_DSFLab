#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "CircularQueue.h"
#include "record.h"
#define MAX_REC 50

using namespace std;

int main()
{
	database records[MAX_REC];
	int rec_id = 0;
	Queue<database> q;
	bool run;
	do {
		system("clear");
		cout << "\t\t\t\tCircular Queue using Arrays\n\n" << endl;
		cout << " 1. Add a record to the Queue. (Enqueue)\n 2. Delete a record from the Queue. (Dequeue)\n 3. Display Queue.\n 4. Exit\n\n Your choice: " ;
		int choice;
		cin >> choice;
		if(choice == 4)
			exit(0);
		switch(choice) {
			case 1 : 
			{
				if(q.checkOverflow())
					cout << " Queue is full, cannot add new elements! Please delete some data .." << endl;
				else {
					/* Add new record */
					cout << " Name: " ;
					string name;
					getchar();
					getline(cin, name, '\n');
					cout << " Roll Number : " ;
					int roll;
					cin >> roll;
					cout << " Mobile Number : " ;
					string phone;
					cin >> phone;
					
					records[rec_id].add_record(name, roll, phone);
					
					if(q.enqueue(records[rec_id])) {
						cout << "There was some problem in insertion, exiting program! " << endl;
						exit(1);
					}
				}
			}
			break;
			
			case 2 :
			{
				if(q.checkUnderflow())
					cout << " Cannot delete elements from an empty Queue! " << endl;
				else {
					database data;
					bool success;
					success = q.dequeue(data);
					if(success)
						cout << " The record for \"" << data.getName() << "\" was removed successfully! " << endl;
					else {
						cout << " There was some error in this operation, exiting program.. " << endl;
						exit(1);
					}
				}
			}
			break;
			
			case 3:
				cout << endl << " Elements in Queue: " << endl << endl;
				q.displayQueue();
			break;
			
			default:
				cout << " Wrong choice entered! " << endl;
			break;
		}
		
		cout << "\n Press 1 to re-run program and 0 to exit...\n" << endl;
		cin >> run;	
	} while(run) ;	
	return 0;
}
	
