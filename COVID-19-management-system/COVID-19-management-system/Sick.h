#pragma once
#include "Encounter.h"
#include <map>

class Sick :public Person
{
private:
	std::multimap<Date* , Site*> routeList;//contains the sick's route including site/address and date
	std::list<Encounter> encounterList;

public:
	Sick(string id, string firstname, string lastname, string birthdate, string phone, string mail,
		string city, string street, int houseNumber, int apartment, int houseResidents);

	Sick(Encounter* encounter);

	void addRouteAddress(string param);

	void addRouteSite(string param);

	void addRouteSite(Date*ptrDate, Site* ptrSite);

	void addSickEncounter(const Encounter& encounter);

	void showPersonRoute() const;

	string getCity() const
	{
		return address.getCity();
	}
	bool isNew = true;
	virtual string getType() const override
	{
		if (sick)
			return "Sick";
		else
			return "healed";
	}

	~Sick();
};

