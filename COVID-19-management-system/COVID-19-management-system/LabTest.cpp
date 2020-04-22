#include "LabTest.h"
#include<iostream>
LabTest::LabTest(string date, string labID, string testID, bool result) throw() : date(date), labID(labID), testID(testID), result(result)
{

}

std::ostream& operator<<(std::ostream& os, const LabTest& lab)
{
	os << lab.date << "\t" << lab.labID << "\t" << lab.testID << "\t" << ((lab.result) ? "POSITIVE" : "NEGATIVE");
	return os;
}

