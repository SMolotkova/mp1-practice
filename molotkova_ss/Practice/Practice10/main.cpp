#pragma once
#include <iostream>
#include "Container1.h"
#include "Container2.h"
#define MAXSIZE 5
using namespace std;

void main()
{
	cout << "Container1" << endl;
	int count;
	cout << "Count = ";
	cin >> count;
	Container1<int> Container_1(MAXSIZE);
	cout << "Container1(Fill) = " << endl;
	try 
	{
		Container_1.Fill(count);//FILLING
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	Container_1.Print();//OUTPUT
	Container1<int> COPYContainer_1(Container_1);
	COPYContainer_1.Add(5);
	COPYContainer_1.Print();
	COPYContainer_1.Add(12);
	COPYContainer_1.Print();
	try
	{
		COPYContainer_1.Fill(0);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	COPYContainer_1.IsEmpty();
	try
	{ 
		Container_1.Delete(4);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}



	cout << "Container2" << endl;
	int count;
	cout << "Count = ";
	cin >> count;
	Container1<int*> Container_2(MAXSIZE);
	cout << "Container2(Fill) = " << endl;
	try
	{
		Container_2.Fill(count);//FILLING
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	Container_2.Print();//OUTPUT
	Container1<int*> COPYContainer_2(Container_2);
	int a = 5;
	COPYContainer_2.Add(&a);
	COPYContainer_2.Print();
	int b = 12;
	COPYContainer_2.Add(&b);
	COPYContainer_2.Print();
	try
	{
		COPYContainer_2.Fill(0);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	COPYContainer_2.IsEmpty();
	try
	{
		Container_2.Delete(4);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}

