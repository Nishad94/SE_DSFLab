#include<iostream>
#include<string>
#include<cstdlib>
#include "InfToPostf.h"
#include "InfToPref.h"
#include "PostfixEval.h"

int main()
{
	bool run;
	do {
		system("clear");
		cout << "\t\t\t\tEXPRESSION CONVERSION\n\n" << endl;
		cout << "\n 1. Perform infix to prefix conversion.\n 2. Perform infix to postfix conversion.\n \
3. Perform evaluation of postfix expression.\n 4. Exit\n\n Your choice: " ;
		int choice;
		cin >> choice;
		if(choice == 4)
			exit(0);
		
		string input;
		getchar() ; 				//absorb '\n' from i/p buffer
		switch(choice) {
			case 1 :
			{
				cout << " Enter infix string : " ;
				getline(cin, input, '\n');
				string prefix;
				if (convert_prefix(input, prefix))
					cout << "There was some error in the infix string. Please follow the correct infix format!" << endl;
				else
					cout << " Prefix : " << prefix << endl;
				break;
			}
			
			case 2 :
			{
				cout << " Enter infix string : " ;
				getline(cin, input, '\n');
				string postfix;
				if (convert_postfix(input, postfix))
					cout << "There was some error in the infix string. Please follow the correct infix format!" << endl;
				else
					cout << " Postfix : " << postfix << endl;
				break;
			}
				
			case 3 :
			{
				cout << " Enter postfix string : " ;
				getline(cin, input, '\n');
				evaluate(input);
				break;
			}
			
			default :
				cout << " Wrong choice entered! " << endl;
				break;
			
		}
		cout << "\n Press 1 to re-run program and 0 to exit...\n" << endl;
		cin >> run;		
	} while (run) ;
	return 0;
}
