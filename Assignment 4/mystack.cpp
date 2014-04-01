#ifndef MY_STACK_CPP
#define MY_STACK_CPP

template <class T>
class Node {
	public:
		T data;
		Node *next;
	
	public:
		Node() : next(0) {}
		Node(T element, Node *t = 0) { 
			data = element;
			next = t;
		}
};


template <class T>
class stack : public Node<T> {
	
	/*struct list{
		T data;
		struct list* next;
	};*/
	Node<T> *head;	
	
	public:
	stack() : head(0) {}		//constructor with in class intializers
	void push(T c);
	T pop();
	int isEmpty();
	T top();
};

// O(1) insertion
template<class T> void stack<T>::push(T c){
	//create new node
	Node<T> *newElement = new Node<T>(c);
	newElement -> next = head;
	head = newElement;			// New elements are added to the top of the stack by shifting the head to the newest position.
}

// O(1) deletion
template<class T> T stack<T>::pop(){
	if(head == 0)	//empty stack
		return 0;
	else{
		T c  = head -> data;
		Node<T> *temp = head;
		head = head -> next;
		delete(temp);
		return c;
	}
}

// returns 1 if empty, else 0
template<class T> int stack<T>::isEmpty(){
	return head == 0 ;
}

//returns last element without removing it
template<class T> T stack<T>::top(){
	if(head) //non empty
		return head -> data;
}

#endif
