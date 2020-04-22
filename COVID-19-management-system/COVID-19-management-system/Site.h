#pragma once
#include <string>
using std::string;


class Site
{
private:
	string siteName;

public:
	Site();
	Site(string siteName);
	virtual void toOs(std::ostream& os) const {}
	friend std::ostream& operator<<(std::ostream& os, const Site& site);
};

