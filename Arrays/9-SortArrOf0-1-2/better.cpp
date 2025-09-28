#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0, ones = 0, twos = 0;
        for(int num : nums) {
            if (num == 0) zeroes++;
            else if (num == 1) ones++;
            else twos++;
        }
        int index = 0;
        while (zeroes--) {
            nums[index++] = 0;
        }
        while (ones--) {
            nums[index++] = 1;
        }
        while (twos--) {
            nums[index++] = 2;
        }
        
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
}