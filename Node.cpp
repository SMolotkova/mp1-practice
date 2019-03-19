#pragma once
#include "Node.h"
#include <iostream>
#include <math.h>
using namespace std;

Node::Node()
{
    head->kof = 0;
    head->step = 0;
}

Node::Node(Mon* el)
{
    head = el;
}

Node::Node(double _kof, int _step)
{
    head->kof = _kof;
    head->step = _step;
}

Node::Node(Node & tmp)
{
    head = tmp.head;
    Mon* i;
    for (i = tmp.head; i->next != 0; i = i->next)
    {
        Add(i);
    }
}

Node::~Node()
{
    DeleteAll();
}

void Node::Add(Mon* el)
{
    if (!head)
    {
        head = el;
    }
    else
    {
        Mon* i;
        for (i = head; (i->next != 0) && (el->step > i->step); i = i->next) {}
        if (i->step == el->step) i->kof += el->kof;
        else
        {
            Mon * temp = i->next;
            i->next = new Mon(*el);
            i->next->next = temp;
        }
    }
}

void Node::Add(double _kof, int _step)
{
    if (!head) 
    {
        head = new Mon(_kof, _step);
    }
    else 
    {
        Mon* i;
        for(i = head; (i->next != 0) && (_step > i->step); i = i->next) {}
        if (i->step == _step) i->kof += _kof;
        else
        {
            Mon * temp = i->next;
            i->next = new Mon(_kof, _step);
            i->next->next = temp;
        }
    }
}

void Node::Sub(Mon* el)
{
    if (!head)
    {
        head = el;
        head->kof *= (-1);
    }
    else
    {
        Mon* i;
        for (i = head; (i->next != 0) && (el->step > i->step); i = i->next) {}
        if (i->step == el->step) i->kof -= el->kof;
        else
        {
            Mon * temp = i->next;
            i->next = new Mon(*el);
            (i->next)->kof *= (-1);
            i->next->next = temp;
        }
    }
}

void Node::Sub(double _kof, int _step)
{
    _kof *= (-1);
    if (!head)
    {
        head = new Mon(_kof, _step);
    }
    else
    {
        Mon* i;
        for (i = head; (i->next != 0) && (_step > i->step); i = i->next) {}
        if (i->step == _step) i->kof += _kof;
        else
        {
            Mon * temp = i->next;
            i->next = new Mon(_kof, _step);
            i->next->next = temp;
        }
    }
}

void Node::Output()
{
    Mon* i;
    for (i = head; i->next != 0; i = i->next) 
    {
        cout << i->kof << "x^" << i->step << " + ";
    }
    cout << endl;
}

void DeleteAll()
{
    Mon* i = head;
    Mon* del = i;
    while(i!=0)
    {
        i = i -> next;
        delete del;
        del = i;
    }
    head = 0;
}

Node & Input() 
{
    ///////////////////////////////////
}

Node & Node::operator=(Node& tmp)
{
    head = tmp.head;
    Mon* i;
    for (i = tmp.head; i->next != 0; i = i->next)
    {
        Add(i);
    }
    return *this;
}

Node & Node::operator+(double a)
{
    Node* res;
    *res = *this;
    (*res).Add(a, 0);
    return *res;
}

Node & Node::operator+(Mon* tmp)
{
    Node* res;
    *res = *this;
    (*res).Add(tmp);
    return *res;
}

Node & Node::operator+(Node& tmp)
{
    Node* res;
    *res = *this;
    Mon* i;
    for (i = tmp.head; i->next != 0; i = i->next)
    {
        (*res).Add(i);
    }
    return *res;
}

Node & Node::operator-(double a)
{
    Node* res;
    *res = *this;
    (*res).Sub(a, 0);
    return *res;
}

Node & Node::operator-(Mon* tmp)
{
    Node* res;
    *res = *this;
    (*res).Sub(tmp);
    return *res;
}

Node & Node::operator-(Node& tmp)
{
    Node* res;
    *res = *this;
    Mon* i;
    for (i = tmp.head; i->next != 0; i = i->next)
    {
        (*res).Sub(i);
    }
    return *res;
}

Node & Node::operator*(double a)
{
    Node* res = new Node(*this);
    Mon* i;
    for (i = (*res).head; i->next != 0; i = i->next)
    {
        i->kof *= a;
    }
    return *res;
}

Node & Node::operator*(Mon* tmp)
{
    Node* res;
    *res = *this;
    Mon* i;
    for (i = (*res).head; i->next != 0; i = i->next)
    {
        i->kof *= tmp->kof;
        i->step += tmp->step;
    }
    return *res;
}

Node & Node::operator*(Node& tmp)
{
    Node* res = new Node(tmp);
    Mon* i;
    Mon* a;
    for (a = head; a->next != 0; a = a->next)
    {
        for (i = (*res).head; i->next != 0; i = i->next)
        {
            i->kof *= a->kof;
            i->step += a->step;
        }
    }
    return *res;
}

Node & Node::operator/(double a)
{
    Node* res = new Node(*this);
    Mon* i;
    for (i = (*res).head; i->next != 0; i = i->next)
    {
        i->kof /= a;
    }
    return *res;
}

Node & Node::operator/(Mon* tmp)
{
    Node* res;
    *res = *this;
    Mon* i;
    for (i = (*res).head; i->next != 0; i = i->next)
    {
        i->kof /= tmp->kof;
        i->step -= tmp->step;
    }
    return *res;
}

Node & Node::operator/(Node& tmp)
{
    Node* res = new Node(tmp);
    Mon* i;
    Mon* a;
    for (a = head; a->next != 0; a = a->next)
    {
        for (i = (*res).head; i->next != 0; i = i->next)
        {
            i->kof /= a->kof;
            i->step -= a->step;
        }
    }
    return *res;
}

Node & Node::operator+=(double a)
{
    Add(a, 0);
    return *this;
}

Node & Node::operator+=(Mon* tmp)
{
    Add(tmp);
    return *this;
}

Node & Node::operator+=(Node& tmp)
{
    Mon* i;
    for (i = tmp.head; i->next != 0; i = i->next)
    {
        Add(i);
    }
    return *this;
}

Node & Node::operator-=(double a)
{
    Sub(a, 0);
    return *this;
}

Node & Node::operator-=(Mon* tmp)
{
    Sub(tmp);
    return *this;
}

Node & Node::operator-=(Node& tmp)
{
    Mon* i;
    for (i = tmp.head; i->next != 0; i = i->next)
    {
        Sub(i);
    }
    return *this;
}

Node & Node::operator*=(double a)
{
    Mon* i;
    for (i = head; i->next != 0; i = i->next)
    {
        i->kof *= a;
    }
    return *this;
}

Node & Node::operator*=(Mon* tmp)
{
    Mon* i;
    for (i = head; i->next != 0; i = i->next)
    {
        i->kof *= tmp->kof;
        i->step += tmp->step;
    }
    return *this;
}

Node & Node::operator*=(Node& tmp)
{
    Mon* i;
    Mon* a;
    for (a = head; a->next != 0; a = a->next)
    {
        for (i = tmp.head; i->next != 0; i = i->next)
        {
            i->kof *= a->kof;
            i->step += a->step;
        }
    }
    return *this;
}

Node & Node::operator/=(double a)
{
    Mon* i;
    for (i = head; i->next != 0; i = i->next)
    {
        i->kof /= a;
    }
    return *this;
}

Node & Node::operator/=(Mon* tmp)
{
    Mon* i;
    for (i = head; i->next != 0; i = i->next)
    {
        i->kof /= tmp->kof;
        i->step -= tmp->step;
    }
    return *this;
}

Node & Node::operator/=(Node& tmp)
{
    Mon* i;
    Mon* a;
    for (a = head; a->next != 0; a = a->next)
    {
        for (i = tmp.head; i->next != 0; i = i->next)
        {
            i->kof /= a->kof;
            i->step -= a->step;
        }
    }
    return *this;
}