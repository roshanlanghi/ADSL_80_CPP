/*
Problem 2: Move all zeroes to the end of an array.
Statement: Given an array of random numbers, push all zeroes to the end 
           while maintaining the relative order of the non-zero elements.

Approach : Apply Merge Sort manually and then push all 0s to the end.The input should be positive numbers

Input(Input should be positive numbers only):4 0 1 3 0 5
Output:1 3 4 5 0 0
*/
#include <iostream>
using namespace std;

// Merging two sorted parts of array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left half
    int n2 = right - mid;    // Size of right half

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements (if any)
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
    }
}

// Display array
void printArray(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    
    int arr[] = {38, 27, 0, 3, 0, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for(int i=0; i < size; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
