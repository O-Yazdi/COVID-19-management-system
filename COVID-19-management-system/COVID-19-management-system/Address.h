#pragma once
#include "Site.h"
#include <string>
using std::string;

class Address : public Site
{
private:
	string city;
	string street;
	int houseNumber;
	int apartment;
	int houseResident;

public:
	Address();
	Address(string city, string street, int houseNumber, int apartment, int houseResident, string siteName = "home");
	virtual void toOs(std::ostream& os) const override;
};

