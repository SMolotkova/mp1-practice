#pragma once

struct Mon
{
    double kof;
    int step;
    Mon* next;
    Mon(double _kof, int _step)
    {
        kof = _kof;
        step = _step;
        next = 0;
    }
    Mon(Mon* tmp)
    {
        kof = tmp->kof;
        step = tmp->step;
        next = 0;
    }
};
class Node
{
private:
    Mon *head;

public:
    Node();
    Node(Mon* el);
    Node(double _kof, int _step);
    Node(Node& tmp);
    ~Node();
    void Add(double _kof, int _step);
    void Add(Mon* el);
    void Sub(double _kof, int _step);
    void Sub(Mon* el);
    void Output();
    void DeleteAll();
    Node & Input();

    //операторы + - / *
    Node & operator+(double a);
    Node & operator+(Mon* tmp);
    Node & operator+(Node& tmp);
    Node & operator-(double a);
    Node & operator-(Mon* tmp);
    Node & operator-(Node& tmp);
    Node & operator*(double a);
    Node & operator*(Mon* tmp);
    Node & operator*(Node& tmp);
    Node & operator/(double a);
    Node & operator/(Mon* tmp);
    Node & operator/(Node& tmp);
    Node & operator+=(double a);
    Node & operator+=(Mon* tmp);
    Node & operator+=(Node& tmp);
    Node & operator-=(double a);
    Node & operator-=(Mon* tmp);
    Node & operator-=(Node& tmp);
    Node & operator*=(double a);
    Node & operator*=(Mon* tmp);
    Node & operator*=(Node& tmp);
    Node & operator/=(double a);
    Node & operator/=(Mon* tmp);
    Node & operator/=(Node& tmp);   

    Node & operator=(Node& tmp);
};