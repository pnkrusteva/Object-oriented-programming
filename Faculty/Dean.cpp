#include "Dean.h"
#include"Professor.h"
#include<iostream>
Dean::Dean(const char* name, const char* birthdayDate,const char* position, double salary, const char* specialty,Student* student, int numOfStudent):
    People(name,birthdayDate),Employee(name,birthdayDate,position,salary),Professor(name,birthdayDate,specialty, student,numOfStudent)
{
}

