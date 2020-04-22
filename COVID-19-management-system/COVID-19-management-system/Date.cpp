#include "Date.h"
#include "Helper.h"
#include <iostream>

Date::Date()
{
	year = "00";
	month = "00";
	year = "1990";
}

Date::Date(string date)
{
	if (date.length() != 10)
		throw (std::string("Date must be in dd/mm/yyyy format!"));
	if (date[2] != '/' or date[5] != '/')
		throw (std::string("Date must be in dd/mm/yyyy format!"));

	//day
	if (Helper::isDigit(date[0]) and Helper::isDigit(date[1]))
	{
		int dayNum = std::stoi(date.substr(0, 2));
		if (dayNum < 1 or dayNum > 31)
			throw (std::string("day must be 1 to 31!"));
		this->day = date.substr(0, 2);
	}
	else
	{
		throw (std::string("day must be in 'dd' format, and must be number!"));
	}

	//month
	if (Helper::isDigit(date[3]) and Helper::isDigit(date[4]))
	{
		int monthNum = std::stoi(date.substr(3, 2));
		if (monthNum < 1 or monthNum > 12)
			throw (std::string("month must be 1 to 12!"));
		this->month = date.substr(3, 2);
	}
	else
	{
		throw (std::string("month must be in 'mm' format, and must be number!"));
	}

	//year
	if (Helper::isDigit(date[6]) and Helper::isDigit(date[7]) and Helper::isDigit(date[8]) and Helper::isDigit(date[9]))
	{
		int yearNum = std::stoi(date.substr(6, 4));
		if (yearNum < 0 or yearNum > 9999)
			throw (std::string("year must be larger than 0, and contain 4 digits!"));
		this->year = date.substr(6, 4);
	}
	else
	{
		throw (std::string("year must be in 'yyyy' format, and must be number!"));
	}
}

bool Date::operator<(const Date& other) const
{
	if (year < other.getYear())
		return true;
	else if (year > other.getYear())
		return false;
	else if (month < other.getMonth())
		return true;
	else if (month > other.getMonth())
		return false;
	else if (day < other.getDay())
		return true;
	else return false;
}


std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	date.toOs(os);
	return os;
}
