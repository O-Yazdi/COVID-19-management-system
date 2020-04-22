#pragma once
#include <string>
using std::string;

class Date
{
private:
	string year;
	string month;
	string day;

public:
	Date();
	Date(string date) throw();

	string getYear() const { return year; }
	string getMonth() const { return month; }
	string getDay() const { return day; }

	virtual void toOs(std::ostream& os) const {}
	friend std::ostream& operator<<(std::ostream& os, const Date& date);

	bool operator < (const Date& other)const;
};

