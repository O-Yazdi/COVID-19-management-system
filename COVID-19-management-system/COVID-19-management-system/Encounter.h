#pragma once
#include "Person.h"

class Encounter : public Person
{
	bool fullDetails = false;
	string encounterID;
	static int staticEncounterID;
public:
	Encounter(string firstName, string lastName, string phone, Person* sourceID);

	void setfullDetails() { fullDetails = true; }

	bool isfullDetails() const { return fullDetails; }
	
	virtual string getType() const override { return "Encounter"; }
	
	string getEncounterID() const { return encounterID; }
	
	void showEncounter() const;
};

