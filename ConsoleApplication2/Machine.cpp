#include "Machine.h"

Machine::Machine(std::string n)
{
	name = n;
}

void Machine::Attach(Observer *o)
{
	vObservers.push_back(o);
}

void Machine::NotifyAllObservers()
{
	std::for_each(vObservers.begin(), vObservers.end(), [&](Observer *o) {
		o->Update(state, name);
	});
}

void Machine::SetState(std::string s)
{
	state = s;
	NotifyAllObservers();
}

Machine::~Machine()
{
	std::for_each(vObservers.begin(), vObservers.end(), [&](Observer *o) {
		delete o;
		o = nullptr;
	});
}