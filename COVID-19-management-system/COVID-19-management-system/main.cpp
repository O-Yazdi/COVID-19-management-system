#include"Manager.h"
#include<iostream>
#include <fstream>

#define YOUR_PATH "C:\\Users\\עתניאל\\Source\\Repos\\O-Yazdi\\COVID-19-management-system\\cmd3.txt"

void main()
{
	std::ifstream cmdFile;
	cmdFile.open(YOUR_PATH);

	if (!cmdFile.is_open())
	{
		std::cerr << "can't open the file" << std::endl;
		exit(1);
	}

	string cmd = "";
	while (getline(cmdFile, cmd))
	{
		try
		{
			Manager* m = Manager::getManager();

			m->checkAndRunCommand(cmd);

		}
		catch (string err)
		{
			std::cerr << err << std::endl;
		}
		catch (...)
		{
			std::cerr << "some eror occured!";
		}
	}
	delete Manager::getManager();

}