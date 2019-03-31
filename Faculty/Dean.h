#ifndef DEAN_H
#define DEAN_H
#include"Professor.h"
#include"Employee.h"

class Dean:public Professor,public Employee
{
    public:
        Dean(const char* name, const char* birthdayDate,const char* position, double salary, const char* specialty,Student* student, int numOfStudent);
};

#endif // DEAN_H
