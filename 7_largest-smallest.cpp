/*
7. Largest and smallest
*/

#include <iostream>
using namespace std;

class B;
class A
{
private:
    int x;

public:
    A(int a)
    {
        x = a;
    }
    friend void largest(A a, B b);
    friend void smallest(A a, B b);
};

class B
{
private:
    int y;

public:
    B(int a)
    {
        y = a;
    }
    friend void largest(A a, B b);
    friend void smallest(A a, B b);
};

void largest(A a, B b)
{
    if (a.x > b.y)
    {
        cout << a.x << " is largest" << endl;
    }
    else
    {
        cout << b.y << " is largest" << endl;
    }
}

void smallest(A a, B b)
{
    if (a.x < b.y)
    {
        cout << a.x << " is smallest" << endl;
    }
    else
    {
        cout << b.y << " is smallest" << endl;
    }
}

int main()
{
    int n;
    cout << "enter first value :";
    cin >> n;
    A first(n);

    cout << "enter second value :";
    cin >> n;
    B second(n);

    largest(first, second);
    smallest(first, second);
    return 0;
}