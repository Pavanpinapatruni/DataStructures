#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % arr.size(); // In case k is greater than array size
    int temp[k];

    for(int i = 0; i < k; i++) {        // O(k)
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++) {       // O(n-k)
        arr[i - k] = arr[i];
    }
    for(int i = n-k; i < n; i++) {      // O(k)
        arr[i] = temp[i - (n-k)];
    }
}

// O(k) + O(n-k) + O(k) = O(n)
// Space Complexity: O(k)

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 4;

    rotateArray(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}