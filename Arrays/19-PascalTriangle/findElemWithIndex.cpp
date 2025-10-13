#include <bits/stdc++.h>
using namespace std;

// Brute force method is generating Pascal's triangle and then returning the element at row and column

//optimal

class Solution{
public:
    void findElement(int row, int col){
        long long res = 1;
        if ((row - col) < col) {
            col = row - col;
        }
        for (int i = 0; i < col; i++) {
            res = res * (row - i);
            res = res / (i + 1);
        }
        cout << res << endl;
    }
};

int main() {
    Solution sol;
    int row, col;
    cout << "Enter row and column (0-indexed): ";
    cin >> row >> col;
    sol.findElement(row, col);
    return 0;
}

