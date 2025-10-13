#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/pascals-triangle-ii/description/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        int ans = 1;
        result.push_back(ans);
        for (int i = 0; i < rowIndex; i++) {
            ans = ans * (rowIndex - i);
            ans = ans / (i + 1);
            result.push_back(ans);
        }
        return result;
    }

    // Brute Force - tracing nCr for entire row
    vector<int> getRowBruteForce(int rowIndex) {
        vector<int> result;
        for (int i = 0; i <= rowIndex; i++) {
            long long res = 1;
            int col = i;
            if ((rowIndex - col) < col) {
                col = rowIndex - col;
            }
            for(int j = 0; j < col; j++) {
                res = res * (rowIndex - j);
                res = res / (j + 1);
            }
            result.push_back(res);
        }
        return result;
    }
};

int main() {
    Solution sol;
    int rowIndex;
    cout << "Enter the row index (0-indexed): ";
    cin >> rowIndex;

    vector<int> result = sol.getRow(rowIndex);
    cout << "Row " << rowIndex << " of Pascal's Triangle: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}