#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
    public:
        People(const char* name, const char* birthdayDate);
		People(const People&);
		People& operator=(const People&);
		~People();

		const char* getName() const{ return this->_name; }
		const char* getBirthdayDate() const{ return this->_birthdayDate; }

		void setName(const char* name);
		void setBirthdayDate(const char *birthdayDate);

		void print() const;
    private:
        char* _name;
        char _birthdayDate[9];
};

#endif // PEOPLE_H
