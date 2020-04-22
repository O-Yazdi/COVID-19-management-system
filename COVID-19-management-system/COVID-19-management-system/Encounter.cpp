#include "Encounter.h"
int Encounter::staticEncounterID = 1;

Encounter::Encounter(string firstName, string lastName, string phone, string sourceID) : Person(firstName, lastName, phone, sourceID)
{
	encounterID = std::to_string(staticEncounterID);
	staticEncounterID++;
}


