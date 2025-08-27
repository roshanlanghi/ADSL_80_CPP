/*
Problem 3: Maximize profit by trading stocks.
Statement: Given an array arr[] of N positive integers where each element 
           represents the stock price on a particular day, find the maximum 
           profit that can be earned by buying and selling stocks. 
           You can buy multiple times and sell multiple times, but must sell 
           before buying again.

Approach: Traverse the prices array. If today's price is higher than yesterday's, 
          sell the stock bought yesterday to gain profit. Accumulate all such profits 
          to get the maximum profit.

Input (Positive integers only): 7 1 5 3 6 4
Output: 7
Explanation: Buy on day 2 (price=1) and sell on day 3 (price=5) => profit=4
             Buy on day 4 (price=3) and sell on day 5 (price=6) => profit=3
             Total Profit = 4+3 = 7
*/

#include <iostream>
using namespace std;

class StockProfit {
public:
    int maxProfit(int prices[], int n) {
        int profit = 0;

        // Traverse the prices array
        for (int i = 1; i < n; i++) {
            // If today's price is higher than yesterday's
            // it means we can make profit
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int prices[n];
    cout << "Enter stock prices for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    StockProfit sp;
    int result = sp.maxProfit(prices, n);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}
