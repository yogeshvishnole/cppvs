#include <iostream>
using namespace std;

bool isIthSet(int n, int i)
{
    int f = 1;
    f = f << i;
    return f & n;
}

int main(int, char **)
{

    // left shift ( equivaent to multipy by 2)
    // n << i === n *(2^i)

    // right shift ( equivalent to divide by 2)

    // n >> i === n/ (2^i)

    cout << boolalpha << isIthSet(2, 0) << endl;
}
