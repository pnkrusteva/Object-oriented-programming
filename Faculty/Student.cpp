#include "Student.h"
#include<iostream>
#include"People.h"

using namespace std;

Student::Student(unsigned int facNum, int averageGrade,const char* name,const char * birthdayDate):People(name,birthdayDate)
 {
    setAverageGrade(averageGrade);
    setFacNum(facNum);
 }

void Student::setAverageGrade(double averageGrade)
{
    if(averageGrade<2||averageGrade>6)
        throw "The average grade is not valid!";

    this->_averageGrade=averageGrade;
}

void Student::setFacNum(unsigned int facNum)
{
    this->_facNum=facNum;
}

void Student::print() const
{
    People::print();
    cout<<"The average grade: "<<this->_averageGrade<<endl;
    cout<<"The faculty number: "<<this->_facNum<<endl;
}
