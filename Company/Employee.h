#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    public:

        Employee(const char* name,int internship);
        Employee(const Employee& other);
		Employee& operator=(const Employee& right);
		virtual ~Employee();

        virtual double getSalary()const;
        const char* getName() const;
        int getInternship()const;

        void setInternship(int internship);
		void setName(const char* name);
		virtual Employee* clone() const { return new Employee(*this);}

    protected:

    private:

        void copyEmployee(const Employee& other);

        char* _name;
        int _internship;
};

#endif // EMPLOYEE_H
