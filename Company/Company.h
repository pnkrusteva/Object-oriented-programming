#ifndef COMPANY_H
#define COMPANY_H
#include "Manager.h"
#include<iostream>

using namespace std;
class Company
{
public:
    Company( Employee** employees=NULL,int numberOfEmployees=0);
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    void addEmployee(const Employee& employee);
    void removeSales(int salary);
    void removeProgrammer(int salary) ;
    void removeManager(int salary);
    void removeEmployee(int salary);

protected:

private:
    void moveElementsAfter(int index);
    void deleteTheEmployeeIfHisSalaryIsHigher(int index,int salary);
    void copyArr(Employee** other);
    void copyCompany(const Company& other);
    void extendCompany();
    Employee** _employees;
    int _numberOfEmployees;
    int _capacity;
};

#endif // COMPANY_H
