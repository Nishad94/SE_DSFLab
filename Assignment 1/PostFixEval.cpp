/*
	Postfix evaluation.
	Supported Ops: *, /, +, -
*/

#include "PostfixEval.h"

using namespace std;

int evaluate(stack<int> &s);


int evaluate(stack<int> &s)
{
	char c;
	int result;
	while((c = getchar()) != '\n')
	{
		if(c == ' ')
			;
		else if(c < '0' || c > '9')		//operator
		{
			int op2 = s.pop(), op1 = s.pop();
			
			switch(c)
			{
				case '+' :
					result = op1 + op2;
				break;
				
				case '-' :
					result = op1 - op2;
				break;
				
				case '*' :
					result = op1 * op2;
				break;
				
				case '/' :
					if(op2 == 0){
						cout << "Cannot divide by 0, exiting program!" << endl;
						exit(-1);
					}
					result = op1 / op2;
				break;
				
				default :
					cout << "Invalid Operator, exiting program! " << endl;
					exit(-1);
					break;
			}
			
			s.push(result);
		} else if(c >= '0' && c <= '9'){
			int num = c - '0';
			while(((c = getchar()) != ' ') && c != '\n')	//operands
			{
				num = (num * 10) + (c - '0') ;
			}
			s.push(num); //push number on stack
		}
	}
	
	//display result
	cout << "Answer : " << result << endl;
}
