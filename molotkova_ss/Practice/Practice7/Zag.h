#pragma once
#include <iostream>
using namespace std;


class Vector
{
private:
	int n;
	double *x;

public:
	Vector(int n);
	Vector(const Vector& v);
	~Vector();
	Vector operator- (const Vector& v) const;
	Vector operator+ (const Vector& v) const;
	double operator* (const Vector& v) const;
	Vector operator+ (double a) const;
	Vector operator- (double a) const;
	Vector operator* (double a) const;
	Vector operator= (const Vector& v);
	bool operator==(const Vector & v) const;
	double Length() const;
	Vector operator+= (const Vector& v);
	Vector operator-= (const Vector& v);
	Vector operator+= (double a);
	Vector operator-= (double a);
	Vector operator*= (double a);
	
	double& operator[](int);
    	const double& operator[](int) const;
	friend istream& operator>> (istream& input, Vector& v);
        friend ostream& operator<< (ostream& output, const Vector& v); 
};
