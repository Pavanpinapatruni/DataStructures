#include <bits/stdc++.h>
using namespace std;

// This is optimal if array indices also asked
// if Two sum is exists or not alone asked you can for 2-pointer approach
// of sorted array initializing indices start at beginning and end at the end of
// vector (if sum of two values > target reduce end, else increase the start)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        map<long long, int> mpp;
        int i = 0;
        while ( i < n ) {
            if (mpp.find(target - nums[i]) != mpp.end()) {
                result.push_back(mpp[target - nums[i]]);
                result.push_back(i);
                break;
            }
            mpp[nums[i]] = i;
            i++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "=== Two Sum Problem - Brute Force Solution ===" << endl << endl;
    
    // Test Case 1: Basic case with positive numbers
    cout << "Test Case 1: Basic case" << endl;
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Array: [2, 7, 11, 15], Target: " << target1 << endl;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Result: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "Values: " << nums1[result1[0]] << " + " << nums1[result1[1]] << " = " << target1 << endl;
    cout << endl;
    
    // Test Case 2: Target with negative numbers
    cout << "Test Case 2: Array with negative numbers" << endl;
    vector<int> nums2 = {-3, 4, 3, 90};
    int target2 = 0;
    cout << "Array: [-3, 4, 3, 90], Target: " << target2 << endl;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Result: [" << result2[0] << ", " << result2[1] << "]" << endl;
    cout << "Values: " << nums2[result2[0]] << " + " << nums2[result2[1]] << " = " << target2 << endl;
    cout << endl;
    
    // Test Case 3: Minimum array size
    cout << "Test Case 3: Minimum array size" << endl;
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    cout << "Array: [3, 3], Target: " << target3 << endl;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Result: [" << result3[0] << ", " << result3[1] << "]" << endl;
    cout << "Values: " << nums3[result3[0]] << " + " << nums3[result3[1]] << " = " << target3 << endl;
    cout << endl;
    
    // Test Case 4: Large numbers
    cout << "Test Case 4: Large numbers" << endl;
    vector<int> nums4 = {1000000, 2000000, 3000000, 4000000};
    int target4 = 5000000;
    cout << "Array: [1000000, 2000000, 3000000, 4000000], Target: " << target4 << endl;
    vector<int> result4 = sol.twoSum(nums4, target4);
    cout << "Result: [" << result4[0] << ", " << result4[1] << "]" << endl;
    cout << "Values: " << nums4[result4[0]] << " + " << nums4[result4[1]] << " = " << target4 << endl;
    cout << endl;
    
    // Test Case 5: Mixed positive and negative
    cout << "Test Case 5: Mixed positive and negative numbers" << endl;
    vector<int> nums5 = {-1, -2, -3, -4, -5};
    int target5 = -8;
    cout << "Array: [-1, -2, -3, -4, -5], Target: " << target5 << endl;
    vector<int> result5 = sol.twoSum(nums5, target5);
    cout << "Result: [" << result5[0] << ", " << result5[1] << "]" << endl;
    cout << "Values: " << nums5[result5[0]] << " + " << nums5[result5[1]] << " = " << target5 << endl;
    cout << endl;
    
    // Test Case 6: Zero in array
    cout << "Test Case 6: Array with zero" << endl;
    vector<int> nums6 = {0, 4, 3, 0};
    int target6 = 0;
    cout << "Array: [0, 4, 3, 0], Target: " << target6 << endl;
    vector<int> result6 = sol.twoSum(nums6, target6);
    cout << "Result: [" << result6[0] << ", " << result6[1] << "]" << endl;
    cout << "Values: " << nums6[result6[0]] << " + " << nums6[result6[1]] << " = " << target6 << endl;
    cout << endl;
    
    // Test Case 7: Solution at the end
    cout << "Test Case 7: Solution at the end of array" << endl;
    vector<int> nums7 = {3, 2, 4};
    int target7 = 6;
    cout << "Array: [3, 2, 4], Target: " << target7 << endl;
    vector<int> result7 = sol.twoSum(nums7, target7);
    cout << "Result: [" << result7[0] << ", " << result7[1] << "]" << endl;
    cout << "Values: " << nums7[result7[0]] << " + " << nums7[result7[1]] << " = " << target7 << endl;
    
    return 0;
}