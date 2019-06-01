#pragma once
#include <iostream>
#include "Zag.h"
using namespace std;

void main()
{
	Vector a(3);
	cin >> a;
	cout << " a output" << a << endl;
	Vector b(a);
	b = a;
	Vector c(3);
	c = a + b;
	cout << " c = a + b";
	cout << c;
	Vector d(3);
	d = a - b;
	cout << " d = a - b" << d;
	double scal;
	scal = a * b;
	cout << " scal" << scal;
	double leng = d.Length();
	cout << "lengths" << leng;
	a[2] = 5;
	cout << " измененная третья координата";
	cout << a[2] <<endl;
}
