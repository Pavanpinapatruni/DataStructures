#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos_index = 0, neg_index = 1;
        vector<int> result(n);
        for(int num : nums) {
            if (num > 0) {
                result[pos_index] = num;
                pos_index += 2;

            } else {
                result[neg_index] = num;
                neg_index += 2;
            }
        }
        return result;
        
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {3,1,-2,-5,2,-4};
    vector<int> result1 = solution.rearrangeArray(nums1);
    cout << "Test case 1: [3,1,-2,-5,2,-4]" << endl;
    cout << "Rearranged array: ";
    for (int num : result1) {
        cout << num << " ";
    }
    

}