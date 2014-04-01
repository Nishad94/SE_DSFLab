#include<iostream>
#include<limits>
#include<string>

using namespace std;

void getline_enhance(string &t, char delim);

class patientRec {

	string name;
	int age;
	string contactNum;
	int priority;
	string illness;
	
	public:
		patientRec() {}
		patientRec(const patientRec &temp) {
			*this = temp;						//Copy initialization
		}
		void addDetails();
		void displayRecord();
		friend class priorityQueue;
};

class node : public patientRec {
		node *next;
	
		public:
			node() {next = NULL;}
			node(const patientRec &temp): patientRec(temp), next(NULL) {}
			friend class Queue;
};

class Queue {
	node *front, *rear;
	
	public:
		Queue() : front(NULL), rear(NULL) {}
		void enqueue(const patientRec &p);
		int dequeue(patientRec &p);
		void display();
		int isEmpty();
		~Queue() { delete front; delete rear; };
};

class priorityQueue {
	Queue *q;
	int numOfPriorities;
	
	public:
		priorityQueue(int p = 3) : numOfPriorities(p) {
			q = new Queue[p];
		}
		void pEnqueue(patientRec &p);
		int pDequeue();
		void pDisplay();
		~priorityQueue() { 
				delete q;
		}
};




