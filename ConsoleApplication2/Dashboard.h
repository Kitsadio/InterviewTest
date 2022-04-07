#pragma once
#include "Observer.h"

class Dashboard : public Observer
{
	void Update(std::string state, std::string from) override;
};

