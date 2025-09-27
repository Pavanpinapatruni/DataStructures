#include <bits/stdc++.h>
using namespace std;

/*
LeetCode link 
https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1783788257/
*/

class Solution {
public:
    int binSearch(vector<int>& nums, int target, int start, int len) {
        cout << "binSearch called with start: " << start << " len: " << len << endl;
        int low = start, high = len;
        int middle = (low + high)/2;
        int index = -1;
        while(low <= high) {
            if (nums[middle] == target) {
                index = middle;
                break;
            }
            if (nums[middle] < target) {
                low = middle + 1;
            }
            if (nums[middle] > target) {
                high = middle -1;
            }
            middle = (low + high)/2;
        }
        return index;
    }

    int linSearch(vector<int>& nums, int target, int start, int end) {
        cout << "linSearch called with start: " << start << " end: " << end << endl;
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i - 1] > nums[i]) {
                return -1;
            }
        }
        return -1;
    }

    int revLinSearch(vector<int>& nums, int target, int end) {
        cout << "revLinSearch called with end: " << end << endl;
        for (int i = end - 1; i >=0; i--) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] > nums[i+1]) {
                return -1;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int middle = (low + high)/2;
        while(low <= high && middle <= high) {
            if (nums[middle] == target) {
                return middle;
            }

            if (nums[low] <= nums[middle]) {
                if (target > nums[middle]) {
                    return linSearch(nums, target, middle, high);
                } else {
                    if (target >= nums[low]) {
                        return binSearch(nums, target, low, high);
                    }
                    else {
                        low = middle + 1;
                        middle = (low + high) / 2;
                        cout<< "1 st third case low " <<low << " middle "<<middle<<" high "<<high<< endl;
                    }
                }

            } else {
                if (target < nums[middle]) {
                    return revLinSearch(nums, target, middle);
                } else {
                    if (target <= nums[high]) {
                        return binSearch(nums, target, middle+1, high);
                    } else {
                        high = middle - 1;
                        middle = (low + high) / 2;
                        cout<< "2nd third case low " <<low << " middle "<<middle<<" high "<<high<< endl;
                    }
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
