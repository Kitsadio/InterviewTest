#pragma once
#include "Subject.h"

class Machine : public Subject
{
public:
	std::string name;

	void SetState(std::string s) override;
	void Attach(Observer *o) override;
	void NotifyAllObservers() override;

	Machine(std::string n);
	~Machine();
};

