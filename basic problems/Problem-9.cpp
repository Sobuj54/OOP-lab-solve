#include <bits/stdc++.h>
using namespace std;
class area_cl
{
public:
    double height;
    double width;
};
class rectangle : public area_cl
{
public:
    rectangle(double h, double w)
    {
        height = h;
        width = w;
    }
    double area()
    {
        double result = (height * width);
        return result;
    }
};
class isosceles : public area_cl
{
public:
    isosceles(double h, double w)
    {
        height = h;
        width = w;
    }
    double area()
    {
        double a;
        a = 0.5 * (height * width);
        return a;
    }
};

int main()
{
    rectangle r1(5.5, 7.3);
    double result;
    result = r1.area();
    cout << "The area of a rectangle is: " << setprecision(4) << result << endl;
    isosceles i(5.7, 7.4);
    result = i.area();
    cout << "The area of an isosceles triangle is: " << fixed << setprecision(4) << result << endl;
    return 0;
}
