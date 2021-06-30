#include <iostream>
#include <vector>
#include <string>
using namespace std;

// time complexity o(n)
// space complexity O(1)

int main(int, char **)
{
    string str = "yogesh";
    int low = 0;
    int high = str.length() - 1;
    cout << str << endl;
    while (low <= high)
    {
        swap(str[low], str[high]);
        low++;
        high--;
    }
    cout << str << endl;
}
