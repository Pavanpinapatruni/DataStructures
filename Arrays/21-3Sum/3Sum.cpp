#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        set<vector<int>> myset;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        sort(temp.begin(), temp.end());
                        myset.insert(temp);
                    }
                }
            }
        }
        for(auto i :myset) {
            result.push_back(i);
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test Case 1: ";
    for(int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<vector<int>> result1 = solution.threeSumBruteForce(nums1);
    cout << "Output: ";
    if(result1.empty()) {
        cout << "[]";
    } else {
        cout << "[";
        for(int i = 0; i < result1.size(); i++) {
            cout << "[";
            for(int j = 0; j < result1[i].size(); j++) {
                cout << result1[i][j];
                if(j < result1[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if(i < result1.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << endl << endl;
    
    // Test case 2: No solution
    vector<int> nums2 = {0, 1, 1};
    cout << "Test Case 2: ";
    for(int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<vector<int>> result2 = solution.threeSumBruteForce(nums2);
    cout << "Output: ";
    if(result2.empty()) {
        cout << "[]";
    } else {
        cout << "[";
        for(int i = 0; i < result2.size(); i++) {
            cout << "[";
            for(int j = 0; j < result2[i].size(); j++) {
                cout << result2[i][j];
                if(j < result2[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if(i < result2.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << endl << endl;
    
    // Test case 3: All zeros
    vector<int> nums3 = {0, 0, 0};
    cout << "Test Case 3: ";
    for(int num : nums3) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<vector<int>> result3 = solution.threeSumBruteForce(nums3);
    cout << "Output: ";
    if(result3.empty()) {
        cout << "[]";
    } else {
        cout << "[";
        for(int i = 0; i < result3.size(); i++) {
            cout << "[";
            for(int j = 0; j < result3[i].size(); j++) {
                cout << result3[i][j];
                if(j < result3[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if(i < result3.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << endl;
    
    return 0;
}