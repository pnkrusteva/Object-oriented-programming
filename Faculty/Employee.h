#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "People.h"

class Employee : virtual public People
{
	public:
		Employee(const char* name, const char* birthdayDate, const char* position, double salary);
		Employee(const Employee&);
		Employee& operator=(const Employee&);
		~Employee();

		const char* getPosition() const { return this->_position; }
		double getSalary() const { return this->_salary; }

		void setPosition(const char*);
		void setSalary(double);

		void print() const;
	private:
		char* _position;
		double _salary;
};

#endif // EMPLOYEE_H
