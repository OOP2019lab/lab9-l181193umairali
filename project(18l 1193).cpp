#include "Project.h"

Project::Project(char* name, int budget, int duration)
{
	int s = strlen(name) + 1;
	this->name = new char[s];
	strcpy_s(this->name, s, name);

	this->budget = budget;
	this->duration = duration;
}

Project::Project(const Project& temp)
{
	int s = strlen(temp.name) + 1;
	this->name = new char[s];
	strcpy_s(this->name, s, temp.name);

	this->budget = temp.budget;
	this->duration = temp.duration;
}

const Project& Project::operator = (const Project& temp)
{
	if (this != &temp)
	{
		int s = strlen(temp.name) + 1;
		if (this->name != nullptr)
			delete[]this->name;
		this->name = new char[s];
		strcpy_s(this->name, s, temp.name);

		this->budget = temp.budget;
		this->duration = temp.duration;
	}

	return *this;
}

ostream& operator << (ostream& out, const Project& temp)
{
	out << temp.name << ", Budget = " << temp.budget << ", Duration = " << temp.duration;
	return out;
}

void Project::setBudget(const int bug)
{
	this->budget = bug;
}

Project::~Project()
{
	if (this->name != nullptr)
		delete[]this->name;
}