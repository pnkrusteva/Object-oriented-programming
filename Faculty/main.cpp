#include <iostream>
#include "People.h"
#include "Student.h"
#include "Employee.h"
#include "Professor.h"
#include "Dean.h"
#include<string.h>

using namespace std;

Student HighestAverageGrade(Professor p)
{
    double max=p.getStudent()[0].getAverageGrade();
    Student s=p.getStudent()[0];

    for(int i=1;i<p.getNumofStudent();i++)
    {
        if(p.getStudent()[i].getAverageGrade()>max)
           {
               max=p.getStudent()[i].getAverageGrade();
               s=p.getStudent()[i];
           }
    }
    return s;
}

bool isItDeanInArrayOfProfessors(const Professor* p,Dean d,int numOfProf)
{

    for(int i=0;i<numOfProf;i++)
    {   bool help=true;
        if(!strcmp(p[i].getName(),d.getName())==0||!strcmp(p[i].getBirthdayDate(),d.getBirthdayDate())==0||!strcmp(p[i].getSpecialty(),d.getSpecialty())==0||!p[i].getNumofStudent()==d.getNumofStudent()||!p[i].getNumofStudent()==d.getNumofStudent())
            help=false;

        for(int j=0;j<p[i].getNumofStudent()&&help;j++)
        {
            help=false;
            for(int k=0;k<p[i].getNumofStudent()&&!help;k++)
            {
                help=p[i].getStudent()[j].getFacNum()==d.getStudent()[k].getFacNum();
            }
        }
    }
    return help;
}
int main()
{
    People p("ivan","20160228");
    Student s(80000,6,"Pet","19981201");
    cout << "Hello world!" << endl;
    return 0;
}
