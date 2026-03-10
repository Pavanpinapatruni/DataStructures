
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        int l =0, r= 0, max_len =0;
        int n = s.length();
        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            hash[s[r]] = r;
            int len = r-l+1;
            max_len = max(max_len, len);
            r++;
        }
        return max_len;

    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    string s1 = "abcabcbb";
    cout << "Test Case 1: " << s1 << endl;
    
    int result1 = solution.lengthOfLongestSubstring(s1);
    cout << "Output: " << result1 << endl << endl;
    
    // Test case 2: All characters are the same
    string s2 = "bbbbb";
    cout << "Test Case 2: " << s2 << endl;
    
    int result2 = solution.lengthOfLongestSubstring(s2);
    cout << "Output: " << result2 << endl << endl;

    // Test case 3: String with all unique characters
    string s3 = "abcdefg";
    cout << "Test Case 3: " << s3 << endl;
    
    int result3 = solution.lengthOfLongestSubstring(s3);
    cout << "Output: " << result3 << endl << endl;

    // Test case 4: Empty string
    string s4 = "";
    cout << "Test Case 4: Empty String" << endl;
    
    int result4 = solution.lengthOfLongestSubstring(s4);
    cout << "Output: " << result4 << endl << endl;

    // Test case 5: String with special characters
    string s5 = "pwwkew";
    cout << "Test Case 5: " << s5 << endl;
    
    int result5 = solution.lengthOfLongestSubstring(s5);
    cout << "Output: " << result5 << endl << endl;

    return 0;
}