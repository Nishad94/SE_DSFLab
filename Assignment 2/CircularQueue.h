#ifndef C_Queue
#define C_Queue
#include <iostream>
#include <string>
#define SIZE_MAX 3

using namespace std; 


template <class T>
class Queue {
	private :
		T data[SIZE_MAX];
		int front, rear;		
		
	public:
		Queue() : front(-1), rear(-1) {}
		bool enqueue(T element);
		bool dequeue(T &data);
		bool isEmpty(void);
		bool checkUnderflow();
		bool checkOverflow();
		T Qfront();
		T Qrear();
		void displayQueue();				
};


/* Insert new element at the front . Returns 0 if successfull, else 1 */
template <class T>
bool Queue<T> :: enqueue(T element) 
{
	if(this -> checkOverflow())
		return 1;			/* Queue is full */
	else {
		if(front == -1) {		/* Empty stack */
			++front; ++rear; 
		}
		data[rear] = element;
		rear = (rear + 1) % SIZE_MAX ;
		return 0;
	}
}

/* Returns oldest element. Success = 1 indicates successful operation , Success = 0 indicates Queue is empty */
template <class T>
bool Queue<T> :: dequeue(T &data_dq)
{
	if(this -> checkUnderflow()) {					
		return 0; 					/* Queue empty */
	}
	data_dq = data[front] ;
	front = (front + 1) % SIZE_MAX ;
	if(front == rear) 	 				/* Queue is now empty */
		front = rear = -1;
	return 1;
}

/* Returns 1 if Queue is empty , else 0 */
template <class T>
bool Queue<T> :: isEmpty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}

/* Returns 1 if Queue is empty , else 0 */
template <class T>
bool Queue<T> :: checkUnderflow()
{
	if(front == -1)
		return 1;
	return 0;
}

/* Returns 1 if Queue is full , else 0 */
template <class T>
bool Queue<T> :: checkOverflow()
{
	if(front == rear) {
		if(front == -1)
			return 0;				/* Indicates empty queue */
		else
			return 1;				/* Indicates full queue */
	}
	return 0;
}

/* Returns newest element. No error checking */
template <class T>
T Queue<T> :: Qfront()
{
	return data[rear - 1];
}

/* Returns oldest element. No error checking */
template <class T>
T Queue<T> :: Qrear()
{
	return data[front];
}


/* Displays all the elements */
template <class T>
void Queue<T> :: displayQueue()
{
	if(front == -1)
		cout << " Queue is empty.. " << endl;
	else {
		int i = front;
		if(front == rear) {		/* Full Queue */
			data[front].display_record(cout);
			++i;
		}
		for( ; i != rear; i = (i + 1) % SIZE_MAX)
			data[i].display_record(cout);
		cout << endl << endl;
	}
}

#endif
