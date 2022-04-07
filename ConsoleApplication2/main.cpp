#include "Machine.h"
#include "Employee.h"
#include "Dashboard.h"
#include <time.h>


#include <iostream>

int main()
{
	unsigned int t = 0;
	unsigned int currentTime = 0;
	unsigned int iterator = 0;

	Employee* _employee;
	Machine _machine("MACHINE");
	Machine _machine2("MACHINE2");
	Machine _machine3("MACHINE3");
	Dashboard* _dashboard = new Dashboard();

	_employee = new Employee("DEV","John");
	_machine.Attach(_employee);
	_employee = new Employee("TEST", "Dev");
	_machine.Attach(_employee);
	_employee = new Employee("ENG", "Lloyd");
	_machine.Attach(_employee);

	_machine.Attach(_dashboard);
	_machine2.Attach(_dashboard);
	_machine3.Attach(_dashboard);

	std::vector<std::string> _machineStates({ "PRODUCING", "IDLE", "STARVED" });
	while (true)	{

		currentTime = time(NULL);
		int difference = currentTime - t;
		if (difference > 3 || t == 0)
		{
			t = time(NULL);
			_machine.SetState(_machineStates[iterator]);
			_machine2.SetState(_machineStates[iterator]);
			_machine3.SetState(_machineStates[iterator]);
			iterator++;
			if(iterator > 2)
			{
				iterator = 0;
			}
		}
	}
}

