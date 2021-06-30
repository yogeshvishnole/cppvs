#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "After reverese : " << endl;
    cout << a << " " << b << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << "Before reverese : " << endl;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << "After reverese : " << endl;
    cout << a << " " << b << endl;
}