#ifndef SALES_H
#define SALES_H
#include "Employee.h"

class Sales:virtual public Employee
{
    public:

        Sales(const char* name,int internship,int numberOfSales);

        double getSalary()const;
        virtual int getNumberOfSales()const;

        void setNumberOfSales(int n);

        virtual Employee* clone() const { return new Sales(*this);}

        virtual ~Sales(){}
    protected:

    private:
        int _numberOfSales;
};

#endif // SALES_H
