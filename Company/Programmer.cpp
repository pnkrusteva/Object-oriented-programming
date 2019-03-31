#include "Programmer.h"

Programmer::Programmer(const char* name,int internship,int numberOfPrograms):Employee(name,internship)
{
  setNumberOfPrograms(numberOfPrograms);
}

double Programmer::getSalary()const
{
    return _numberOfPrograms+200;
}
void Programmer::setNumberOfPrograms(int numberOfPrograms)
{
    if(numberOfPrograms<0)
        throw "The number of programs should be positive!";

   _numberOfPrograms=numberOfPrograms;
}

int Programmer::getNumberOfPrograms()const
{
    return _numberOfPrograms;
}
