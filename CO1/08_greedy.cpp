#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {4, 3, 2, 1, 1};
    int t = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n); 

    int count = 0;
    int tempsize = 0;

    for (int i = 0; i < n; i++)
    {
        if (tempsize + arr[i] <= t)
        {
            tempsize = tempsize + arr[i];
            count++;
        }
        else
        {
            break;
        }
    }
    cout << count;

    return 0;
}
