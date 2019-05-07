#pragma once
#include <iostream>
using namespace std; 

template <typename T, int maxsize>
class Container  
{
private :
	T** array;
	int n;
public: 
	Container();
	Cintainer(int x);
	Contaainer(const Container& tmp);
	~Container();

	bool IsFull()const;
	bool IsEmpty()const;

	int Find(T a)const;
	void Add(T a);
	void Remove(T a);
	T* operator [] (int i);
	void Sorting();

	void Print() const;
	void Fill();
};
template <typename T, int maxsize>
Container <T, maxsize> ::Container(int x)
{
	n = x;
	arr = new T*[maxsize];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new T;
		*arr[i] = tmp.*arr[i];
	}
}
template <typename T, int maxsize>
Container <T, maxsize> ::Container()
{
	n = 0;
	arr = new T*[maxsize];
}
template <typename T, int maxsize>
Container <T, maxsize> ::Container(const Container& tmp)
{
	n = tmp.n;
	arr = new T*[maxsize];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new T;
		*arr[i] = tmp.*arr[i];
	}
}
template <typename T, int maxsize>
Container <T, maxsize> ::~Container()
{
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	delete arr; 
	n = 0;
}
template <typename T, int maxsize>
Container <T, maxsize> :: IsF()