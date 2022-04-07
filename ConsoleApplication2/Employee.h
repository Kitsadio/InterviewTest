#pragma once
#include "Observer.h"

class Employee : public Observer
{
public:
	void Update(std::string state, std::string from) override;
	std::string role;

	Employee(std::string r, std::string n);
};

