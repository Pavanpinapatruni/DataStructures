#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int odd[n/2], even[n/2];
        int odd_index = 0, even_index = 0;
        vector<int> result(n);
        for(int num : nums) {
            if (num < 0) {
                odd[odd_index++] = num;
            } else {
                even[even_index++] = num;
            }
        }

        for (int i = 0; i < n/2; i++) {
            result[i * 2] = even[i];
            result[i * 2 + 1] = odd[i];
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