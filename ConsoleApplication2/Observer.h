#pragma once
#include <cstdio>
#include <string>
#include <iostream>

class Observer
{
public:
	void virtual Update(std::string state, std::string from) = 0;

	std::string name;
};

