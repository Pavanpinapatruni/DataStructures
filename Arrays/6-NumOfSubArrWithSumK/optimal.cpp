#include <bits/stdc++.h>
using namespace std;

// Function to find the longest subarray with sum equal to k
int findingNumOfSubArrayWithSumK(int arr[], int n, int k)
{
    unordered_map<long long, int> presumMap;
    long long presum = 0;
    int count = 0;

    for (int i =0; i < n; i++) {
        presum += arr[i];

        if (presum == k) {
            count++;
        }

        if (presumMap.find(presum - k) != presumMap.end()) {
            count += presumMap[presum - k];
        }

        presumMap[presum]++;
    }

    return count;
}

int main()
{
    cout << "=== Test Cases for findingNumOfSubArrayWithSumK ===" << endl << endl;
    
    // Test Case 1: Basic positive numbers
    cout << "Test Case 1: Basic positive numbers" << endl;
    int arr1[] = {10, 5, 2, 7, 1, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 15;
    cout << "Array: [10, 5, 2, 7, 1, 9], k = " << k1 << endl;
    int count1 = findingNumOfSubArrayWithSumK(arr1, n1, k1);
    cout << "Count of subarrays with sum " << k1 << " is: " << count1 << endl;
    cout << endl;
    
    // Test Case 2: Array with negative numbers
    cout << "Test Case 2: Array with negative numbers" << endl;
    int arr2[] = {3, 4, -7, 1, 3, 3, 1, -4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 7;
    cout << "Array: [3, 4, -7, 1, 3, 3, 1, -4], k = " << k2 << endl;
    int count2 = findingNumOfSubArrayWithSumK(arr2, n2, k2);
    cout << "Count of subarrays with sum " << k2 << " is: " << count2 << endl;
    cout << endl;
    
    // Test Case 3: Array with zeros
    cout << "Test Case 3: Array with zeros" << endl;
    int arr3[] = {1, 0, 1, 0, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int k3 = 1;
    cout << "Array: [1, 0, 1, 0, 1], k = " << k3 << endl;
    int count3 = findingNumOfSubArrayWithSumK(arr3, n3, k3);
    cout << "Count of subarrays with sum " << k3 << " is: " << count3 << endl;
    cout << endl;
    
    // Test Case 4: All zeros with k = 0
    cout << "Test Case 4: All zeros with k = 0" << endl;
    int arr4[] = {0, 0, 0, 0};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int k4 = 0;
    cout << "Array: [0, 0, 0, 0], k = " << k4 << endl;
    int count4 = findingNumOfSubArrayWithSumK(arr4, n4, k4);
    cout << "Count of subarrays with sum " << k4 << " is: " << count4 << endl;
    cout << endl;
    
    // Test Case 5: Single element array (match)
    cout << "Test Case 5: Single element array (match)" << endl;
    int arr5[] = {5};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int k5 = 5;
    cout << "Array: [5], k = " << k5 << endl;
    int count5 = findingNumOfSubArrayWithSumK(arr5, n5, k5);
    cout << "Count of subarrays with sum " << k5 << " is: " << count5 << endl;
    cout << endl;
    
    // Test Case 6: Single element array (no match)
    cout << "Test Case 6: Single element array (no match)" << endl;
    int arr6[] = {5};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    int k6 = 3;
    cout << "Array: [5], k = " << k6 << endl;
    int count6 = findingNumOfSubArrayWithSumK(arr6, n6, k6);
    cout << "Count of subarrays with sum " << k6 << " is: " << count6 << endl;
    cout << endl;
    
    // Test Case 7: All negative numbers
    cout << "Test Case 7: All negative numbers" << endl;
    int arr7[] = {-1, -2, -3, -4};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    int k7 = -5;
    cout << "Array: [-1, -2, -3, -4], k = " << k7 << endl;
    int count7 = findingNumOfSubArrayWithSumK(arr7, n7, k7);
    cout << "Count of subarrays with sum " << k7 << " is: " << count7 << endl;
    cout << endl;
    
    // Test Case 8: k = 0 with mixed numbers
    cout << "Test Case 8: k = 0 with mixed numbers" << endl;
    int arr8[] = {3, -3, 1, -1, 0};
    int n8 = sizeof(arr8) / sizeof(arr8[0]);
    int k8 = 0;
    cout << "Array: [3, -3, 1, -1, 0], k = " << k8 << endl;
    int count8 = findingNumOfSubArrayWithSumK(arr8, n8, k8);
    cout << "Count of subarrays with sum " << k8 << " is: " << count8 << endl;
    cout << endl;
    
    // Test Case 9: Large k value (no subarrays)
    cout << "Test Case 9: Large k value (no subarrays)" << endl;
    int arr9[] = {1, 2, 3};
    int n9 = sizeof(arr9) / sizeof(arr9[0]);
    int k9 = 100;
    cout << "Array: [1, 2, 3], k = " << k9 << endl;
    int count9 = findingNumOfSubArrayWithSumK(arr9, n9, k9);
    cout << "Count of subarrays with sum " << k9 << " is: " << count9 << endl;
    cout << endl;
    
    // Test Case 10: Repeated elements
    cout << "Test Case 10: Repeated elements" << endl;
    int arr10[] = {2, 2, 2, 2};
    int n10 = sizeof(arr10) / sizeof(arr10[0]);
    int k10 = 4;
    cout << "Array: [2, 2, 2, 2], k = " << k10 << endl;
    int count10 = findingNumOfSubArrayWithSumK(arr10, n10, k10);
    cout << "Count of subarrays with sum " << k10 << " is: " << count10 << endl;
    
    return 0;
}