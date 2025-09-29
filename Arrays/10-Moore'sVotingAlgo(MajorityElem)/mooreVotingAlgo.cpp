#include <bits/stdc++.h>
using namespace std;



/*
link : https://leetcode.com/problems/majority-element/description/""
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

// better way would be hashing the below one is optimal
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                element = num;
            }
            if (num == element) {
                count++;
            } else {
                count--;
            }
        }
        return element;
        
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic majority element
    vector<int> nums1 = {3, 2, 3};
    cout << "Test case 1: [3, 2, 3]" << endl;
    cout << "Majority element: " << solution.majorityElement(nums1) << endl;
    cout << endl;
    
    // Test case 2: Larger array with majority element
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test case 2: [2, 2, 1, 1, 1, 2, 2]" << endl;
    cout << "Majority element: " << solution.majorityElement(nums2) << endl;
    cout << endl;
    
    // Test case 3: All elements are the same
    vector<int> nums3 = {1, 1, 1, 1, 1};
    cout << "Test case 3: [1, 1, 1, 1, 1]" << endl;
    cout << "Majority element: " << solution.majorityElement(nums3) << endl;
    cout << endl;
    
    // Test case 4: Single element
    vector<int> nums4 = {5};
    cout << "Test case 4: [5]" << endl;
    cout << "Majority element: " << solution.majorityElement(nums4) << endl;
    cout << endl;
    
    // Test case 5: Large array with majority element
    vector<int> nums5 = {4, 4, 2, 4, 3, 4, 4, 3, 2, 4};
    cout << "Test case 5: [4, 4, 2, 4, 3, 4, 4, 3, 2, 4]" << endl;
    cout << "Majority element: " << solution.majorityElement(nums5) << endl;
    cout << endl;
    
    vector<int> userNums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> userNums[i];
    }
    
    cout << "Your array: [";
    for (int i = 0; i < n; i++) {
        cout << userNums[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Majority element: " << solution.majorityElement(userNums) << endl;
    
    return 0;
}