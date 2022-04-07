#pragma once
#include "Observer.h"

#include <vector>
#include <algorithm>

class Subject
{
public:
	void virtual SetState(std::string s) = 0;
	void virtual Attach(Observer *o) = 0;
	void virtual NotifyAllObservers() = 0;

protected:
	std::string state;
	std::vector<Observer*> vObservers;
};

