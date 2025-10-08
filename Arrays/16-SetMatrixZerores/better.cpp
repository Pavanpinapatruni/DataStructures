#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int no_rows = matrix.size();
        int no_cols = 0;
        if (no_rows > 0) {
            no_cols = matrix[0].size();
        }
        vector<int> rows(no_rows,0), cols(no_cols,0);

        for (int i = 0; i < no_rows; i++) {
            for (int j = 0; j < no_cols; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i = 0; i < no_rows; i++) {
            for(int j = 0; j < no_cols; j++) {
                if (rows[i] == 1 || cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};

void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix1);
    
    solution.setZeroes(matrix1);
    
    cout << "After setting zeroes:" << endl;
    printMatrix(matrix1);
    
    // Test Case 2: Multiple zeros
    cout << "Test Case 2:" << endl;
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix2);
    
    solution.setZeroes(matrix2);
    
    cout << "After setting zeroes:" << endl;
    printMatrix(matrix2);
    
    // Test Case 3: Single element matrix
    cout << "Test Case 3:" << endl;
    vector<vector<int>> matrix3 = {{0}};
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix3);
    
    solution.setZeroes(matrix3);
    
    cout << "After setting zeroes:" << endl;
    printMatrix(matrix3);
    
    // Test Case 4: No zeros
    cout << "Test Case 4:" << endl;
    vector<vector<int>> matrix4 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix4);
    
    solution.setZeroes(matrix4);
    
    cout << "After setting zeroes:" << endl;
    printMatrix(matrix4);
    
    return 0;
}