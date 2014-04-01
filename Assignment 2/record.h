#ifndef REC_H
#define REC_H
#include<string>
#include<iostream>

using namespace std;

class database {
	private:
		string name;
		int roll_num;
		string phone_num;
		
		void setName(string newName);		
		void setRoll(int newRoll);	
		void setPhone(string newPhone);
		
	
	public:
		string getName();
		int getRoll();
		string getPhone();
		void add_record(string name, int roll, string phone);
		void display_record(ostream& os);
};



#endif
