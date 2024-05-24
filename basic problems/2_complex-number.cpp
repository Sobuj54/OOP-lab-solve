/*
2. complex number addition.
*/ 

#include <iostream>
using namespace std;

class COMPLEX{
    private: 
        int real, imaginary;
    public:
        COMPLEX(){
            real=imaginary=0;
        };

        COMPLEX(int x, int y){
            real = x;
            imaginary = y;
        };

        void add(COMPLEX c1, COMPLEX c2){
            real = c1.real + c2.real;
            imaginary = c1.imaginary + c2.imaginary;
        };

        void show(){
            cout << "sum is :" << real << "+" << imaginary <<"i"<<endl;
        };
};

int main(){
    int x, y;
    cout<<"enter real number :";
    cin>>x;
    cout<< "enter imaginary number :";
    cin>>y;
    COMPLEX p1(x,y);

    cout<<"enter real number :";
    cin>>x;
    cout<< "enter imaginary number :";
    cin>>y;
    COMPLEX p2(x,y),p3;
    
    p3.add(p1,p2);
    p3.show();
    return 0;
}