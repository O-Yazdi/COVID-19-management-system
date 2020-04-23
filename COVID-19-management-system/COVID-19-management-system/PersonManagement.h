#pragma once
#include"person.h"
#include<list>
class PersonManagement
{
private:
	std::list<Person*> personList;
	std::list<LabTest*> testList;
	static int itToNewSick;

	Person* findPersonByID(string id) const;
	Person* findEncounterId(string id) const;
	std::list<Person*>::const_iterator getPersonByID(string id) const;

	void updateStatusPerson(Person*& person, bool resultLabTest);

	void deleteLabTestInPerson(LabTest* lab);

	std::list<LabTest*>::const_iterator findTestLab(string labid, string testid);

public:
	void createSick(string param);

	void createSick(string ID, string firstname, string lastname, string birthdate,
		string phone, string mail, string city, string street, int houseNumber,
		int apartment, int houseResidents);

	void addRouteSite(string param);

	void addRouteAddress(string param);

	void addSickEncounter(string param);

	void showSickEncounter();

	void updateSickEncounter(string param);

	void updateSickEncounter(string encounterID, string sickID, string firstname, string lastname,
		string birthdate, string phone, string mail, string city, string street, int houseNumber,
		int apartment, int houseResidents);

	void updateLabTest(string param);

	void updateLabTest(string labid, string testid, string personid, string date, bool result);

	void showNewSick() const;

	void showStat(string somePARAM) const;

	void showPerson(string personid) const;

	void showPersonRoute(string personid) const;

	void showSick() const;

	int getCountSicks() const;

	int getCountHealed() const;

	void showIsolated() const;

	int getCountIsolated() const;

	void showSickPerCity() const;


	~PersonManagement();
};

