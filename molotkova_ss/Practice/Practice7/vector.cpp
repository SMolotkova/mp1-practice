#pragma once
#include <iostream>
#include "Zag.h"
using namespace std;

Vector::Vector(int n)
{
	this -> n = n;
	x = new double[n];
}
Vector::Vector(const Vector& v)
{
	n = v.n;
	x = new double[v.n];
	for(int i = 0; i < v.n; i++)
		x[i] = v.x[i];
}
Vector::~Vector()
{
	delete[]x;
	n = 0;
}
Vector Vector::operator+ (const Vector& v) const
{
	if(v.n != n)
		throw "Не совпадают размерности";
	Vector res(v);
	for (int i = 0; i < n; i++)
		res.x[i] += x[i];
	return res;

}
Vector Vector::operator- (const Vector& v) const
{
	if(v.n != n)
		throw "не совпали размеры";
	Vector res(v);
	for (int i = 0; i < n; i++)
		res.x[i] -= x[i];
	return res;
}
double Vector::operator* (const Vector& v) const
{
	if(v.n != n)
		throw "размерности";
	double scal = 0;
	for(int i = 0; i < n; i++)
		scal += x[i] * v.x[i];
	return scal;
}
Vector Vector::operator+ (double a) const 
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] += a;
	return res;
}
Vector Vector::operator- (double a) const
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] -= a;
	return res;
}
Vector Vector::operator* (double a) const 
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] *= a;
	return res;
}
bool Vector::operator==(const Vector & v) const
{
    if (n != v.n) 
	    return false;
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (x[i] != v.x[i]) 
		flag = 1;
    }
    if (flag == 1) 
	    return false;
    return true;
}
Vector Vector::operator= (const Vector& v) 
{       if(*this  == v)
		return;
	delete[] x;
	n = v.n;
	x = new double[v.n];
	for(int i = 0; i < v.n; i++)
		x[i] = v.x[i];
	return *this;
}
double Vector::Length() const
{
	double result = 0;
	for (int i = 0; i < n; i++)
		result += x[i] * x[i];
	result = sqrt(result);
	return result;
}
Vector Vector::operator+= (const Vector& v)
{
	if(v.n != n)
		throw "Error";
	for (int i = 0; i < n; i++)
		x[i] += v.x[i];
	return *this;
}
Vector Vector::operator-= (const Vector& v)
{
	if(v.n != n)
		throw "Error";
	for (int i = 0; i < n; i++)
		x[i] -= v.x[i];
	return *this;
}
Vector Vector::operator+= (double a)
{
	for (int i = 0; i < n; i++)
		x[i] += a;
	return *this;
}
Vector Vector::operator-= (double a)
{
	for (int i = 0; i < n; i++)
		x[i] -= a;
	return *this;
}
Vector Vector::operator*= (double a)
{
	for (int i = 0; i < n; i++)
		x[i] *= a;
	return *this;
}


double& Vector::operator[](int index)
{
    if ((index < 0) || (index >= n))
        throw "Not correct index!";

    return x[index];
}

const double& Vector::operator[](int index) const
{
    if ((index < 0) || (index >= n))
        throw "Not correct index!";

    return x[index];
}
istream& operator>> (istream& input, Vector& v)
{
    for (int i = 0; i < v.n; i++)
        input >> v.x[i];

    return input;
}

ostream& operator<< (ostream &output, const Vector& v)
{
    if (v.n == 0)
    {
        output << "Empty";
        return output;
    }

    output << "(";

    for (int i = 0; i < v.n; i++)
    {
        if (i != v.n - 1)
            output << v[i] << ", ";
        else
            output << v[i] << ")";
    }

    return output;
}
