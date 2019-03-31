#include "Sales.h"
#include<iostream>
using namespace std;

Sales:: Sales(const char* name,int internship,int numberOfSales):Employee(name,internship)
{
  setNumberOfSales(numberOfSales);
}

double Sales::getSalary()const
{
    return _numberOfSales*3+100;
}

void Sales::setNumberOfSales(int numberOfSales)
{
    if(numberOfSales<0)
        throw "The number of sales should be positive!";

   _numberOfSales=numberOfSales;
}

int Sales::getNumberOfSales()const
{
    return _numberOfSales;
}
