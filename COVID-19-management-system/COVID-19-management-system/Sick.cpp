#include "Sick.h"
#include"Helper.h"
#include"Encounter.h"
#include<iostream>

Sick::Sick(string id, string firstname, string lastname, string birthdate,
	string phone, string mail, string city, string street, int houseNumber,
	int apartment, int houseResidents) :Person(firstname, lastname, phone, id, birthdate, mail, city, street,
		houseNumber, apartment, houseResidents)
{
	sick = true;
}

Sick::Sick(Encounter* encounter) :Person(*(Person*)encounter)
{
	sick = true;
}


void Sick::addRouteAddress(string param)
{
	do
	{
		size_t i = param.find(' ');
		i = param.find(' ', i + 1); //becuse date and time we need two spaces
		if (i == string::npos)
			throw string("no match param for 'Add-route-address' command!");
		string dateAndTime = param.substr(0, i);

		if (++i >= param.length())
			break;
		param = param.substr(i);
		i = param.find(' ');
		if (i == string::npos)
			break;
		string siteName = param.substr(0, i);

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
		string houseNumberStr = param.substr(i);
		if (!Helper::isNumber(houseNumberStr))
			break;
		int houseNumber = std::stoi(houseNumberStr);

		addRouteSite(new DateAndTime(dateAndTime), new Address(city, street, houseNumber, 1, 1, siteName));
		std::cout << "added address " << siteName <<", "<< city << ", "<< street<< ", "<< houseNumber <<
			" to id: " << ID << " successfully\n";
		return;

	} while (false);
	throw string("no match param for 'Add-route-address' command!");
}

void Sick::addRouteSite(string param)
{
	size_t i = param.find(' ');

	if (++i >= param.length())
		throw string("no match param for 'Add-route-site' command!");
	i = param.find(' ', i + 1); //becuse date and time we need two spaces
	if (i == string::npos)
		throw string("no match param for 'Add-route-site' command!");
	string dateAndTime = param.substr(0, i);

	if (++i >= param.length())
		throw string("no match param for 'Add-route-site' command!");
	string sitename = param.substr(i);

	addRouteSite(new DateAndTime(dateAndTime), new Site(sitename));
	std::cout << "added site " << sitename << " to id: " << ID << " successfully\n";
}

void Sick::addRouteSite(Date* ptrDate, Site* ptrSite)
{
	routeList.insert({ ptrDate,ptrSite });
}

void Sick::addSickEncounter(const Encounter& encounter)
{
	encounterList.push_back(encounter);
}

void Sick::showPersonRoute() const
{
	std::cout << "\nRoute of sick id: " << ID << std::endl;
	for (auto i : routeList)
	{
		std::cout << *(i.first) << "   " << *(i.second) << std::endl;
	}
	std::cout << "\n";
}


Sick::~Sick()
{
	for (auto i : routeList)
	{
		delete i.first;
		delete i.second;
	}
}
