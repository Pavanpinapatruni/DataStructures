#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void recursiveBubbleSort(int arr[], int n) {
        // Base case: if array has 1 or 0 elements, it's sorted
        if (n == 1 || n == 0) 
            return;
        
        // One pass of bubble sort
        // Move the largest element to the end
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        
        // Recursively sort the first n-1 elements
        recursiveBubbleSort(arr, n-1);
    }

    void recursiveInsertionSort(int arr[], int n) {
        // Base case: if array has 1 or 0 elements, it's sorted
        if (n <= 1) 
            return;
        
        // Sort first n-1 elements recursively
        recursiveInsertionSort(arr, n-1);
        
        // Insert the nth element in its correct position
        int last = arr[n-1];
        int j = n-2;
        
        // Move elements greater than 'last' one position ahead
        while (j >= 0 && arr[j] > last) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = last;
    }

    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i > 0; i--) {
            bool are_swaps = false;
            for (int j = 0; j < i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    are_swaps = true;
                }
            }
            if (!are_swaps) {
                break;
            }
        }
    }

    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                swap(arr[j-1], arr[j]);
                j--;
            }
            
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {64, 25, 12, 22, 11};
    sol.selectionSort(arr);
    cout << "Selection Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout<<endl;
    sol.bubbleSort(arr);
    cout << "Bubble Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout<<endl;
    sol.insertionSort(arr);
    cout << "Insertion Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
}