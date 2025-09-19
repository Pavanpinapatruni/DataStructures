#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % arr.size(); // In case k is greater than array size
    
    reverse(arr.begin(), arr.begin() + k); // O(k)
    reverse(arr.begin() + k, arr.end());   // O(n-k)
    reverse(arr.begin(), arr.end());       // O(n)
}


int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 4;

    rotateArray(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}