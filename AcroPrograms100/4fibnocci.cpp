#include <iostream>
using namespace std;

// simple recursive way
int fib(long int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// recursive memoization
int fibMemRec(long int n, int *mem)
{
    if (n == 0 || n == 1)
        return n;
    if (mem[n] != -1)
    {
        return mem[n];
    }
    int ans = fibMemRec(n - 1, mem) + fibMemRec(n - 2, mem);
    mem[n] = ans;
    return ans;
}

// interative memoization
long long int fibIter(int n)
{
    long long int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
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
    cout << fibIter(n) << endl;
}