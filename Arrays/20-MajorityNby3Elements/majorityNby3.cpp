#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElementBruteForce(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        set<int> mySet;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > n/3) {
                mySet.insert(nums[i]);
            }
            if (result.size() == 2) { //Since only two elements can be repeated n/3 times
                break;
            }
        }
        for (int i : mySet) {
            result.push_back(i);
        }
        sort(result.begin(), result.end());
        return result;        
    }

    vector<int> majorityElementBetter(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> myMap;
        for (int i = 0; i < n; i++) {
            myMap[nums[i]] += 1;
            if (myMap[nums[i]] == (n/3 + 1)) {
                result.push_back(nums[i]);
            }
            if(result.size() == 2) { //Since only two elements can be repeated n/3 times
                break;
            }
        }
        return result;        
    }
    // Optimal Approach: Boyer-Moore Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int count1 = 0, count2 = 0;
        int elem1 = INT_MIN, elem2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            if (count1 == 0 && nums[i] != elem2) {
                count1++;
                elem1 = nums[i];
            } else if (count2 == 0 && nums[i] != elem1) {
                count2++;
                elem2 = nums[i];
            } else if (nums[i] == elem1) {
                count1++;
            } else if (nums[i] == elem2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++) {
            if (nums[i] == elem1) count1++;
            if (nums[i] == elem2) count2++;
        }
        int maxPossible = (int)n/3 + 1;
        if (count1 >= maxPossible) result.push_back(elem1);
        if (count2 >= maxPossible) result.push_back(elem2);
        return result;        
    }

};

int main() {
    Solution sol;
    
    // Test case 1: [3,2,3]
    vector<int> nums1 = {3, 2, 3};
    cout << "Test case 1: [3, 2, 3]" << endl;
    cout << "Expected: [3]" << endl;
    cout << "Result: [";
    vector<int> result1 = sol.majorityElement(nums1);
    for (int i = 0; i < result1.size(); i++) {
        if (i > 0) cout << ", ";
        cout << result1[i];
    }
    cout << "]" << endl << endl;
    
    // Test case 2: [1]
    vector<int> nums2 = {1};
    cout << "Test case 2: [1]" << endl;
    cout << "Expected: [1]" << endl;
    cout << "Result: [";
    vector<int> result2 = sol.majorityElement(nums2);
    for (int i = 0; i < result2.size(); i++) {
        if (i > 0) cout << ", ";
        cout << result2[i];
    }
    cout << "]" << endl << endl;
    
    // Test case 3: [1,2]
    vector<int> nums3 = {1, 2};
    cout << "Test case 3: [1, 2]" << endl;
    cout << "Expected: []" << endl;
    cout << "Result: [";
    vector<int> result3 = sol.majorityElement(nums3);
    for (int i = 0; i < result3.size(); i++) {
        if (i > 0) cout << ", ";
        cout << result3[i];
    }
    cout << "]" << endl << endl;
    
    // Test case 4: [1,1,1,3,3,2,2,2]
    vector<int> nums4 = {1, 1, 1, 3, 3, 2, 2, 2};
    cout << "Test case 4: [1, 1, 1, 3, 3, 2, 2, 2]" << endl;
    cout << "Expected: [1, 2]" << endl;
    cout << "Result: [";
    vector<int> result4 = sol.majorityElement(nums4);
    for (int i = 0; i < result4.size(); i++) {
        if (i > 0) cout << ", ";
        cout << result4[i];
    }
    cout << "]" << endl << endl;

    // Test case 5: [-1, -2]
    vector<int> nums5 = {-1, -2};
    cout << "Test case 5: [-1, -2]" << endl;
    cout << "Expected: [-1, -2]" << endl;
    cout << "Result: [";
    vector<int> result5 = sol.majorityElement(nums5);
    for (int i = 0; i < result5.size(); i++) {
        if (i > 0) cout << ", ";
        cout << result5[i];
    }
    cout << "]" << endl << endl;
    
    return 0;
}
