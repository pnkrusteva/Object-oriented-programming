#include "Professor.h"
#include "Student.h"
#include<iostream>
#include<string.h>

Professor::Professor(const char* name, const char* birthdayDate,const char* specialty,Student* student, int numOfStudent):People(name,birthdayDate),_specialty(NULL), _student(NULL)
{
    if(numOfStudent<0)
        throw "The number of student should be positive!";
    this->_numOfStudent=numOfStudent;
    setSpecialty(specialty);
    setStudent(student);
}

Professor::Professor(const Professor& other):People(other)
{
    copyProf(other);
}
Professor& Professor::operator=(const Professor& other)
{
    if(this!=&other)
    {
        People::operator=(other);
        copyProf(other);
    }
    return *this;
}
Professor::~Professor()
{
    delete []_specialty;
    delete []_student;
    this->_specialty=NULL;
    this-> _student=NULL;

}

void Professor::setSpecialty(const char* specialty )
{
    int len = strlen(specialty);

	if (len==0)
		throw "The specialty cannot be empty!";

	delete[] this->_specialty;
	this->_specialty = new char[len + 1];
	strcpy(this->_specialty, specialty);
}
void Professor::setStudent(Student* student)
{
    delete[] this->_student;
	this->_student = new Student[_numOfStudent];
	for(int i=0;i<_numOfStudent;i++)
        this->_student[i]=student[i];
}

void Professor::copyProf(const Professor&other)
{
    this->_specialty=NULL;
    this-> _student=NULL;
    setSpecialty(other._specialty);
    setStudent(other._student);
}
