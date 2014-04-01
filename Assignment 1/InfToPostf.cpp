/*int main()
{
	cout << "Enter infix string : ";
	string infix;
	getline(cin, infix, '\n');
	string postfix;
	if (convert_postfix(infix, postfix))
		cout << "There was some error in the infix string. Please follow the correct infix format!" << endl;
	else
		cout << "Postfix : " << postfix << endl;
	return 0;
}*/

#include "InfToPostf.h"


/* 
 * Function to convert infix to postfix. 
 * Returns 0 on successful execution, else returns a non-zero value.
 */
int convert_postfix(string &in, string &post)
{
	stack<char> s1;
	int length_inf = in.length();
	for (int i = 0; i < length_inf ; ++i) {
		if (in[i] == ' ') {
			if(*(post.end() - 1) != ' ')	
				post.push_back(in[i]);		/* Prevent multiple consecutive spaces */
		}
		else if (in[i] >= '0' && in[i] <= '9') {
			post.push_back(in[i]);			/* Directly copy operands */
			if(!(in[i+1] >= '0' && in[i+1] <= '9')) 	/* If next token is not a digit, insert space */
				post.push_back(' ');
		}
		else if (in[i] == '\0') 
			break;
		else {
			if(s1.isEmpty())		/* empty stack, just push the operator */
				s1.push(in[i]);
			else{
				while (!s1.isEmpty() && (compare_priority_postfix(in[i],s1.top()) <= 0)){		/* pop all higher or equal precedence operators */
					if(s1.top() != '('){
						post.push_back(s1.pop());
						
						if(*(post.end() - 1) != ' ')	/* Spacing */
							post.push_back(' ');
					}
					else{
						if(in[i] == ')'){
							s1.pop();		/* Discard '(' */
							break;			/* End of tokens inside this bracket */
						}
					}
				}
				if(in[i] != ')')		/* Discard ')' */
					s1.push(in[i]);
			}
		}
	}
	
	while(!s1.isEmpty()){		/* Push remaining operators */
		if(*(post.end() - 1) != ' ') 	/* 	Put a space between tokens */
			post.push_back(' ');
		post.push_back(s1.pop());
	}
	post.push_back('\0');
	return 0;
}



/* 
 * Function to compare priorities of different operators.
 * Precedence : '(', ^, / *, + - , ')'
 * Returns 1 if pr(op1) > pr(op2),
 *		   0 if pr(op1) == pr(op2),
 *		  -1 if pr(op1) < pr(op2)
 */
int compare_priority_postfix(char op1, char op2)
{
	if (op1 == ')')						/* Lowest precedence */
		return -1;
	else if (op1 == '(')		/* Highest precedence as op1 */
		return 1;		
	else if (op2 == '(')				/* Lowest precedence  as op2 (exception: op1 == ')' ) */
		return 1;
	switch (op1) {
	case '(' :
	
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
