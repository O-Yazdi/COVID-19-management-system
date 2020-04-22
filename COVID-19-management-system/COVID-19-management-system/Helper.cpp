#include "Helper.h"

bool Helper::isDigit(char tav)
{
	if (tav < '0' or tav > '9')
		return false;
	return true;
}

bool Helper::isNumber(std::string num)
{
	for (int i = 0; i < num.length(); i++)
	{
		if (!isDigit(num[i]))
			return false;
	}
	return true;
}
