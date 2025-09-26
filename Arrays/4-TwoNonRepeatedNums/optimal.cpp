#include <bits/stdc++.h>
using namespace std;

void findTwoUnique(int arr[], int n, int &num1, int &num2) {
    int XOR2 = 0;   // This will store XOR of two unique numbers
    for (int i = 0; i < n; i++) {
        XOR2 ^= arr[i];
    }

    // Find the rightmost set bit in XOR2
    int setBit = XOR2 & -XOR2;

    num1 = 0, num2 = 0;
    // Divide elements into two groups based on the set bit
    for (int i = 0; i < n; i++) {
        if (arr[i] & setBit) {
            num1 ^= arr[i];  // Group 1
        } else {
            num2 ^= arr[i];  // Group 2
        }
    }
}
int main() {
    int arr[] = {2, 4, 7, 9, 2, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num1, num2;
    findTwoUnique(arr, n, num1, num2);
    cout << "The two non-repeated numbers are: " << num1 << " and " << num2 << endl;
    return 0;
}