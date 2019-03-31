#ifndef MANAGER_H
#define MANAGER_H
#include "Sales.h"
#include "Programmer.h"

class Manager:public Sales,public Programmer
{
    public:

        Manager(const char* name,int internship,int numberOfSales,int numberOfPrograms,const char* nickname,int numOfShares );
        Manager(const Manager&other);
        Manager& operator=(const Manager& right);
        ~Manager();

        void setNickname(const char* nickname);
        void setNumberOfShares(int num);

        const char* getNickname()const;
        int getNumberOfShares()const;

        virtual double getSalary()const;

        virtual Employee* clone() const { return new Manager(*this);}

    protected:

    private:
        void copyManager(const Manager& other);
        int _numberOfShares;
        char* _nickname;
};

#endif // MANAGER_H
