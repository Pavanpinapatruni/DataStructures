#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        int max = nums[n-1];
        vector<int> result;
        for(int i = n - 1; i >= 0; i--) {
            if (nums[i] >= max) {
                max = nums[i];
                result.insert(result.begin(), max);
            }
        }
      return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> result = sol.leaders(nums);
    for(int i : result) {
        cout<<i<< " ";
    }
    cout<<endl;

    vector<int> nums1 = {61, 61, 17};
    vector<int> result1 = sol.leaders(nums1);
    for(int i : result1) {
        cout<<i<< " ";
    }
    cout<<endl;
    return 0;
}