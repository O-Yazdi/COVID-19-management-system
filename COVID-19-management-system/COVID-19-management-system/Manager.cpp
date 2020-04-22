#include "Manager.h"
#include "Sick.h"
#include"Helper.h"
#include <iostream>

Manager* Manager::instance = nullptr;

void Manager::showHelp() const
{
	std::cout << "please insert the follow command in your file:\n"
		"1. Create-sick\n"
		"2. Add-route-site\n"
		"3. Add-route-address\n"
		"4. Add-sick-encounter\n"
		"5. Show-sick-encounter\n"
		"6. Update-sick-encounter-details\n"
		"7. Update-lab-test\n"
		"8. Show-new-sick\n"
		"9. Show-stat\n"
		"10. Show-person\n"
		"11. Show-person-route\n"
		"12. Show-sick\n"
		"13. Show-isolated\n"
		"14. Show-help\n";
}

Manager::~Manager()
{
}


Manager* Manager::getManager()
{
	if (instance == nullptr)
		instance = new Manager();
	return instance;
}

void Manager::checkAndRunCommand(string cmd) throw()
{
	size_t i = cmd.find(' ');
	if (i == string::npos)
		i = cmd.length();

	string titleOfCommand = cmd.substr(0, i); //cut the title of command
	i++; //now i is after the ' ' if exists
	if (titleOfCommand == "Create-sick")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Create-sick' command!");
		string param = cmd.substr(i);
		personManage.createSick(param);
	}
	else if (titleOfCommand == "Add-route-site")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Add-route-site' command!");
		string param = cmd.substr(i);
		personManage.addRouteSite(param);
	}
	else if (titleOfCommand == "Add-route-address")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Add-route-address' command!");
		string param = cmd.substr(i);
		personManage.addRouteAddress(param);
	}
	else if (titleOfCommand == "Add-sick-encounter")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Add-sick-encounter' command!");
		string param = cmd.substr(i);
		personManage.addSickEncounter(param);
	}
	else if (titleOfCommand == "Show-sick-encounter")
	{
		personManage.showSickEncounter();
	}
	else if (titleOfCommand == "Update-sick-encounter-details")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Update-sick-encounter-details' command!");
		string param = cmd.substr(i);
		personManage.updateSickEncounter(param);
	}
	else if (titleOfCommand == "Update-lab-test")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Update-lab-test' command!");
		string param = cmd.substr(i);
		personManage.updateLabTest(param);
	}
	else if (titleOfCommand == "Show-new-sick")
	{

	}
	else if (titleOfCommand == "Show-stat")
	{

	}
	else if (titleOfCommand == "Show-person")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Show-person' command!");
		string id = cmd.substr(i);
		personManage.showPerson(id);
	}
	else if (titleOfCommand == "Show-person-route")
	{
		if (i >= cmd.length())
			throw string("no match param for 'Show-person-route' command!");
		string id = cmd.substr(i);
		personManage.showPersonRoute(id);
	}
	else if (titleOfCommand == "Show-sick")
	{

	}
	else if (titleOfCommand == "Show-isolated")
	{

	}
	else if (titleOfCommand == "Show-help")
	{

	}
	else
	{
		throw string("no match any command!");
	}
}


