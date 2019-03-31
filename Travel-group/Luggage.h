#ifndef LUGGAGE_H_INCLUDED
#define LUGGAGE_H_INCLUDED

class Luggage
{
public:
     Luggage();
     Luggage(double,double,int);

     void setcapacity(double);
     void setweight(double);
     void setnumber(int);

     double getcapacity()const;
     double getweight()const;
     int getnumber()const;
     int getid()const;

private:
    double _capacity;
    double _weight;
    int _number;
    static int _id;
};


#endif // LUGGAGE_H_INCLUDED
