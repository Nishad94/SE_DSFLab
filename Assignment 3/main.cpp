#include<iostream>
#include<cstdlib>
#include<cstdio>
#include "priorityQ.h"

using namespace std;

int main()
{
	int run, priorityNum;
	cout << "Specify Number of Priorities : " << endl;
	cin >> priorityNum;
	priorityQueue pq(priorityNum);
	do {
		system("clear");
		cout << "\t\t\t Priority Queue for Patient Processing" << endl << endl;
		int choice;
		cout << "Enter your choice:\n 1. Add patient   2. Process Patient   3. Display patient queue   4. Exit" << endl;
		cin >> choice;
		switch(choice) {
			case 1:
			{
				patientRec p;
				p.addDetails();		// Accept patient details
				pq.pEnqueue(p);		// Add to queue
			}
			break;
			
			case 2:
			{
				pq.pDequeue();
			}
			break;
			
			case 3:
			{
				pq.pDisplay();
			}
			break;
			
			case 4:
				exit(0);
			break;
			
			default:
				cout << "Wrong choice entered! Reloading app! " << endl;
		}
		cout << "Press 1 to continue , 0 to exit... " << endl;
		cin >> run;
	} 
	while(run);
	return 0;
}
