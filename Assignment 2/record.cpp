#include "record.h"

void database::setName(string newName)
{
	this->name = newName;
}

string database::getName()
{
	return(this->name);
}

void database::setRoll(int newRoll)
{
	this->roll_num = newRoll;
}

int database::getRoll()
{
	return(this->roll_num);
}

void database::setPhone(string newPhone)
{
	this->phone_num = newPhone;
}

string database::getPhone()
{
	return(this->phone_num);
}

void database::add_record(string name, int roll, string phone)
{
	setName(name);
	setRoll(roll);
	setPhone(phone);
}

void database::display_record(ostream& os)
{
	os << " Name : " << getName() << endl << " Roll Number : " << getRoll() << endl << " Phone number : " << getPhone() << endl << endl;
}
