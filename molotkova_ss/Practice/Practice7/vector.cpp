#pragma once
#include <iostream>
#include "Zag.h"
using namespace std;

Vector::Vector()//consructor �� ���������
{
	n = 0;// ������ �������
	x = NULL;//����������
}
Vector::Vector(int n)//����������� � �����������
{
	this -> n = n;
	x = new double[n];
}
Vector::Vector(const Vector& v)//����������� �����������
{
	n = v.n;
	x = new double[v.n];
	for(int i = 0; i < v.n; i++)
		x[i] = v.x[i];
}
Vector::~Vector()// destructor
{
	delete[]x;
	n = 0;
}
Vector Vector::operator+ (const Vector& v) const //�������� ��������
{
	if(v.n != n)
		throw "�� ��������� �����������";
	Vector res(v);//����� ����������� �����������
	for (int i = 0; i < n; i++)
		res.x[i] += x[i];
	return res;

}
Vector Vector::operator- (const Vector& v) const
{
	if(v.n != n)
		throw "�� ������� �������";
	Vector res(v);
	for (int i = 0; i < n; i++)
		res.x[i] -= x[i];
	return res;
}
double Vector::operator* (const Vector& v) const//��������� ������������
{
	if(v.n != n)
		throw "�����������";
	double scal = 0;
	for(int i = 0; i < n; i++)
		scal += x[i] * v.x[i];
	return scal;
}
Vector Vector::operator+ (double a) const //����������� ���������
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] += a;
	return res;
}
Vector Vector::operator- (double a) const//��������� ���������
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] -= a;
	return res;
}
Vector Vector::operator* (double a) const //��������� �� �����
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] *= a;
	return res;
}
Vector Vector::operator= (const Vector& v) 
{
	delete[] x;
	n = v.n;
	x = new double[v.n];
	for(int i = 0; i < v.n; i++)
		x[i] = v.x[i];
	return *this;
}
double* Vector::operator[] (int index) const
{
	if ((index < 0) || (index >= n))
		throw "Error";
	return &(x[index]);
}
double Vector::Length()
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
// new delete catch
void Vector::Output()
{
	if (n <= 0)
		throw "������";
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}
void Vector::Input()
{
	if (n <= 0)
		throw "������";
	for (int i = 0; i < n; i++)
		cin >> x[i];
}