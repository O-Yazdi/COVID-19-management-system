#pragma once
#include <string>
#include "PersonManagement.h"
using std::string;

class Manager
{
private:
	PersonManagement personManage;
	static Manager* instance;
	Manager() {}

public:
	static Manager* getManager();

	void checkAndRunCommand(string cmd) throw();

	//void addSickEncounter(string sickID, string firstname, string lastname, string phone);

	//void showSickEncounter();

	//void updateSickEncounter(string encounterID, string sickID, string firstname, string lastname,
	//	string birthdate, string phone, string mail, string city, string street, int houseNumber,
	//	int apartment, int houseResidents);


	//void showNewSick();

	//void showStat(string somePARAM);

	//void showIsolated();

	void showHelp() const;

	~Manager();
};

