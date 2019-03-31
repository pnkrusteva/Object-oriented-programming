#include<iostream>
#include"Ticket.h"
#include<cassert>
#include<string.h>

using namespace std;


Ticket::Ticket(): _transport(Car),_startStation(NULL),_destination(NULL),_price(0)
{

}

Ticket::Ticket(int helpnum,const char*startStation ,const char* destination,int price)
{
    _transport=(Transport)helpnum;
    _price=price;
    _startStation = new char[strlen(startStation)+1];
    strcpy(_startStation, startStation);
    _destination = new char[strlen(destination)+1];
    strcpy(_destination, destination);
}

Ticket::Ticket(const Ticket& right)
{
    _transport=right. _transport;
    _price=right._price;
    _startStation = new char[strlen(right._startStation)+1];
    strcpy(_startStation, right._startStation);
    _destination = new char[strlen(right._destination)+1];
    strcpy(_destination,right._destination);
}

Ticket&::Ticket operator=(const Ticket& right)
{
    if (this != &right)
    {
       delete [] _startStation;
       delete [] _destination;
       _transport=right. _transport;
       _price=right._price;
       _startStation = new char[strlen(right._startStation)+1];
       strcpy(_startStation, right._startStation);
       _destination = new char[strlen(right._destination)+1];
       strcpy(_destination,right._destination);
    }

    return *this;
}

Ticket::~Ticket()
{
    delete [] _startStation;
    delete [] _destination;
}

void Ticket::setTransport(int helpnum)
{
    _transport=(Transport)helpnum;
}
void Ticket::setStartStation(const char* startStation)
{
    _startStation = new char[strlen(startStation)+1];
    strcpy(_startStation, startStation);
}
void Ticket::setDestination(const char* destination)
{
    _destination = new char[strlen(destination)+1];
    strcpy(_destination,destination);
}
void Ticket::setPrice(int price)
{
    _price=price;
}

Transport Ticket::getTransport()const
{
    return _transport;
}
const char* Ticket::getstartStation()const
{
    return _startStation;
}
const char* Ticket::getdestination()const
{
    return _destination;
}
int Ticket::getPrice()const
{
    return _price;
}

