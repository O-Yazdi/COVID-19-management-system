#pragma once
#include <string>
#include"Date.h"
#include "Address.h"
#include"LabTest.h"
#include<list>
using std::string;


class LabTest;
class Person
{
protected:
	string name;
	string lastName;
	string ID;
	Date birthDate;
	string phone;
	string email;
	Address address;
	std::list<LabTest> testList;
	Person* sourceSick;
	bool sick;

public:
	Person(string name, string lastName, string phone, Person* sourceSick);

	Person(string name, string lastName, string phone, string ID, string birthDate,
		string email, string city, string street, int houseNumber, int apartment, int houseResidents = 1, Person* sourceSick = nullptr);

	void deleteLabTest(LabTest* labtest);

	Person(const Person& other);
	const Person& operator=(const Person& other);


	void setID(string id) { if (ID == "null") ID = id; }//The ID can only be edited if it is still empty
	string getID() const { return ID; }

	string getName() const { return name; }

	string getLastName() const { return lastName; }

	string getPhone() const { return phone; }

	string getSourceSick() const { return sourceSick->getID(); }

	void setBirthdate(string date) { birthDate = date; }

	void setEmail(string email) { this->email = email; }

	void setAddress(string city, string street, int houseNumber, int apartment, int houseResidents)
	{
		address = Address(city, street, houseNumber, apartment, houseResidents);
	}
	
	virtual string getType() const { return "Person"; }

	virtual void addLabTest(LabTest* labtest);

	void setIsSick(bool result) { this->sick = result; }
		
	virtual void toOs(std::ostream& os) const {}

	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	void showPerson() const;
	virtual ~Person();
};

