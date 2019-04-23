#pragma once
#include "Time.h"
#include"Date.h"

class Tasks 
{
public:
	Tasks();
	virtual ~Tasks();
	virtual void Print()const = 0;
	//virtual const Tasks& operator=(const Tasks& t);
	Date GetDate()const {
		return date;
	};
protected:
	char* description;
	Date date;
};

class Type1: public Tasks
{
public:
	Type1();
	Type1(char* description, Date date);
	~Type1();
	void Print()const;
	const Type1& operator= (const Type1& t);
};

class Type2: public Tasks
{
private:
	unsigned duration;
	Time time;
public:
	Type2();
	Type2(char* description, Date date, unsigned duration, Time time);
	~Type2();
	void Print()const;
	const Type2& operator= (const Type2& t);
};

