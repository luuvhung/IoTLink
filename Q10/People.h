#pragma once
struct Date
{
	int day;
	int month;
	int year;
};
class People
{
protected:
	char* name;
	Date birthday;
	int idcode;
public:
	People();
	People(char*, Date, int);
	virtual ~People();
	int static num;
	void virtual printInfo();
	void setName(char*);
	char* getName();
	void setBirthday(Date);
	Date getBirthday();
	void setIdCode(int);
	int getIdCode();
};

