#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;
        for(int num : nums) {
            if (num < 0) {
                neg.push_back(num);
            } else {
                pos.push_back(num);
            }
        }

        if(pos.size() > neg.size()) {
            for (int i = 0; i < neg.size(); i++) {
                nums[i * 2] = pos[i];
                nums[i * 2 + 1] = neg[i];
            }

            for (int i = neg.size(); i < pos.size(); i++) {
                nums[i] = pos[i];
            }
        } else {
            for (int i = 0; i < pos.size(); i++) {
                nums[i * 2] = pos[i];
                nums[i * 2 + 1] = neg[i];
            }

            for (int i = pos.size(); i < neg.size(); i++) {
                nums[i] = neg[i];
            }
        }
        return nums;
        
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {3,1,-2,-5,2,-4,6,9};
    vector<int> result1 = solution.rearrangeArray(nums1);
    cout << "Test case 1: [3,1,-2,-5,2,-4]" << endl;
    cout << "Rearranged array: ";
    for (int num : result1) {
        cout << num << " ";
    }
}