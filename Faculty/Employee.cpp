#include "Employee.h"
#include <iostream>
#include <string.h>

using namespace std;

void Employee::setPosition(const char* position)
{
	int len = strlen(position);

	if (len==0)
		throw "The position cannot be empty!";

	delete[] this->_position;
	this->_position = new char[len + 1];
	strcpy(this->_position, position);
}

void Employee::setSalary(double salary)
{
	if (salary <= 0)
		throw "The salary should be positive number!";

	this->_salary = salary;
}

Employee::Employee(const char* name,const char* birthdayDate,const char* position, double salary)
	:People(name, birthdayDate), _position(NULL)
{
	setPosition(position);
	setSalary(salary);
}

Employee::Employee(const Employee& other):People(other), _position(NULL)
{
	setPosition(other._position);
	setSalary(other._salary);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		People::operator=(other);

		this->setPosition(other._position);
		this->setSalary(other._salary);
	}

	return *this;
}

Employee::~Employee()
{
	delete[] this->_position;
}

void Employee::print() const
{
	People::print();

	cout << "Position: " << this->_position << endl;
	cout << "Salary: " << this->_salary <<endl;
}
