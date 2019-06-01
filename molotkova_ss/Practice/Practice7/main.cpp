#pragma once
#include <iostream>
#include "Zag.h"
using namespace std;

void main()
{
	Vector a(3);
	cin >> a >> endl;
	cout << " a output" << a << endl;
	Vector b;
	b = a;
	Vector c;
	c = a + b;
	cout << " c = a + b";
	cout << c <<;
	Vector d;
	d = a - b;
	cout << " d = a - b" << d;
	double scal;
	scal = a * b;
	cout << " scal" << scal;
	double leng = d.Length();
	cout << "lengths" << leng;
	*(a[2]) = 5;
	cout << " измененная третья координата";
	cout << a[2] <<endl;
}
