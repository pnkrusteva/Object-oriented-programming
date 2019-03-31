
#include<iostream>
#include"Luggage.h"

using namespace std;


int Luggage::_id = 0;
Luggage::Luggage():_weight(0),_capacity(0),_number(0)
{
     _id++;
}
Luggage::Luggage(double weight,double capacity,int number)
{
    _weight=weight;
    _capacity=capacity;
    _number=number;
    _id++;
}
void Luggage::setcapacity(double weight)
{
     _weight=weight;
}
void Luggage::setweight(double capacity)
{
     _capacity=capacity;
}
void Luggage::setnumber(int number)
{
     _number=number;
}

double Luggage::getcapacity()const
{
    return _capacity;
}
double Luggage::getweight()const
{
    return _weight;
}
int Luggage::getnumber()const
{
    return _number;
}
int Luggage::getid()const
{
    return _id;
}
