#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> getRow(int rowNum) {
        long long ans = 1;
        vector<int> result;
        result.push_back(ans);
        for(int i = 0; i < rowNum; i++) {
            ans = ans * (rowNum - i);
            ans = ans/(i + 1);
            result.push_back(ans);
        }
        return result;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            long long ans = 1;
            result.push_back(getRow(i));
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test generating Pascal's Triangle with different sizes
    vector<int> testSizes = {5, 6, 8, 10};
    
    for(int numRows : testSizes) {
        cout << "\nPascal's Triangle with " << numRows << " rows:" << endl;
        vector<vector<int>> triangle = sol.generate(numRows);
        
        // Find the maximum number of digits in the triangle for proper spacing
        int maxDigits = 1;
        for(int i = 0; i < triangle.size(); i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                // log10(num) + 1 gives you num of digits in number
                int digits = (int)(log10(triangle[i][j]) + 1);
                maxDigits = max(maxDigits, digits);
            }
        }
        
        // Print the Pascal's Triangle with proper spacing
        for(int i = 0; i < triangle.size(); i++) {
            // Add leading spaces for triangle shape
            int leadingSpaces = (numRows - i - 1) * (maxDigits + 1) / 2;
            for(int k = 0; k < leadingSpaces; k++) {
                cout << " ";
            }
            
            // Print the row elements with consistent width
            for(int j = 0; j < triangle[i].size(); j++) {
                cout << setw(maxDigits) << triangle[i][j];
                if(j < triangle[i].size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
        
        cout << endl;
    }
        
    return 0;
}