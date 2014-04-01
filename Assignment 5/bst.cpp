/* Name: Nishad Dawkhar
   SE 8, E 8, Roll Number: 2809
   Assignment:
   	Implement BST and perform following operations:
   		1. Create tree
   		2. Insert an element
   		3. Delete an element
   		4. Traversal - Recursive and non-recursive */
   		
#include<iostream>

using namespace std;

// Forward declaration
template< class T >
class tree;

template< class T >
class node {
	node<T> *left, *right, *parent;
	T data;
	
	public:
		node<T>() : left(NULL), right(NULL), parent(NULL) {}
		friend class tree<T>;
};

template< class T >
class tree {
	node<T> *root;
	void inorder_r(node<T> *t);
	
	public:
		tree() : root(NULL) {}
		int insert(T element);
		int del(T element);
		node<T>* search(T element);
		void inorder_print();
};


template< class T >
int tree<T>::del(T element)
{
	
}

template< class T >
node<T>* tree<T>::search(T element)
{
	node<T>* current = root;
	while(current != NULL) {
		if(current -> data == element)
			return current;
		else if(current -> data < element)
			current = current -> right;
		else
			current = current -> left;
	}
	return current;
}

template< class T >
// Returns 0 on success
int tree<T>::insert(T element)
{
	node<T> *current, *prev;
	current = prev = root;
	//cout << "lol" << endl;
	if(root == NULL) {
		
		node<T> *newNode = new node<T>();
		newNode -> data = element;
		root = newNode;
		//cout << "Element : " << newNode -> data << endl;
		return 0;
	}
	else {
		// Go on searching for the appropriate position to insert in
		while(current != NULL) {
			if(current -> data < element) {
				prev = current;
				current = current -> right;		
			}
			else if(current -> data > element) {
				prev = current;
				current = current -> left;
			}
			else {
				return 1;	// Element already present in the tree, no duplicates
			}
		}
		if(prev -> data < element) {
			// Insert to the right
			node<T> *newNode = new node<T>();
			newNode -> data = element;
			newNode -> parent = prev;
			
			prev -> right = newNode;
			
			return 0;
		}
		else {
			// Insert to the left
			node<T> *newNode = new node<T>();
			newNode -> data = element;
			newNode -> parent = prev;
			
			prev -> left = newNode;
			
			return 0;
		}
	}
	
}

template< class T >
void tree<T>::inorder_print()
{
	cout << "Items in tree: " << endl;
	inorder_r(root);
	cout << endl << endl;
}


template< class T >
void tree<T>::inorder_r(node<T> *t)
{
	if(t == NULL)
		return;
	else {
		inorder_r(t -> left);
		cout << " " << t -> data;
		inorder_r(t -> right);
	}
}
