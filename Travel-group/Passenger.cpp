
#include<cassert>
#include<iostream>
#include"Luggage.h"
#include"Ticket.h"
#include"Passenger.h"

using namespace std;

int Passenger::counter = 0;

Passenger::Passenger() :_name(NULL), _luggage(), _ticket()
{
	counter++;
}
Passenger::Passenger(const char*name, const Luggage& luggage,  const Ticket& ticket)
{
	_luggage=luggage;
	_ticket=ticket;
	_name = new char[strlen(name) + 1];
	assert(_name != NULL);
	strcpy_s(_name,strlen(name)+1, name);
	counter++;
}
Passenger::Passenger(Passenger const& right)
{
    _luggage=right._luggage;
    _ticket=right._ticket;
	_name = new char[strlen(right._name) + 1];
	assert(_name != NULL);
	strcpy_s(_name, strlen(right._name)+1,right._name);
	counter++;
}
Passenger& Passenger::operator=(const Passenger& right) {
	if (this != &right)
	{
		delete[] _name;
		_name = new char[strlen(right._name) + 1];

		strcpy_s(_name,strlen(right._name)+1, right._name);
		_luggage = right._luggage;
		_ticket = right._ticket;
		counter++;
	}
	return *this;
}

char* Passenger::getName()const
{
	return _name;
}
 Luggage Passenger::getLuggage()const
{

	return _luggage;
}
 Ticket Passenger::getTicket()const
{
	return _ticket;
}
void Passenger::setName(const char*name) {
	assert(name);
	delete[] _name;
	_name= new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
}
void Passenger::setLuggage(const Luggage &luggage)
{
	_luggage = luggage;
}
void Passenger::setTicket(const Ticket &ticket)
{
	_ticket = ticket;
}

Passenger::~Passenger() {
	delete[] _name;
	_name = NULL;
	counter--;
}

bool Passenger::sameStartStation(Passenger right)
{
    return this->getTicket().getstartStation()==right.getTicket().getstartStation();
}
bool Passenger::samedestination(Passenger right)
{
     return this->getTicket().getdestination()== right.getTicket().getdestination();
}
