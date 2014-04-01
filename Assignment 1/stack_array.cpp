#include<iostream>
#include<stdio.h>
#define LIM 100

using namespace std;

template<class T>
class stack{
	T buffer[LIM];
	int top_position;
	
	public:
	stack() : top_position(0) {}	// constructor
	void push(T c);
	T pop();
	int isEmpty();
	T top();
};

template<class T> void stack<T>::push(T c){
	buffer[++top_position] = c;
}

template<class T> T stack<T>::pop(){
	return buffer[top_position--];
}

template<class T> T stack<T>::top(){
	return buffer[top_position];
}

template<class T> int stack<T>::isEmpty(){
	return ((top_position == 0) ? 1 : 0) ;
}

int main()
{
	stack<char> s1;
	char t;
	while((t = getchar()) != '\n')
		s1.push(t);
	while(!s1.isEmpty())
		cout << s1.pop() << endl;
	return 0;
}
