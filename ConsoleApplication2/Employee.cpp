#include "Employee.h"

void Employee::Update(std::string state, std::string from)
{
	std::cout << "State: " << state << " Machine Name: " << from << " Employee Role: " << role << " Employee Name: " << name << std::endl;
}

Employee::Employee(std::string r, std::string n)
{
	role = r;
	name = n;
}