#include "People.h"
#include<string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

void People::setName(const char* name)
{
	int len = strlen(name);

	if (len==0)
		throw "The name cannot be empty!";

	delete[] this->_name;
	this->_name = new char[len + 1];
	strcpy(this->_name, name);
}
bool isDateValid(const char* date);
void  People::setBirthdayDate(const char *birthdayDate)
{
    if(!isDateValid(birthdayDate))
        throw "The date is not valid!";

    strcpy(this->_birthdayDate, birthdayDate);
}

People::People(const char* name, const char* birthdayDate ):_name(NULL)
{
	setName(name);
    setBirthdayDate(birthdayDate);
}

People::People(const People& other)
	: People(other._name, other._birthdayDate)
{}
People& People::operator=(const People& other)
{
	if (this != &other)
	{
        setName(other._name);
        setBirthdayDate(other._birthdayDate);
	}

	return *this;
}

People::~People()
{
	delete[] this->_name;
}

void People::print() const
{
	cout << "Name: " << this->_name << endl;
	cout << "Birthday Date: " << this->_birthdayDate<< endl;
}
bool isDateValid(const char* date)
{
    for(int i=0;i<strlen(date);i++)
        if(!isdigit(date[i]))return false;
    if(strlen(date)!=8)return false;

    int year,month,day,help;
    help=atoi(date);
    year=help/10000;
    help=help%10000;
    month=help/100;
    help=help%100;
    day=help;
    bool IsTheYearLeap, IsTheMonthfeb,IsTheMonthWith31Days;

    IsTheYearLeap=((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
    IsTheMonthfeb=(month==2);
    IsTheMonthWith31Days=(month<8&&month%2!=0||month>7&&month%2==0);

    if(day<=0||month<=0||year<0)return false;
    if(month<=12)
        {
            if(IsTheMonthfeb)
                {
                    if(IsTheYearLeap)
                        {
                            if(day>29)return false;
                        }
                    else
                        if(day>28)return false;
                }
            if(IsTheMonthWith31Days)
            {
                if(day>31)return false;
            }
                else
                    {
                        if(day>30)return false;
                    }
        }
    else
        return false;

    return true;
}
