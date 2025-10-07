#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        int count = 1;
        int longest = 1;
        int latest = INT_MIN;
        for(int i : nums) {
            if (i == (latest + 1)) {
                count++;
            } else if (i != latest) {
                count = 1;
            }
            if (count > longest) {
                longest = count;
            }
            latest = i;
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};

    int longest = sol.longestConsecutive(nums);
    cout<<longest<<endl;
}