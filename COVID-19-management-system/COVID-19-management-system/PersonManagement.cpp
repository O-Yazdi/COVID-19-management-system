#include "PersonManagement.h"
#include"Sick.h"
#include"Helper.h"
#include<iostream>
#include<list>

//define keywords for lab test results 
#define POSITIVE "true"
#define NEGATIVE "false"


Person* PersonManagement::findPersonByID(string id) const
{
	for (auto it : personList)
	{
		if (it->getID() == id)
		{
			return it;
		}
	}
	return nullptr;
}

Person* PersonManagement::findEncounterId(string encounterId) const
{
	for (auto it : personList)
	{
		if(it->getType() == "Encounter")
			if (((Encounter*)it)->getEncounterID() == encounterId)
			{
				return it;
			}
	}
	return nullptr;
}


std::list<Person*>::const_iterator PersonManagement::getPersonByID(string id) const
{
	for (std::list<Person*>::const_iterator it = personList.begin(); it != personList.end(); it++)
	{
		if ((*it)->getID() == id)
		{
			return it;
		}
	}
	return personList.end();
}


void PersonManagement::updateStatusPerson(Person*& person, bool resultLabTest)
{
	if (person->getType() == "Sick")
	{
		person->setIsSick(resultLabTest);
	}
	else if (person->getType() == "Encounter")
	{
		if (resultLabTest)
		{
			person = new Sick((Encounter*)person);
			std::list<Person*>::const_iterator it = getPersonByID(person->getID());
			delete(*it);
			personList.erase(it);
			personList.push_back(person);
		}
	}
}

void PersonManagement::deleteLabTestInPerson(LabTest* lab)
{
	for (auto i : personList)
		i->deleteLabTest(lab);
}
std::list<LabTest*>::const_iterator PersonManagement::findTestLab(string labid, string testid)
{
	for (std::list<LabTest*>::const_iterator it = testList.begin(); it != testList.end(); it++)
	{
		if (labid == (*it)->getLabID())
			if(testid == (*it)->getTestID())
					return it;
	}
	return testList.end();
}


void PersonManagement::createSick(string param)
{
	do
	{
		size_t i = param.find(' ');
		if (i == string::npos)
			break;
		string id = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string firstName = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string lastName = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string birthdate = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string phone = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string email = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string city = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string street = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string houseNumberStr = param.substr(0, i);
		if (!Helper::isNumber(houseNumberStr))
			break;
		int houseNumber = std::stoi(houseNumberStr);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string apartmentStr = param.substr(0, i);
		if (!Helper::isNumber(apartmentStr))
			break;
		int apartment = std::stoi(apartmentStr);

		if (++i >= param.length())
			break;
		string houseResidentsStr = param.substr(i);
		if (!Helper::isNumber(houseResidentsStr))
			break;
		int houseResidents = std::stoi(houseResidentsStr);

		createSick(id, firstName, lastName, birthdate, phone, email, city, street,
			houseNumber, apartment, houseResidents);
		return;

	} while (false);
	throw string("no match param for 'Create-sick' command!");
}

void PersonManagement::createSick(string ID, string firstname, string lastname, string birthdate, string phone,
	string mail, string city, string street, int houseNumber, int apartment, int houseResidents)
{
	std::list<Person*>::const_iterator it = getPersonByID(ID);
	//Check if that person already exists, so we replace it
	if (it != personList.end())
	{
		delete (*it);
		personList.erase(it);
	}
	personList.push_back(new Sick(ID, firstname, lastname, birthdate, phone, mail, city,
		street, houseNumber, apartment, houseResidents));
	std::cout << "new sick id: " << ID << " added successfully\n";
}

void PersonManagement::addRouteSite(string param)
{
	size_t i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Add-route-site' command!");
	string id = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Add-route-site' command!");
	param = param.substr(i);

	Person* person = findPersonByID(id);
	if (person == nullptr)
		throw string("Add-route-site: ID" + id + " didn't exist!");

	if (person->getType() != "Sick")
		throw string("Add-route-site: Route-Site can only added to Sick!");

	((Sick*)(person))->addRouteSite(param);
}

void PersonManagement::addRouteAddress(string param)
{
	size_t i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Add-route-address' command!");
	string id = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Add-route-address' command!");
	param = param.substr(i);

	Person* person = findPersonByID(id);
	if (person == nullptr)
		throw string("Add-route-address: ID " + id + " didn't exist!");

	if (person->getType() != "Sick")
		throw string("Add-route-address: Route-Site can only added to Sick!");

	((Sick*)(person))->addRouteAddress(param);
}

void PersonManagement::addSickEncounter(string param)
{
	size_t i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Add-sick-encounter' command!");
	string id = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Add-sick-encounter' command!");
	param = param.substr(i);

	Person* person = findPersonByID(id);
	if (person == nullptr)
		throw string("Add-sick-encounter: ID " + id + " didn't exist!");

	if (person->getType() != "Sick")
		throw string("Add-sick-encounter: encounter can only added to Sick!");

	i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Add-sick-encounter' command!");
	string firstname = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Add-sick-encounter' command!");
	param = param.substr(i);
	i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Add-sick-encounter' command!");
	string lastname = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Add-sick-encounter' command!");
	string phone = param.substr(i);

	Encounter* encounter = new Encounter(firstname, lastname, phone, person);

	personList.push_back(encounter);

	((Sick*)(person))->addSickEncounter(*encounter);

	std::cout << "Add-sick-encounter: name " << firstname << " added to sick ID: " + id + " successfully\n";
}

void PersonManagement::showSickEncounter()
{
	for (auto i : personList)
	{
		if(i->getType() == "Encounter")
			if (!((Encounter*)i)->isfullDetails())
			{
				((Encounter*)i)->showEncounter();
				std::cout << "\n";
			}
	}
}

void PersonManagement::updateSickEncounter(string param)
{
	do
	{
		size_t i = param.find(' ');
		if (i == string::npos)
			break;
		string encounterId = param.substr(0, i);

		Person* person = findEncounterId(encounterId);
		if (person == nullptr)
			throw string("Update-sick-encounter-details: encounterId " + encounterId + " didn't exist!");


		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string personId = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string firstName = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string lastName = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string birthdate = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string phone = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string email = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string city = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string street = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string houseNumberStr = param.substr(0, i);
		if (!Helper::isNumber(houseNumberStr))
			break;
		int houseNumber = std::stoi(houseNumberStr);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string apartmentStr = param.substr(0, i);
		if (!Helper::isNumber(apartmentStr))
			break;
		int apartment = std::stoi(apartmentStr);

		if (++i >= param.length())
			break;
		string houseResidentsStr = param.substr(i);
		if (!Helper::isNumber(houseResidentsStr))
			break;
		int houseResidents = std::stoi(houseResidentsStr);

		person->setID(personId);
		person->setBirthdate(birthdate);
		person->setEmail(email);
		person->setAddress(city, street, houseNumber, apartment, houseResidents);
		((Encounter*)person)->setfullDetails();
		std::cout << "Update-sick-encounter-details: ID " << personId << " and other details successfully updated\n";
		return;

	} while (false);
	throw string("no match param for 'Add-sick-encounter' command!");

}


PersonManagement::~PersonManagement()
{
	std::cout << "DES!";
	for (auto i : personList)
	{
		std::cout << i->getType() << " ~!";
		delete i;
	}
}

void PersonManagement::showPerson(string personid)
{
	Person* person = findPersonByID(personid);
	if (person == nullptr)
		throw string("Show-person: ID " + personid + " didn't exist!");

	person->showPerson();
}

void PersonManagement::showPersonRoute(string personid)
{
	Person* person = findPersonByID(personid);
	if (person == nullptr)
		throw string("Show-person-route: ID " + personid + " didn't exist!");

	((Sick*)person)->showPersonRoute();
}

void PersonManagement::updateLabTest(string param)
{
	size_t i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Update-lab-test' command!");
	string labid = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Update-lab-test' command!");
	param = param.substr(i);
	i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Update-lab-test' command!");
	string testid = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Update-lab-test' command!");
	param = param.substr(i);
	i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Update-lab-test' command!");
	string personid = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Update-lab-test' command!");
	param = param.substr(i);
	i = param.find(' ');
	if (i == string::npos)
		throw string("no match param for 'Update-lab-test' command!");
	string date = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Update-lab-test' command!");
	string resultStr = param.substr(i);
	if (resultStr != NEGATIVE and resultStr != POSITIVE)
		throw string("no match param for 'Update-lab-test' command!, result must be 'true' or 'false' only!");
	bool result = (resultStr == POSITIVE ? true : false);

	updateLabTest(labid, testid, personid, date, result);
}

void PersonManagement::updateLabTest(string labid, string testid, string personid, string date, bool result)
{
	Person* person = findPersonByID(personid);
	if (person == nullptr)
		throw string("Update-lab-test: ID " + personid + " didn't exist!");

	LabTest* newLabTest = new LabTest(date, labid, testid, result);

	std::list<LabTest*>::const_iterator lab = findTestLab(labid, testid);
	if (lab != testList.end())
	{
		deleteLabTestInPerson(newLabTest);
		delete (*lab);
		testList.erase(lab);
	}
	testList.push_back(newLabTest);
	person->addLabTest(newLabTest);

	updateStatusPerson(person, result);
}
