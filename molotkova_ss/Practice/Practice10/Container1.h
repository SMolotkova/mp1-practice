#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Container1
{
private:
    T* arr;
    int count;//real number of elemnts
    int maxsize;
    void Adding(int add);
public:
    Container1();
    Container1(int count);
    Container1(const Container1& tmp);
    ~Container1();

    bool IsFull()const;
    bool IsEmpty()const;

    int Find(T a)const;
    void Add(T a);
    void Delete(T a);
	T& operator[](int i);//input
	const T& operator[](int i)const;//reading

    void Print()const;
    void Fill(int count);
};

template <typename T>
Container1<T>::Container1()
{
    count = 0;
    maxsize = 0;
}

template <typename T>
Container1<T>::Container1(int maxsize)
{
    this->maxsize = maxsize;
	count = 0;
    arr = new T[maxsize];
}

template <typename T>
Container1<T>::Container1(const Container1& tmp)
{
    count = tmp.count;
	maxsize = tmp.maxsize;
    arr = new T[maxsize];
    for (int i = 0; i < count; i++)
    {
        arr[i] = tmp.arr[i];
    }
}

template <typename T>
Container1<T>::~Container1()
{
    delete arr;
    count = 0;
	maxsize = 0;
}

template <typename T>
bool Container1<T>::IsFull()const
{
    if (count == maxsize) 
	{
		cout<<"Full"<<endl;
		return true;
	}
	else 
	{
		cout <<"Is not full"<<endl;
		return false;
	}
}

template <typename T>
bool Container1<T>::IsEmpty()const
{
    if (count == 0)
	{
		cout << "Empty" << endl;
		return true;
	}
	else 
		return false;
}

template <typename T>
int Container1<T>::Find(T a)const
{
    for (int i = 0; i < count; i++)
	{
        if (arr[i] == a)
		{ 
			cout << "Index of element is "<< i <<endl;
			return i;
		}
		else
		{
			cout << "Element does not exist"<<endl;
			return -1;
		}	
	}
}

template <typename T>
void Container1<T>::Add(T a)
{
	if (this->IsFull())
		this->Adding(1);
   arr[count++] = a;
}

template <typename T>
void Container1<T>::Delete(T a)
{
        if (this->IsEmpty())
            throw "Container is empty";
        int j = Find(a);
        if (j == -1)
            throw "Element does not exist" ;
        arr[j] = arr[--count];
}

template <typename T>
T& Container1<T>::operator[](int i)
{
	if ((i < 0) || (i >= count))
		throw "Element does not exist";
	return arr[i];
}
template <typename T>
const T& Container1<T>:: operator[](int i)const
{
	if ((i < 0) || (i >= count))
		throw "Element does not exist";
	return arr[i];
}

template <typename T>
void Container1<T>::Print()const
{
	for (int i = 0; i < count; i++)
    {
		cout << arr[i] << " ";
    }
	cout << endl;  
}

template <typename T>
void Container1<T>::Fill(int count)
{
	this->count = count;
        if (this->IsEmpty())
            throw "Container is empty";
        for (int i = 0; i < count; i++)
        {
            cin >> arr[i];
        } 
}
template <typename T>
void Container1<T>::Adding(int add)
{
	maxsize += add;
	T* newarr = new T[maxsize];
	for (int i = 0; i < count; i++)
		newarr[i] = arr[i];
	arr = newarr;
}
