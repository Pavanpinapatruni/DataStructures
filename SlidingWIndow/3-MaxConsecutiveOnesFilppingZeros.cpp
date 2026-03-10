#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int longestOnesBruteForce(vector<int>& nums, int k) {
        int max_len = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int count = 0, len = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    count++;
                }

                if (count > k) {
                    break;
                }
                len++;
                max_len = max(len, max_len);
            }
        }
        return max_len;
    }

    int longestOnesBetter(vector<int>& nums, int k) {
        int l = 0, r = 0, max_len = 0;
        int zeros = 0, len = 0;
        int n =  nums.size();
        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }
            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }
            len = r-l+1;
            max_len = max(max_len, len);
            r++;
        }
        return max_len;
    }

    int longestOnes(vector<int>& nums, int k) {

        int l = 0, r = 0, max_len = 0, len = 0;
        int zeros = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                zeros++;
            }
            if (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }

            if (zeros <= k) {
                len = r - l + 1;
            }
            
            max_len = max(max_len, len);
            r++;
        }
        return max_len;
    }
};

int main() {
    class Solution sol;
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 3;

    cout<< "Output : " << sol.longestOnes(nums1, k1)<<endl;

    vector<int> nums2 = {0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;

    cout<< "Output : " << sol.longestOnes(nums2, k2)<<endl;
}