#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();

     // Transpose
     for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            matrix[i][j] = matrix[j][i];
        }
     }

     for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
     }        
    }
};

int main() {
    Solution solution;
    
    // Test case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original Matrix 1:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    solution.rotate(matrix1);
    
    cout << "\nAfter 90-degree clockwise rotation:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    cout << "\n" << string(30, '-') << "\n" << endl;
    
    // Test case 2: 4x4 matrix
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    
    cout << "Original Matrix 2:" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    solution.rotate(matrix2);
    
    cout << "\nAfter 90-degree clockwise rotation:" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}