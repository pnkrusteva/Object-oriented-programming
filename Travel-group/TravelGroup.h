#ifndef TRAVELGROUP_H_INCLUDED
#define TRAVELGROUP_H_INCLUDED
#include"Passenger.h"
#include"Ticket.h"
#include"Luggage.h"

typedef void(*operation)(int,Passenger);
class TravelGroup
{
    TravelGroup();
    TravelGroup(Passenger* arr,int n);

    TravelGroup(const TravelGroup& right)

    TravelGroup& operator= (const TravelGroup& other);

    ~TravelGroup();

    int getNumPassenger() const;

    void setStudents(int n, const Student* arr);
    void sortLuggage();
    void fromThisStartstation(const char*)
    void toThisStartstation(const char*)
    void NamePrint(int n);

    void setOperation(operation op)
    {
        this->_op = op;
    }

    void executeOperation() const
    {
        _op(numPassenger,arr);
    }

    void sortPrice();
    void (*getOperation()) (int numPassenger,Passenger* arr)
    {
    return sortPrice();
    }

private:
    void copyTravelGroup(const TravelGroup& other);
    void deleteTravelGroup();

    Passenger* arr;
    int numPassenger;
    operation _op;

};

#endif // TRAVELGROUP_H_INCLUDE


