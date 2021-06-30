#include <iostream>
#include <math.h>
using namespace std;

int reverseNumber(int number)
{
    string numStr = to_string(number);
    int i = numStr.length() - 1;
    int rev = 0;
    while (i >= 0)
    {
        rev += pow(10, i) * (numStr[i] - '0');
        i--;
    }
    return rev;
}

int main()
{
    int num;
    cin >> num;
    int reversed = reverseNumber(num);
    cout << reversed << endl;
}