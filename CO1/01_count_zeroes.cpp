/*
Problem 1: Count the number of zeroes in a sorted binary array.
Statement: Given an array of 1s and 0s where all 1s appear first 
           followed by all 0s, find the total number of 0s in the array.

Approach: Use Binary Search to find the first occurrence of 0 in the sorted array. 
          The number of zeroes will be equal to (size of array - index of first 0). 
          Input validation ensures only 0s and 1s are entered.

Input (Only 0s and 1s, sorted): 1 1 1 0 0 0
Output: 3
*/

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
