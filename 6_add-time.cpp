/*
6. add time minutes and hours
*/

#include <iostream>
using namespace std;

class Time
{
private:
    int hour, min;

public:
    void get_time()
    {
        int h, m;
        cout << "enter hour and minute :";
        cin >> h >> m;
        hour = h;
        min = m;
    }

    void add_time(Time t1, Time t2)
    {
        min = t1.min + t2.min;
        hour = t1.hour + t2.hour + (min / 60);
        min = min % 60;
    }

    void display()
    {
        cout << "total time = " << hour << "h " << min << "min" << endl;
    }
};

int main()
{
    Time a, b, c;
    a.get_time();
    b.get_time();
    c.add_time(a, b);
    c.display();
    return 0;
}