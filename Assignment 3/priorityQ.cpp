#include "priorityQ.h"


/*
 * Clear input stream and then call getline()
 * Use this function if you want to use getline() right after cin(). DO NOT use this just after getline().
 */
void getline_enhance(string &t, char delim)
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), delim);
	getline(cin,t,delim);
}

// Display current record
void patientRec::displayRecord()
{
	cout << " Patient name : " << name << endl;
	cout << " Patient age : " << age << endl;
	cout << " Contact number : " << contactNum << endl;
	cout << " Paient illness : " << illness << endl << endl;
}

// Add patient details in record
void patientRec::addDetails()
{
	cout << "Enter the following details:\n Patient name : " ;
	getline_enhance(name,'\n');
	cout << " Patient age : "; 
	cin >> age;
	cout << " Contact number : ";
	getline_enhance(contactNum,'\n');
	cout << " Illness : ";
	getline(cin,illness,'\n');		
	cout << " Patient priority : " ;
	cin >> priority;
	
}

void Queue::enqueue(const patientRec &p)
{
	node *newNode = new node(p);			/// <--- Problem here(check)
	
	if(rear != NULL) {
		rear->next = newNode;
		rear = rear->next;
	}
	else 
		front = rear = newNode;			// This is the first element in the Queue
		
}

// Returns 0 on success, else returns 1 as error
int Queue::dequeue(patientRec &p)
{
	if(isEmpty())
		return 1;
	else {	
		p = *front;						// Get 'patientRec' baseclass of class 'node'
		node *temp = front;
		front = front->next;
		delete temp;
		return 0;
	}
}

// Returns 1 if Queue is empty
int Queue::isEmpty()
{
	if(front == NULL)
		return 1;
	else
		return 0;
}

/*
 * Display all records in a queue
 */
void Queue::display()
{
	node *t = front;
	while(t != NULL) {
		t->displayRecord();
		t = t->next;
	}
}

//Enqueues according to prioriy in the appropriate queue
void priorityQueue::pEnqueue(patientRec &p)
{
	if(p.priority > numOfPriorities)
		cout << " You have entered an invalid priority number! Did not add record to Queue. " << endl;
	else
		q[(p.priority - 1)].enqueue(p);			// If patient priority = 1(highest), add to q[0] priority=2, add to q[1] , priority=3(lowest), add to q[2]
}


/*
 * Removes element of highest priority 
 * Stores deleted element in p, and returns either a 0(for success) else a 1(for failure)
 */
int priorityQueue::pDequeue()
{
	int flag , i = 0;
	patientRec p;
	// If Queue is empty check next queue
	while((i < numOfPriorities) && (flag = q[i].dequeue(p)))			// dequeue() returns 0 on success
		i++;
	
	// Found record
	if(i < numOfPriorities) {
		cout << "The following patient has been processed ( removed ) : " << endl;
		p.displayRecord();
		return 0;		
	}
	else {
		cout << "No patient in queue! Please add patients .. " << endl;
		return 1;		// All queue's are empty
	}
}

// Display patient records
void priorityQueue::pDisplay()
{
	for(int i = 0; i < numOfPriorities; ++i) {
		cout << " --->Patients with Priority #" << i + 1 << " : " << endl << endl;
		q[i].display();
	}
}

