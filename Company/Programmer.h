#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Employee.h"

class Programmer:virtual public  Employee
{
    public:

       Programmer(const char* name,int internship,int numberOfPrograms);

        double getSalary()const;

        void setNumberOfPrograms(int n);

        virtual int getNumberOfPrograms()const;

        virtual Employee* clone() const { return new Programmer(*this);}

    protected:

    private:
        int _numberOfPrograms;
};


#endif // PROGRAMMER_H
