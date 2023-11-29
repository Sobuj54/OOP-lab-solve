/*
1. Find factorial using constructor.
*/ 

#include <iostream>
using namespace std;

class factorial{
    private:
        int n,fact;
    public:
        factorial(int num);
        void display();
};

factorial :: factorial(int num){
    n=num;
    fact=1;
    for(int i=n; i>0; i--){
        fact *= i;
    }
}

void factorial :: display(){
    cout<<"factorial of "<<n <<" is "<<fact<<endl;
}

int main(){
    int n;
    cout << "Enter the number :";
    cin >> n;
    factorial f(n);
    f.display();
    return 0;
}