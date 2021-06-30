#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
        return b;
    if (a < b)
        return gcd(a, b - a);
    else
        return gcd(b, a - b);
}

int main()
{
    cout << gcd(5, 3) << endl;
}