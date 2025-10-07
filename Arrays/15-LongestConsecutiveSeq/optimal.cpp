#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // optimal if array shouldn't be manipulated
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        unordered_set<int> st;
        for(int i : nums) {
            st.insert(i);
        }
        int longest = 1;
        for (int i : st) {
            int count = 1;
            if(st.find(i-1) == st.end()) {
                int x = i;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    count++;
                }
                if (longest < count) {
                    longest = count;
                }
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};

    int longest = sol.longestConsecutive(nums);
    cout<<longest<<endl;
}