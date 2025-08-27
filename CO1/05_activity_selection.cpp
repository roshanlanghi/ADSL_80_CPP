/*
Problem 4: Activity Selection Problem with K Persons

Statement: 
Given two arrays S[] and E[] of size N denoting the starting and ending times 
of shops, and an integer K denoting the number of people, find the maximum 
number of shops that can be visited in total if each shop is visited optimally 
under the following conditions:

1) A shop can be visited by only one person.
2) A person cannot visit another shop if its timing collides with a previously 
   visited shop.

Approach:
1) Sort all shops by their ending times (E[]). Sorting ensures that we always 
   consider shops that finish earliest first.
2) Initialize an array freeTime[K] to keep track of the last shop visited by 
   each person.
3) Traverse the sorted shops and assign each shop to the first person whose 
   freeTime allows visiting that shop.
4) Update that person's freeTime and increment the total visited shop count.
5) The result is the total number of shops visited by all K persons.

Input Example 1:
N = 5, K = 2
S[] = {1, 8, 3, 2, 6}
E[] = {5, 10, 6, 5, 9}
Output: 4

Input Example 2:
N = 3, K = 2
S[] = {1, 2, 3}
E[] = {3, 4, 5}
Output: 3
*/

#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter number of shops: ";
    cin >> N;
    cout << "Enter number of persons: ";
    cin >> K;

    int S[100], E[100];      // start and end times
    int freeTime[100] = {0}; // last visit time for each person

    cout << "Enter start times of shops:\n";
    for(int i = 0; i < N; i++)
        cin >> S[i];

    cout << "Enter end times of shops:\n";
    for(int i = 0; i < N; i++)
        cin >> E[i];

    // Step 1: Sort shops by end time (bubble sort)
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-i-1; j++){
            if(E[j] > E[j+1]){
                swap(E[j], E[j+1]);
                swap(S[j], S[j+1]);
            }
        }
    }

    // Step 2: Initialize all persons as free at time 0
    for(int p = 0; p < K; p++)
        freeTime[p] = 0;

    int count = 0; // total shops visited

    // Step 3: Assign shops to persons
    for(int i = 0; i < N; i++){
        for(int p = 0; p < K; p++){
            if(S[i] >= freeTime[p]){
                freeTime[p] = E[i]; // person p visits this shop
                count++;
                break; // move to next shop
            }
        }
    }

    cout << "Total visited shops: " << count << endl;
    return 0;
}
