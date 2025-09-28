#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to partition the array
    int partition(int arr[], int low, int high) {
        int pivot = arr[high]; // Choosing the last element as pivot
        int i = low; // Pointer for the smaller element
        int j = high - 1; // Pointer for the larger element

        while (i <= j) {
            // Increment i until we find an element greater than the pivot
            while (i <= j && arr[i] <= pivot) {
                i++;
            }
            // Decrement j until we find an element less than or equal to the pivot
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            // If i is less than j, swap the elements at i and j
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        // Place the pivot in its correct position
        swap(arr[i], arr[high]);
        return i; // Return the index of the pivot
    }
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            // Partition the array
            int pivot = partition(arr, low, high);
            
            // Recursively sort elements before and after partition
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
    
};


int main() {
    Solution sol;
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sol.quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}