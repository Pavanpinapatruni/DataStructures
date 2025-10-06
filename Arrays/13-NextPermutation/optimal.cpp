#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArr(vector<int>& nums, int low, int high) {
        while(low < high) {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }
        if(ind == -1) {
            reverseArr(nums, 0, n-1);
        } else {
            for (int i = n - 1; i > ind; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[ind], nums[i]);
                    break;
                }
            }
            reverseArr(nums, ind + 1, n-1);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2};
    sol.nextPermutation(nums);
    for (int i : nums) {
        cout <<i<<endl;
    }
    return 0;
}