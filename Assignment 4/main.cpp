#include<iostream>
#include<string>
#include "ExpTree.h"

using namespace std;

int main()
{
	ExpressionTree t;
	cout << "Enter postfix expression (eg: AB+) : ";
	string postfix;
	cin >> postfix;
	t.buildTree(postfix);
	t.printPrefix();
	return 0;
}
