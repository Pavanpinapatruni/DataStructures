#include <bits/stdc++.h>
using namespace std;

// Two pointer approach - O(n) time complexity and O(1) space complexity
void pushZerosToEnd(vector<int> &arr) {
    int n = arr.size();
    int count = 0; // Count of non-zero elements

    for(int i = 0; i < n; i++) { // O(n)
        if(arr[i] != 0) {
            int temp = arr[count];
            arr[count++] = arr[i]; // Place non-zero element at the count index
            arr[i] = temp; // Set current index to zero
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 0, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}