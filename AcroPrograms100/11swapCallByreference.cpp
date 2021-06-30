#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
    cout << "Inside swap function: "
         << "x : " << x << " "
         << "y : " << y << endl;
}

int main()
{
    int x = 10;
    int y = 20;
    cout << "Befor swap function: "
         << "x : " << x << " "
         << "y : " << y << endl;
    swap(x, y);
    cout << "After swap function: "
         << "x : " << x << " "
         << "y : " << y << endl;
}