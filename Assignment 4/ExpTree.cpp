#include "ExpTree.h"

node :: node(char t)
{
	left = right = parent = NULL;
	data = t;
}

/*
 * Start from right end of the postfix expression. Create a new node for each token(called newNode below). 
 * Steps:
 *	1. If currentNode(which is the previous token in the tree) is an operand , currentNode = currentNode->parent
 *	2. Insert as right child to currentNode if there is space, else left child. If no space, currentNode = currentNode -> parent. After insertion curentNode = newNode
 *	3. Repeat 1 , 2 until currentNode == newNode
 */
void ExpressionTree::buildTree(string &postfix)
{
	for(string::reverse_iterator it = postfix.rbegin(); it != postfix.rend(); ++it) {
		
		node *newNode = new node(*it);	
		
		// Make the last token the root
		if(it == postfix.rbegin()){
			root = currentNode = newNode;
		}
		
		else {
			// Place the new node into the expression tree
			while(currentNode != newNode) {
			
				// If current node is operator and if it has space append to right(if not, then left)
				if(currentNode -> data == '+' || currentNode -> data == '-' || currentNode -> data == '*' || currentNode -> data =='/') {
					if(currentNode -> right == NULL) {
						currentNode -> right = newNode;
						newNode -> parent = currentNode;
						currentNode = newNode;
					}
					else if(currentNode -> left == NULL) {
						currentNode -> left = newNode;
						newNode -> parent = currentNode;
						currentNode = newNode;
					}
					else
						currentNode = currentNode -> parent;
				}
				
				//else go to parent
				else
					currentNode = currentNode -> parent;
			}		
		}
	}
}

// Public version. Will call internal version with root.
void ExpressionTree::printInfix_rec()
{
	printInfix_r(root);
	cout << endl;
}

// Print left subtree, print root, print right subtree. Recursive.
void ExpressionTree::printInfix_r(node *t)
{
	if(t == NULL)
		return;
	// print bracket if token isn't a leaf node
	if(t -> left != NULL && t -> right != NULL)
		cout << "( " ;
	printInfix_r(t -> left);
	cout << t -> data << " ";
	printInfix_r(t -> right);
	if(t -> left != NULL && t -> right != NULL)
		cout << ") " ;
}

// Print post fix public version. Will call internal version with root as arg.
void ExpressionTree::printPostfix_rec()
{
	printPostfix_r(root);
	cout << endl;
}

// Print left subtree, right subtree, root
void ExpressionTree::printPostfix_r(node *t)
{
	if(t == NULL)
		return;
	printPostfix_r(t -> left);
	printPostfix_r(t ->right);
	cout << t -> data << " ";
}

// Print prefix public version. Will call internal version with root as arg.
void ExpressionTree::printPrefix_rec()
{
	printPrefix_r(root);
	cout << endl;
}

// Print left subtree , right subtree, root
void ExpressionTree::printPrefix_r(node *t)
{
	if(t == NULL)
		return;
	cout << t -> data << " ";
	printPrefix_r(t -> left);
	printPrefix_r(t -> right);
}

// Non recursive implementation
void ExpressionTree::printPrefix()
{
	node *t;
	stack<node*> s;
	s.push(root);
	while( !s.isEmpty() ) {
		t = s.pop();
		cout << t -> data << " ";
		if(t -> right != NULL)
			s.push( t -> right );
		if(t -> left != NULL)
			s.push(t -> left);
	}
	cout << endl;
}

void ExpressionTree::printInfix()
{
	node *t;
	stack<node*> s;
	s.push(root);
	while( !s.isEmpty() ) {
		t = s.pop();
		if(t -> right != NULL)
			s.push(t -> right);
		cout << t -> data << " ";
		if(t -> left != NULL)
			s.push(t -> left);
	}
}
