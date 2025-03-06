#include <iostream>
#include <vector>
using namespace std;

// Function of 0/1 Knapsack using Dynamic Programming
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    // DP table bottom-up
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    
    vector<int> val(n), wt(n);
    cout << "Enter values of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Value of item " << i + 1 << ": ";
        cin >> val[i];
    }
    
    cout << "Enter weights of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> wt[i];
    }
    
    cout << "\nMaximum value in knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}