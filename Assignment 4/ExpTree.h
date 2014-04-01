#include<iostream>
#include<string>
#include "mystack.cpp"

using namespace std;


class node {
	node *left, *right, *parent;
	char data;
	
	public:
		node() : left(NULL), right(NULL), parent(NULL) {};
		node(char t);		
		friend class ExpressionTree;	
};


class ExpressionTree {
	node *root, *currentNode;
	void printInfix_r(node *t);
	void printPostfix_r(node *t);
	void printPrefix_r(node *t);
	
	public:
		ExpressionTree() : root(NULL), currentNode(NULL) {}
		void buildTree(string &postfix);
		void printInfix_rec();
		void printPostfix_rec();
		void printPrefix_rec();
		void printInfix();
		void printPostfix();
		void printPrefix();
};
