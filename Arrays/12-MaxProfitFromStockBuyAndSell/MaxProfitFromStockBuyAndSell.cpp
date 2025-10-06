#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < n; i++) {
            int cost = prices[i] - minPrice;
            maxProfit = max(cost, maxProfit);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl; // Output: 5
    return 0;
}