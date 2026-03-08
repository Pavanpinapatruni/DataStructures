
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        // code here.
        int lsum=0, rsum=0, sum = 0, max_sum=0;
        
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        max_sum = lsum;
        int rightIndex = cardPoints.size() - 1;
        
        for(int i= k-1; i>=0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIndex];
            rightIndex--;
            sum = lsum + rsum;
            max_sum = max(max_sum,sum);
            sum = 0;
        }
        
        return max_sum;
    }
};


int main() {
    Solution solution;
    
    // Test case 1: Basic example
    vector<int> cardPoints1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    cout << "Test Case 1: ";
    for(int num : cardPoints1) {
        cout << num << " ";
    }
    cout << endl;
    
    int result1 = solution.maxScore(cardPoints1, k1);
    cout << "Output: " << result1 << endl << endl;
    
    // Test case 2: All points are the same
    vector<int> cardPoints2 = {2, 2, 2};
    int k2 = 2;
    cout << "Test Case 2: ";
    for(int num : cardPoints2) {
        cout << num << " ";
    }
    cout << endl;
    
    int result2 = solution.maxScore(cardPoints2, k2);
    cout << "Output: " << result2 << endl << endl;

    // Test case 3: k equals the number of cards
    vector<int> cardPoints3 = {9, 7, 7, 9, 7};
    int k3 = 5;
    cout << "Test Case 3: ";
    for(int num : cardPoints3) {
        cout << num << " ";
    }
    cout << endl;
    
    int result3 = solution.maxScore(cardPoints3, k3);
    cout << "Output: " << result3 << endl << endl;

}