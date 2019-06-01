#pragma once
#include <iostream>
#include "Zag.h"
using namespace std;

void main()
{
	Vector a(3);
	a.Input();
	cout << " a output";
	a.Output();
	Vector b;
	b = a;
	cout << " b = a" << " " << " b output";
	b.Output();
	Vector c;
	c = a + b;
	cout << " c = a + b";
	c.Output();
	Vector d;
	d = a - b;
	cout << " d = a - b";
	d.Output();
	double scal;
	scal = a * b;
	cout << " scal" << scal;
	double leng = d.Length();
	cout << "lengths" << leng;
	*(a[2]) = 5;
	cout << " измененная третья координата";
	a.Output();
}
