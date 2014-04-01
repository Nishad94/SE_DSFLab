

/*int main()
{
	cout << "Enter infix string : ";
	string infix;
	getline(cin, infix, '\n');
	string prefix;
	if (convert_prefix(infix, prefix))
		cout << "There was some error in the infix string. Please follow the correct infix format!" << endl;
	else
		cout << "Prefix : " << prefix << endl;
	return 0;
}*/

#include "InfToPref.h"

/* 
 * Function to convert infix to postfix. 
 * Returns 0 on successful execution, else returns a non-zero value.
 */
int convert_prefix(string &in, string &pre)
{
	stack<char> s1;
	int length_inf = in.length();
	/* Same algorithm as in->post . Reverese infix string , apply algorithm and in the end reverse result prefix string */
	for (int i = length_inf - 1; i >= 0 ; --i) {
		if (in[i] == ' ') {
			if(*(pre.end() - 1) != ' ')	
				pre.push_back(in[i]);		/* Prevent multiple consecutive spaces */
		}
		else if (in[i] >= '0' && in[i] <= '9') {
			pre.push_back(in[i]);			/* Directly copy operands */
			if(!(in[i+1] >= '0' && in[i+1] <= '9')) 	/* If next token is not a digit, insert space */
				pre.push_back(' ');
		}
		else if (in[i] == '\0') 
			break;
		else {
			if(s1.isEmpty())		/* empty stack, just push the operator */
				s1.push(in[i]);
			else{
				while (!s1.isEmpty() && (compare_priority_prefix(in[i],s1.top()) < 0)){		/* pop only higher precedence operators (end when stack is empty) */
					if(s1.top() != ')'){
						pre.push_back(s1.pop());
						
						if(*(pre.end() - 1) != ' ')	/* Spacing */
							pre.push_back(' ');
					}
					else{
						if(in[i] == '('){
							s1.pop();		/* Discard ')' */
							break;			/* End of tokens inside this bracket */
						}
					}
				}
				if(in[i] != '(')		/* Discard '(' */
					s1.push(in[i]);
			}
		}
	}
	
	while(!s1.isEmpty()){		/* Push remaining operators */
		if(*(pre.end() - 1) != ' ') 	/* 	Put a space between tokens */
			pre.push_back(' ');
		pre.push_back(s1.pop());
	}
	pre.push_back('\0');
	
	pre = reverse_string(pre);		/* Reverse o/p string for correct answer */
	return 0;
}



/* 
 * Function to compare priorities of different operators.
 * Precedence : '(', ^, / *, + - , ')'
 * Returns 1 if pr(op1) > pr(op2),
 *		   0 if pr(op1) == pr(op2),
 *		  -1 if pr(op1) < pr(op2)
 */
int compare_priority_prefix(char op1, char op2)
{
	if (op1 == '(')						/* Lowest precedence */
		return -1;
	else if (op1 == ')')		/* Highest precedence as op1 */
		return 1;		
	else if (op2 == ')')				/* Lowest precedence  as op2 (exception: op1 == '(' ) */
		return 1;
	else if(op2 == '^')			/* Highest precedence on stack */
		return -1;
	switch (op1) {
	case ')' :
	
			 /* Fall Through */
			 
	case '^' :
			 return 1;					/* Highest priority overall */
			 break;
	case '/' :
	
			 /* Fall Through */
			 
	case '*' :
			 if (op2 == '^')
			 	return -1;
			 else if (op2 == '/' || op2 == '*')
			 	return 0;
			 else
			 	return 1;
			 break;
	case '+' :
	
			 /* Fall Through */
			 
	case '-' :
			 if (op2 == '+' || op2 == '-')
			 	return 0;
			 else
			 	return -1;
			 break;
	}
}


/*
 * Reverse string
 */
string reverse_string(string &s)
{
	int length = s.length();
	string rev;		
	for(int i = length - 1; i >= 0; --i) {
		rev.push_back(s[i]);
	}
	rev.push_back('\0');
	return rev;
}
