#pragma once
#include "vectora.h"
#include <iostream>
using namespace std;

int main()
{
    int i;
    int *elem = new int[10];
    for (i = 0; i < 10; i++)
        elem[i] = i;

    Vector* v1 = new Vector();
    Vector* v2 = new Vector(10);
    Vector* v3 = new Vector(10, elem);
    Vector* v4 = new Vector(v3);
    v3->PrintVector();
    v2->PrintVector();
    v1->PrintVector();
    v4->PrintVector();

    cin >> i;    return 0;
}