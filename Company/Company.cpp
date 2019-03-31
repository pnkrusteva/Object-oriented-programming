#include "Company.h"
#include<iostream>
using namespace std;
Company::Company(Employee** employees,int numberOfEmployees):_employees(NULL)
{
    if(numberOfEmployees<0)
        throw "The number of employees should be positive!";

    this->_numberOfEmployees=numberOfEmployees;

    _capacity=_numberOfEmployees;

    this->_employees = new Employee*[_capacity];

    for(int i = 0; i <_numberOfEmployees; i++)
    {
       _employees[i] = employees[i]->clone();
    }
}

Company::Company(const Company& other)
{
    copyCompany(other);
}

Company& Company::operator=(const Company& other)
{
    if(this!=&other)
    {
        copyCompany(other);
    }
    return *this;
}

Company::~Company()
{
    for(int i=0;i<_numberOfEmployees;i++)
        delete[] _employees[i];
    delete[] _employees;
}
void Company::addEmployee(const Employee& employee)
{
    if(_numberOfEmployees==_capacity)
    {
        extendCompany();
    }
    _numberOfEmployees++;
    _employees[_numberOfEmployees]=employee.clone();
}

 void Company::removeSales(int salary)
 {
    for(int i=0;i<_numberOfEmployees;i++)
     {
         Sales* s=dynamic_cast<Sales*>(_employees[i])
         if(s!=NULL)
            deleteTheEmployeeIfHisSalaryIsHigher(i,salary);
     }
 }

void Company::removeProgrammer(int salary)
 {
    for(int i=0;i<_numberOfEmployees;i++)
     {
        Programmer* p=dynamic_cast<Programmer*>(_employees[i])

        if(p!=NULL)
            deleteTheEmployeeIfHisSalaryIsHigher(i,salary);
     }
 }

void Company::removeManager(int salary)
 {
    for(int i=0;i<_numberOfEmployees;i++)
     {
         Manager* m=dynamic_cast<Manager*>(_employees[i])
         if(m!=NULL)
            deleteTheEmployeeIfHisSalaryIsHigher(i,salary);
     }
 }

void Company::removeEmployee(int salary)
 {
    for(int i=0;i<_numberOfEmployees;i++)
     {
         Employee* e=dynamic_cast<Employee*>(_employees[i])

         if(e!=NULL)
            deleteTheEmployeeIfHisSalaryIsHigher(i,salary);
     }
 }



void Company::deleteTheEmployeeIfHisSalaryIsHigher(int index,int salary)
{
    if(_employees[index]->getSalary()>salary)
        {
            moveElementsAfter(index);
            _numberOfEmployees--;
        }
}


void Company::moveElementsAfter(int index)
{
    for(int i=index;i<_numberOfEmployees-1;++i)
    {
        this->_employees[i] = _employees[i++]->clone();
    }
}

void Company::copyArr(Employee** other)
{
    this->_employees = new Employee*[_capacity];
    for(int i = 0; i <_numberOfEmployees; ++i)
    {
        this->_employees[i] = _employees[i]->clone();
    }
}
void Company::copyCompany(const Company &other)
{
    this->_numberOfEmployees=other._numberOfEmployees;
    this->_capacity=other._capacity;
    this->_employees = new Employee*[_capacity];
    for(int i = 0; i <_numberOfEmployees; ++i)
    {
        this->_employees[i] = _employees[i]->clone();
    }
}
void Company:: extendCompany()
{
    Employee** temp = _employees;
    _capacity *= 2;

    _employees = new Employee*[_capacity];
    for(int i = 0; i < _numberOfEmployees; ++i)
    {
        _employees[i] = temp[i]->clone();
    }
    for(int i = 0; i < _numberOfEmployees; ++i)
    {
        delete temp[i];
    }
    delete [] temp;
}

