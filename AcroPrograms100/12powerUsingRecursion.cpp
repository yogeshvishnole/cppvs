#include <iostream>
using namespace std;

int powFact(int n, int exp)
{
    if (exp < 0)
    {
        return -1;
    }
    if (exp == 0)
    {
        return 1;
    }
    return n * powFact(n, exp - 1);
}

int main(int argc, char **argv)
{
    cout << powFact(5, 3) << endl;
}