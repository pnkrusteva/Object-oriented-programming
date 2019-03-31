#include"People.h"

#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
///!!!!!!!Trqbva da definiram kopi i =
class Student:public People
{
public:
    Student(unsigned int facNum=0, int averageGrade=2,const char* name=NULL,const char * birthdayDate=NULL);

    unsigned int getFacNum() const {return _facNum;}
    double getAverageGrade()const {return _averageGrade;}

    void setAverageGrade(double averageGrade);
    void setFacNum(unsigned int facNum);

    void print() const;

private:
    unsigned int _facNum;
    int  _averageGrade;
};
#endif // STUDENT_H
