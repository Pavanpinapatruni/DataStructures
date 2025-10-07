#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1};
    sol.nextPermutation(nums);
    for (int i : nums) {
        cout <<i<<endl;
    }
    return 0;
}