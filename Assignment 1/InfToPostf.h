#ifndef IN_POST
#define IN_POST

#include<iostream>
#include<string>
#include "mystack.cpp"

using namespace std;

int convert_postfix(string &in, string &post);
int compare_priority_postfix(char op1, char op2);


#endif
