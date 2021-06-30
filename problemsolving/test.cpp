#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void frequencyCount(vector<int> &arr, int N, int P)
{

    int i = 0;
    while (i < N)
    {
        if (arr[i] > 0)
        {

            int x = arr[i] - 1;
            if (arr[x] > 0)
            {
                if (i < x)
                {
                    swap(arr[x], arr[i]);
                }else{
                    i++;
                }

                arr[x] = -1;
            }
            else
            {
                arr[x]--;
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > 0)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = arr[i] * -1;
        }
    }
}

int main()
{
    vector<int> arr = {3, 2, 2, 2, 1};
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    frequencyCount(arr, arr.size(), 3);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}