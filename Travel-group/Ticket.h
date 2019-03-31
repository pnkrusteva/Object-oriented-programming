#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED


enum Transport{Car,Airplane,Train,Bus,Ship};

class Ticket
{
public:
    Ticket();
    Ticket(int,const char* ,const char* name,int);

    Ticket(const Ticket& right);

    Ticket& operator=(const Ticket& right);

    ~Ticket();

    void setTransport(int helpnum);
    void setStartStation(const char* _startStation);
    void setDestination(const char* _destination);
    void setPrice(int _price);

    const char* getTransport()const;
    const char* getstartStation()const;
    const char* getdestination()const;
    int getPrice()const;

private:
     Transport _transport;
     char* _startStation;
     char* _destination;
     int _price;

};


#endif // TICKET_H_INCLUDED
