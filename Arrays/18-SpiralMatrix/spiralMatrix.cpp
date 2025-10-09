#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int no_rows = matrix.size();
        int no_cols = matrix[0].size();

        vector<int> result;
        int top = 0, bottom = no_rows - 1;
        int left = 0, right = no_cols - 1;

        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1: 3x3 matrix (filled in spiral order)
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    
    cout << "Matrix 1:" << endl;
    for(auto& row : matrix1) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<int> result1 = sol.spiralOrder(matrix1);
    cout << "Spiral Order: ";
    for(int val : result1) {
        cout << val << " ";
    }
    cout << endl << endl;
    
    // Example 2: 3x4 matrix (filled in spiral order)
    vector<vector<int>> matrix2 = {
        {1,  2,  3,  4},
        {10, 11, 12, 5},
        {9,  8,  7,  6}
    };
    
    cout << "Matrix 2:" << endl;
    for(auto& row : matrix2) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<int> result2 = sol.spiralOrder(matrix2);
    cout << "Spiral Order: ";
    for(int val : result2) {
        cout << val << " ";
    }
    cout << endl << endl;
    
    // Example 3: 4x3 matrix (filled in spiral order)
    vector<vector<int>> matrix3 = {
        {1,  2,  3},
        {10, 11, 4},
        {9,  12, 5},
        {8,  7,  6}
    };
    
    cout << "Matrix 3:" << endl;
    for(auto& row : matrix3) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<int> result3 = sol.spiralOrder(matrix3);
    cout << "Spiral Order: ";
    for(int val : result3) {
        cout << val << " ";
    }
    cout << endl << endl;
    
    // Example 4: 6x6 matrix (filled in spiral order)
    vector<vector<int>> matrix4 = {
        {1,  2,  3,  4,  5,  6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11}
    };
    
    cout << "Matrix 4 (6x6):" << endl;
    for(auto& row : matrix4) {
        for(int val : row) {
            cout << setw(3) << val << " ";
        }
        cout << endl;
    }
    
    vector<int> result4 = sol.spiralOrder(matrix4);
    cout << "Spiral Order: ";
    for(int val : result4) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}