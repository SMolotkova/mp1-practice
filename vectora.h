#pragma once

class Vector
{
private:
    int size;
    int *arr;
public:
    //�����������
    Vector();
    Vector(int x);
    Vector(int x, int* a);
    Vector(const Vector& vec);
    ~Vector();

    void PrintVector();
};

