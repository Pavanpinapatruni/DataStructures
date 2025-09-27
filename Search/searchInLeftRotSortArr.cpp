#include <bits/stdc++.h>
using namespace std;

/*
LeetCode link 
https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1783788257/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int middle = (low + high)/2;
        while(low <= high) {
            middle = (low + high) / 2;
            if (nums[middle] == target) {
                return middle;
            }

            if (nums[low] <= nums[middle]) {
                //Left part is sorted
                if (target >= nums[low] && target < nums[middle]) {
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
                middle = (low + high) / 2;
            } else {
                //Right part is sorted
                if (target > nums[middle] && target <= nums[high]) {
                    low = middle + 1;
                } else {
                    high = middle - 1;
                } 
            }
        }
        return -1;
        
    }
};


int main() {
    Solution solution;
    
    // Test array (must be sorted for binary search)
    // vector<int> arr = {4,5,6,7,0,1,2};
    // vector<int> arr = {3, 1};
    // vector<int> arr = {1,3,5};
    // vector<int> arr = {5, 1, 3};
    vector<int> arr = {9,1,2,3,4,5,6,7,8};
    
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << solution.search(arr, 1) << endl;    
    return 0;
}
