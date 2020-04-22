#include "Address.h"
#include <iostream>

Address::Address()
{
	city = "null";
	street = "null";
	houseNumber= 0;
	apartment = 0;
	houseResident = 0;

}

Address::Address(string city, string street, int houseNumber, int apartment, int houseResident,
string siteName) : Site(siteName), city(city), street(street), houseNumber(houseNumber),
apartment(apartment), houseResident(houseResident)
{
	
}

void Address::toOs(std::ostream& os) const
{
	os<<".   " << "City: " <<city << ",  Strees: " <<street << ",  House Number: " <<houseNumber <<
		",  Apartment: " << apartment << ",  House Resident: " <<houseResident;
}

