#include "Employee.h"
#include<string.h>

using namespace std;

Employee::Employee(const char* name,int internship):_name(NULL)
{
    setInternship(internship);
    setName(name);
}

Employee::Employee(const Employee& other)
{
    copyEmployee(other);
}

Employee&Employee:: operator=(const Employee& right)
{
    if(this!=&right)
    {
        copyEmployee(right);
    }
    return *this;
}

Employee::~Employee()
{
    delete[] this->_name;
}

double Employee::getSalary()const
{
    return 2*_internship + 500;
}

const char* Employee::getName() const
{
    return _name;
}

int Employee::getInternship()const
{
    return _internship;
}

void Employee::setInternship(int internship)
{
    if(internship<0)
        throw "The internship should be positive number!";

    _internship=internship;
}

void Employee::setName(const char* name)
{
    int len = strlen(name);

    if (!name || !len)
		throw "The name can not be empty!";

	delete[] this->_name;

	this->_name = new char[len + 1];
	strcpy(this->_name,name);
}

void Employee::copyEmployee(const Employee& other)
{
    setInternship(other._internship);
    setName(other._name);
}
