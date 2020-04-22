#pragma once
#include"Person.h"
#include"DateAndTime.h"
#include <string>

using std::string;

class LabTest
{
private:
	Date date;
	string labID;
	string testID;
	bool result;
public:
	LabTest(string date, string labID, string testID, bool result) throw();
	string getLabID() const { return labID; }
	string getTestID() const { return testID; }
	bool getResult() const { return result; }
	friend std::ostream& operator<<(std::ostream& os, const LabTest& lab);
};

