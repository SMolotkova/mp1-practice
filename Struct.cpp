#include "Header.h"

#include <iostream>

using namespace std;
Vector* Constr(int size)
{
	Vector* a = new Vector;
	a->size = size;
	a->arr = new double[size];

	cout << "Enter elements" << endl;

	for (int i = 0; i < size; i++)

	{
		cin >> arr[i];
	}
	return a;
}
