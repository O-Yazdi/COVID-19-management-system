#pragma once
#include "Date.h"
class DateAndTime : public Date
{
private:
	string hour;
	string minuth;

public:
	DateAndTime();
	DateAndTime(string dateAndTime) throw();
	virtual void toOs(std::ostream& os) const override;
};

