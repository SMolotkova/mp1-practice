#pragma once
#include "vectora.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
    size = 0;
    arr = NULL;
}

Vector::Vector(int size)
{
    this->size = size;
    this->arr = new int[size];
    cout << "Enter elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

Vector::Vector(int _size, int *_arr)
{
    size = _size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = _arr[i];
    }
}

Vector::Vector(const Vector& tmp)
{
    size = tmp.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = tmp.arr[i];
    }
}

Vector::~Vector()
{
    size = 0;
    delete[] arr;
}

void Vector::PrintVector()
{
    if (this->size == 0)
    {
        cout << "Array is empty";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

Vector & Vector::operator= (Vector & tmp)
{
    this->size = tmp.size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = tmp.arr[i];
    }
    return *this;
}

Vector & Vector::operator+ (Vector & tmp)
{
    Vector* res = new Vector(tmp);
    for (int i = 0; i < size; i++)
        *res.arr[i] = this->arr[i] + tmp.arr[i];
    return *res;
}