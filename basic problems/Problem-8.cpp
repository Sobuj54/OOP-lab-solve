#include <iostream>
#include <iomanip>
using namespace std;
class FLOAT
{
    float a;
public:
    FLOAT()
    {
        a=0.0;
    }
    FLOAT(float num1);
    FLOAT operator + (FLOAT o);
    FLOAT operator - (FLOAT o);
    FLOAT operator * (FLOAT o);
    FLOAT operator / (FLOAT o);
    void display();
};
FLOAT :: FLOAT(float num1)
{
    a=num1;
}
FLOAT FLOAT :: operator +(FLOAT o)
{
    FLOAT c;
    c.a =a+ o.a;
    return c;
}
FLOAT FLOAT :: operator -(FLOAT o)
{
    FLOAT c;
    c.a =a- o.a;
    return c;
}
FLOAT FLOAT :: operator *(FLOAT o)
{
    FLOAT c;
    c.a =a* o.a;
    return c;
}
FLOAT FLOAT :: operator /(FLOAT o)
{
    FLOAT c;
    c.a =a/ o.a;
    return c;
}
void FLOAT :: display()
{
    cout<<"Result="<<a<<endl;
}
int main()
{
    float f1,f2;
    cout<<"Enter two floating point number:"<<endl;
    cin>>f1>>f2;
    FLOAT o1(f1), o2(f2), o3;
    cout<<"Addition:"<<endl;
    o3=o1+o2;
    o3.display();
    cout<<"Subtraction:"<<endl;
    o3=o1-o2;
    o3.display();
    cout<<"Multiplication:"<<endl;
    o3=o1*o2;
    o3.display();
    cout<<"Division:"<<endl;
    o3=o1/o2;
    o3.display();
    return 0;
}
