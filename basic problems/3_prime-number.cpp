/*
3. prime or not using class
*/

#include <iostream>
using namespace std;

class prime
{
private:
    int n;

public:
    prime(int x)
    {
        n = x;
    };
    void isPrime();
};

void prime ::isPrime()
{
    int flag = 0;

    if (n == 0 || n == 1)
    {
        flag = 1;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag++;
            break;
        }
    }

    if (flag == 0)
    {
        cout << n << " is prime" << endl;
    }
    else
    {
        cout << n << " is not prime" << endl;
    }
}

int main()
{
    int n;
    cout << "enter a number :";
    cin >> n;
    prime p(n);
    p.isPrime();
    return 0;
}