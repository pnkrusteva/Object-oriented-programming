#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "People.h"
#include"Student.h"

class Professor: virtual public People
{
    public:
        Professor(const char* name, const char* birthdayDate,const char* specialty,Student* student,int numOfStudent);
        Professor(const Professor& other);
        Professor& operator=(const Professor& other);
        ~Professor();

        void setSpecialty(const char* specialty );
        void setStudent(Student* student);

        char* getSpecialty()const{return _specialty;}
        Student* getStudent()const{return _student;}
        int getNumofStudent()const{return _numOfStudent;}

    private:
        char* _specialty;
        Student* _student;
        int _numOfStudent;
        void copyProf(const Professor&other);
};

#endif // PROFESSOR_H
