git push origin main
#include<iostream>
using namespace std;

int main(){
    int size, a[20], count = 0;
    cout << "Enter ARRAY size: ";
    cin >> size;

    // Input array elements with validation (0 or 1 only)
    cout << "Enter ARRAY elements (0 and 1 only, sorted):\n";
    for(int i = 0; i < size; i++){
        int val;
        while (true) {
            cout << "Enter " << i << " Element: ";
            cin >> val;
            if (val == 0 || val == 1) {
                a[i] = val;
                break;
            } else {
                cout << "Invalid input! Please enter 0 or 1 only.\n";
            }
        }
    }

    int low = 0, high = size - 1, mid;
    int firstzero = -1;

    // Binary search for the first 0
    while(low <= high){
        mid = (low + high) / 2;
        if(a[mid] == 0){
            firstzero = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Count the number of 0s
    if(firstzero != -1){
        count = size - firstzero;
    }

    cout << "The total 0s in this array are: " << count;
    return 0;
}
