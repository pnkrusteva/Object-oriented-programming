#include "Manager.h"
#include<string.h>
#include<iostream>
using namespace std;

Manager::Manager(const char* name,int internship,int numberOfSales,int numberOfPrograms,const char* nickname,int numberOfShares):Employee(name,internship),Programmer(name,internship,numberOfPrograms),Sales(name,internship,numberOfSales), _nickname(NULL)
{
    setNickname(nickname);
    setNumberOfShares(numberOfShares);
}

Manager::Manager(const Manager& other):Employee(other),Programmer(other),Sales(other)
{
    copyManager(other);
}
Manager& Manager::operator=(const Manager& right)
{
    if(this!=&right)
    {
        Employee::operator=(right);
        copyManager(right);
    }
    return *this;
}
Manager::~Manager()
{
    delete[] this->_nickname;
}

void Manager:: setNickname(const char* nickname)
{
    int len = strlen(nickname);

    if (!nickname || !len)
		throw "The nickname can not be empty!";

	delete[] this->_nickname;

	this->_nickname = new char[len + 1];
	strcpy(this->_nickname,nickname);
}
void Manager::setNumberOfShares(int num)
{
     if(num<0)
        throw "The number of shares should be positive number!";

    _numberOfShares=num;
}

const char* Manager::getNickname()const
{
    return _nickname;
}
int Manager::getNumberOfShares()const
{
    return _numberOfShares;
}

double Manager::getSalary()const
{
   return 3*_numberOfShares+100;
}

void Manager::copyManager(const Manager& other)
{
    setNickname(other._nickname);
    setNumberOfShares(other._numberOfShares);
}
