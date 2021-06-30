#include <iostream>
using namespace std;

// method1 time complexity logn
int countSetBits1(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
            cnt++;
        n = n >> 1;
    }
    return cnt;
}

// method2 time complexity O(no of set bits)

int countSetBits2(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countSetBits1(n) << " " << countSetBits2(n) << endl;
    }
}