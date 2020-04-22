#include "Person.h"
#include<iostream>


Person::Person(string name, string lastName, string phone, string sourceSick) : name(name), lastName(lastName), phone(phone), sourceSick(sourceSick)
{
	ID = "null";
	email = "null";
	sick = false;
}

Person::Person(string name, string lastName, string phone, string ID, string birthDate,
	string email, string city, string street, int houseNumber, int apartment, int houseResidents, string sourceSick)
	: name(name), lastName(lastName), phone(phone), ID(ID), birthDate(birthDate), email(email),
	address(city, street, houseNumber, apartment, houseResidents)
{
	this->sourceSick = sourceSick;
	sick = false;
}


void Person::addLabTest(LabTest* labtest)
{
	testList.push_back(*labtest);
	std::cout << "added lab test, labID: " << labtest->getLabID() << ", testID: " << labtest->getTestID() << ". to id: " << ID << " successfully\n";
}

void Person::deleteLabTest(LabTest* labtest)
{
	for (std::list<LabTest>::iterator it = testList.begin(); it!=testList.end(); ++it)
	{
		if ((*it).getLabID() == labtest->getLabID())
			if ((*it).getTestID() == labtest->getTestID())
			{
				testList.erase(it);
				return;
			}
	}
}
Person::Person(const Person& other)
{
	*this = other;
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		name = other.name;
		lastName = other.lastName;
		ID =  other.ID;
		birthDate = other.birthDate;
		phone = other.phone;
		email = other.email;
		address = other.address;
		testList = other.testList;
		sourceSick = other.sourceSick;
		sick = other.sick;
	}
	return *this;
}

void Person::showPerson() const
{
	std::cout << *this;
	std::cout << "\n** LAB RESULT BEGIN **\n";
	for (auto i : testList)
	{
		std::cout <<"     "<< i << std::endl;
	}
	std::cout << "** LAB RESULT END **\n\n";
}

Person::~Person()
{
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
	os << "\nPerson details id: " << p.ID << "\nfirst name: " << p.name << "\nlast name: " << p.lastName <<
		"\nis sick: "<< ((p.sick) ? "true" : "false")<<"\nbirthdate: "<< p.birthDate << "\nphone: "
		<< p.phone << "\nmail: " << p.email <<"\n"<< p.address<< "\nsource sick: " << p.sourceSick;
	return os;
}
