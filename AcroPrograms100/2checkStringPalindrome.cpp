#include <iostream>
using namespace std;

bool isStringPalin(string str)
{
    string reverse = str;
    int low = 0;
    int high = str.length() - 1;
    while (low <= high)
    {
        swap(reverse[low], reverse[high]);
        low++;
        high--;
    }
    if (str == reverse)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << boolalpha << isStringPalin("yoogesh") << endl;
}
