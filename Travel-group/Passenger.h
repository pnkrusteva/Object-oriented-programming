
#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include"Luggage.h"
#include"Ticket.h"
class Passenger {
public:
	Passenger();
	Passenger(const char*name,  const Luggage &luggage, const  Ticket &ticket);

	Passenger(Passenger const&);

	Passenger& operator=(const Passenger& right);

	~Passenger();

	void setName(const char*name);
	void setLuggage(const Luggage& luggage);
	void setTicket(const Ticket& ticket);

	char* getName()const;
	Luggage getLuggage()const;
	Ticket getTicket()const;

	bool sameStartStation(Passenger);
	bool samedestination(Passenger);
	static int counter;
private:
	char* _name;
	Luggage _luggage;
	Ticket _ticket;
    



};

#endif // PASSENGER_H_INCLUDED
