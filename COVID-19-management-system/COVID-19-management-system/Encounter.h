#pragma once
#include "Person.h"

class Encounter : public Person
{
	bool fullDetails = false;
	string encounterID;
	static int staticEncounterID;
public:
	void setfullDetails() { fullDetails = true; }
	bool isfullDetails() const { return fullDetails; }
	Encounter(string firstName, string lastName, string phone, string sourceID);
	virtual string getType() const override { return "Encounter"; }
	string getEncounterID() const { return encounterID; }
	
};

