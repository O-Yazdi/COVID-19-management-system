#include "Site.h"
#include <iostream>
Site::Site()
{
	siteName = "home";
}
Site::Site(string siteName) : siteName(siteName)
{
}

std::ostream& operator<<(std::ostream& os, const Site& site)
{
	os << "Site Name: " << site.siteName;
	site.toOs(os);
	return os;
}
