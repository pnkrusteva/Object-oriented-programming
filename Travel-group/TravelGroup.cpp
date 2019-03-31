#include<iostream>
#include"TravelGroup.h"
#include"Passenger.h"
#include"Luggage.h"
#include"Ticket.h"

TravelGroup::TravelGroup(): arr(NULL), numPassenger(0)
{
}

TravelGroup::TravelGroup(Passenger* arr,int n):arr(NULL), numPassenger(0)
{
     this->arr = new Passeger[numPassenger];
   for (int i = 0; i < numPassenger; ++i)
   {
       this->arr[i] = arr[i];
   }
}

TravelGroup::TravelGroup(const TravelGroup& right) : arr(NULL)
{
   copyTravelGroup(right);
}

TravelGroup::TravelGroup& TravelGroup::operator= (const TravelGroup& other)
{
    if (this != &other)
    {
        deleteTravelGroup();
        copyTravelGroup(other);
    }
    return *this;
}
void TravelGroup:: copyTravelGroup(const TravelGroup& other)
{
   this->numPassenger = other.numPassenger;

   this->arr = new Passenger[numPassenger];
   for (int i = 0; i < numPassenger; ++i)
   {
       this->arr[i] = other.arr[i];
   }
}

void TravelGroup::deleteTravelGroup()
{
   delete [] arr;
   arr = NULL;
}
TravelGroup::~TravelGroup()
{
    deleteTravelGroup();
}
int TravelGroup::getNumStudents() const
{
    return numPassenger;
}

void TravelGroup::setStudents(int n, const Student* arr)
{
   delete [] this->arr;

   this->numPassenger = n;
   this->arr = new Passenger[n];

   for (int i = 0; i < n; ++i)
   {
      this->arr[i] = arr[i];
   }
}
void TravelGroup::sortLuggage()
{
    for(int i=0;i<getNumStudents()-1;++i)
    {
        int min1=arr[i].getLuggage().getweight();
        int k=i;
        for(int j=i+1;j<getNumStudents();j++)
            if(arr[j].getLuggage().getweight()<min1)
        {
            min1=arr[j].getLuggage().getweight();
            k=j;
        }
        Passenger x=arr[i];
        arr[i]=arr[k];
        arr[k]=x;

    }
}

void TravelGroup::fromThisStartstation(const char* str)
{
    for(int i=0;i<getNumStudents();++i)
        if(!strcmp(arr[i].getTicket().getstartStation()))
        cout<<arr[i].getName()<<endl;
}
void TravelGroup::toThisStartstation(const char* str)
{
    for(int i=0;i<getNumStudents();++i)
        if(!strcmp(arr[i].getTicket().getdestination()))
        cout<<arr[i].getName()<<endl;
}
 void  TravelGroup::NamePrint(int n=0)
 {
     if(n==getNumStudents())return;
     cout<<arr[n].getName()<<endl;
     NamePrint(n+1);
 }

 void TravelGroup::sortPrice()
 {
    for(int i=0;i<getNumStudents()-1;++i)
    {
        int min1=arr[i].getLuggage().getPrice();
        int k=i;
        for(int j=i+1;j<getNumStudents();j++)
            if(arr[j].getLuggage().getPrice()<min1)
        {
            min1=arr[j].getLuggage().getPrice();
            k=j;
        }
        Passenger x=arr[i];
        arr[i]=arr[k];
        arr[k]=x;
        cout<<arr[i].getName()<<endl;
    }
}

