#pragma once
#include <iostream>
using namespace std;

template <typename T, int maxsize>
class Container1
{
private:
    T* arr;
    int count;
public:
    Container1();
    //Container1(int x);
    Container1(const mContainer& tmp);
    ~Container1();

    bool IsFull()const;
    bool IsEmpty()const;

    int Find(T a)const;
    void Add(T a);
    void Delete(T a);
    T* operator[](int i);
    void Sorting();

    void Print()const;
    void Fill();
};

template <typename T, int maxsize>
Container1<T, maxsize>::Container1()
{
    count = 0;
    arr = new T*[maxsize];
}

//template <typename T, int maxsize>
//Container1<T, maxsize>::Container1(int x)
//{
//    count = x;
//    arr = new T[maxsize];
//}

template <typename T, int maxsize>
Container1<T, maxsize>::Container1(const Container1& tmp)
{
    count = tmp.count;
    arr = new T[maxsize];
    for (int i = 0; i < n; i++)
    {
        arr[i] = tmp.arr[i];
    }
}

template <typename T, int maxsize>
Container1<T, maxsize>::~Container1()
{
    delete arr;
    count = 0;
}

template <typename T, int maxsize>
bool Container1<T, maxsize>::IsFull()const
{
    if (count == maxsize) 
	{cout<<"Full"<<endl;
	return true;}
	else 
	{cout <<"Empty"<<endl;
	return false;}
}

template <typename T, int maxsize>
bool Container1<T, maxsize>::IsEmpty()const
{
    if (count == 0)
	{cout << "Empty" << endl;
	return true;}
	else return false;
}

template <typename T, int maxsize>
int Container1<T, maxsize>::Find(T a)const
{
    for (int i = 0; i < count; i++)
        if (arr[i] == a)
		{ return i;
		cout << "Index of element is "<< i <<endl;}
	esle
	{
	cout << "Element does not exist"<<endl;
	return -1;
	}	
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Add(T a)
{
    try
    {
        if (this->IsFull())
            throw 1;
        count++;
        arr[count - 1] = a;
    }
	catch (1)
	{cout << "Array is full!";}
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Remove(T a)
{
    try
    {
        if (this->IsEmpty())
            throw 2;
        int j = Find(a);
        if (j == -1)
            throw 3 ;
        arr[j] = arr[count - 1];
        count--;
    }
	catch(int i)
	{
		switch(i)
		{
		case 2:
			cout << "Empty" << endl;
            break;
		case 3:
			cout << "Element does not exist" << endl;
            break;
		}
	}
}

template <typename T, int maxsize>
T* Container1<T, maxsize>::operator[](int i)
{
    try
    {
        if ((i < 0) || (i >= count))
            throw 3;
        return &(arr[i]);
    }
	catch (int i)
	{
	switch (i)
	{
	case 3:
            cout << "Element does not exist" << endl;
            break;
	}
	}
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Print()const
{
    try
    {
        if (this->IsEmpty())
            throw 2;
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    catch (int i)
    {
        switch (i)
        {
        case 2:
            cout << "Empty" << endl;
            break;
		}
    }
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Fill()
{
    try
    {
        if (this->IsEmpty())
            throw 2;
        for (int i = 0; i < count; i++)
        {
            cin >> arr[i];
        }
    }
    catch (int i)
    {
        switch (i)
        {
        case 2:
            cout << "Empty" << endl;
            break;
        }
    }
}

template <typename T, int maxsize>
void Container1<T, maxsize>::Sort()
{
    try
    {
        if (this->IsEmpty())
            throw 1;
        int i, j, tmp;
        for (i = 1; i < count; i++)
        {
            tmp = arr[i];
            j = i - 1;
            while ((j >= 0) && (arr[j] > tmp))
            {
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
    }
    catch (int i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
} 