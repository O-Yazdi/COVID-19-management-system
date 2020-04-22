#include "Encounter.h"
#include <iostream>
int Encounter::staticEncounterID = 1;

Encounter::Encounter(string firstName, string lastName, string phone, Person* sourceID) : Person(firstName, lastName, phone, sourceID)
{
	encounterID = std::to_string(staticEncounterID);
	staticEncounterID++;
}

void Encounter::showEncounter() const
{
	std::cout << "\nEncounter details id : " << encounterID << "\nsource sick id: " << sourceSick->getID()
		<< ", sick first name: " << sourceSick->getName() << ", sick lastname: " << sourceSick->getLastName()
		<< "\nperson name: " << name << ", last name: " << lastName << ", phone: " << phone;
}


