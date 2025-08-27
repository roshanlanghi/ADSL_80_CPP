#include <iostream>
using namespace std;

int countTrailingZeroes(int x) {
   
    int count = 0;
    while (x > 0) {
        x /= 5;  // Count factors of 5
        count += x;
    }
    return count;
}

 
int findSmallestNumber(int n) {
    int low = 0, high = 5 * n, mid;
    int result = -1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        int zeroes = countTrailingZeroes(mid);
        
        if (zeroes >= n) {
            result = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeroes: ";
    cin >> n;
    
    cout << "Smallest number with at least " << n << " trailing zeroes in factorial is: "<<endl;
    cout << findSmallestNumber(n) << endl;

    return 0;
}
