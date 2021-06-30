#include <iostream>
using namespace std;

// simple recursive way
int fib(long int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    long int mem[n + 1];
    for (int i = 0; i <= n; i++)
    {
        mem[i] = -1;
    }
    cout << fib(n) << endl;
}