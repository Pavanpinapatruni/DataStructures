#include <bits/stdc++.h>
using namespace std;

// leet code link https://leetcode.com/problems/maximum-subarray/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Kadane's Algorithm
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;
        int start = 0, end = 0, tempStart = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            if (sum > maxSum) {
                maxSum = sum;
                start = tempStart;
                end = i;
            }
            
            if (sum < 0) {
                sum = 0;
                tempStart = i + 1;
            }
        }
        /*Additional not required for leetcode problem*/
        cout << "Start Index: " << start << ", End Index: " << end << endl;
        for (int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }
        return maxSum;
        
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Test Case 1: ";
    cout << "Input: [-2,1,-3,4,-1,2,1,-5,4], Output: " << sol.maxSubArray(nums1) << endl;

    vector<int> nums2 = {1};
    cout << "Test Case 2: ";
    cout << "Input: [1], Output: " << sol.maxSubArray(nums2) << endl;

    vector<int> nums3 = {5,4,-1,7,8};
    cout << "Test Case 3: ";
    cout << "Input: [5,4,-1,7,8], Output: " << sol.maxSubArray(nums3) << endl;

    vector<int> nums4 = {-1};
    cout << "Test Case 4: ";
    cout << "Input: [-1], Output: " << sol.maxSubArray(nums4) << endl;

    vector<int> nums5 = {-2147483647};
    cout << "Test Case 5: ";
    cout << "Input: [-2147483647], Output: " << sol.maxSubArray(nums5) << endl;

    vector<int> nums6 = {-2,-1};
    cout << "Test Case 6: ";
    cout << "Input: [-2,-1], Output: " << sol.maxSubArray(nums6) << endl;

    vector<int> nums7 = {0};
    cout << "Test Case 7: ";
    cout << "Input: [0], Output: " << sol.maxSubArray(nums7) << endl;

    vector<int> nums8 = {-1,-2,-3,-4};
    cout << "Test Case 8: ";
    cout << "Input: [-1,-2,-3,-4], Output: " << sol.maxSubArray(nums8) << endl;

    vector<int> nums9 = {8,-19,5,-4,20};
    cout << "Test Case 9: ";
    cout << "Input: [8,-19,5,-4,20], Output: " << sol.maxSubArray(nums9) << endl;

    return 0;
}