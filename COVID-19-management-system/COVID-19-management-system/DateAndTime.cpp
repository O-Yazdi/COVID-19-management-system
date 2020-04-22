#include "DateAndTime.h"
#include "Helper.h"
#include<iostream>

DateAndTime::DateAndTime() : Date()
{
	hour = "00";
	minuth = "00";
}

DateAndTime::DateAndTime(string dateAndTime) throw() : Date(dateAndTime.substr(0,10))
{
	if(dateAndTime[10] != ' ' )
			throw (std::string("DateTime must be in dd/mm/yyyy HH:MM format!"));
	if (dateAndTime[13] != ':')
		throw (std::string("DateTime must be in dd/mm/yyyy HH:MM format!"));

	//hour
	if (Helper::isDigit(dateAndTime[11]) and Helper::isDigit(dateAndTime[12]))
	{
		int hourNum = std::stoi(dateAndTime.substr(11, 2));
		if (hourNum < 0 or hourNum > 23)
			throw (std::string("hour must be between 0 to 23!"));
		this->hour = dateAndTime.substr(11, 2);
	}
	else
	{
		throw (std::string("hour must be in 'HH' format, and must be number!"));
	}

	//minute
	if (Helper::isDigit(dateAndTime[14]) and Helper::isDigit(dateAndTime[15]))
	{
		int minutsNum = std::stoi(dateAndTime.substr(14, 2));
		if (minutsNum < 0 or minutsNum > 60)
			throw (std::string("minutes must be between 0 to 60!"));
		this->minuth = dateAndTime.substr(14, 2);
	}
	else
	{
		throw (std::string("minutes must be in 'MM' format, and must be number!"));
	}
}

void DateAndTime::toOs(std::ostream& os) const
{
	os<<" "<<hour << ":" <<minuth;
}
