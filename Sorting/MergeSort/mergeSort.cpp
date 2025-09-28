#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(int arr[], int low, int mid, int high) {
        int left = low; // Size of left subarray
        int right = mid + 1;    // Size of right subarray

        // Create temporary arrays
        vector<int> temp;

        while(left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(int arr[], int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2; // To avoid overflow

            // Recursively sort the first and second halves
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);

            // Merge the sorted halves
            merge(arr, low, mid, high);
        }
    }
};

int main() {
    Solution sol;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sol.mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}