#include <bits/stdc++.h>
using namespace std;

// Function to find the longest subarray with sum equal to k
// Time Complexity: O(n log n) - where n is the size of array
//   - The for loop runs n times
//   - In each iteration: 2 find operations + 1 potential insert operation
//   - Each map operation (find, insert) takes O(log n) time in worst case
//   - Overall: O(n * 3 * log n) = O(n log n)
// Space Complexity: O(n) - for the map to store prefix sums
//   - In worst case, all prefix sums are unique, so map can store up to n elements
void findingLongestSubArray(int arr[], int n, int k)
{
    map<long long, int> presumMap;
    long long presum = 0;
    int maxLen = 0;
    int startIndex = -1;
    int endIndex = -1;

    for (int i =0; i < n; i++) {
        presum += arr[i];

        if (presum == k) {
            maxLen = i + 1;
            startIndex = 0;
            endIndex = i;
        }

        if (presumMap.find(presum) == presumMap.end()) {
            presumMap[presum] = i;
        }

        if (presumMap.find(presum - k) != presumMap.end()) {
            maxLen = max(maxLen, i - presumMap[presum - k]);
            if (maxLen == i - presumMap[presum - k]) {
                startIndex = presumMap[presum - k] + 1;
                endIndex = i;
            }
        }
    }

    cout << "Max Length: " << maxLen << endl;
    cout << "Start Index: " << startIndex << endl;
    cout << "End Index: " << endIndex << endl;
    for (int j = startIndex; j <= endIndex; j++) {
        cout << arr[j] << " ";
    }
}

int main()
{
    int arr[] = {10, -5, 2, -1, 15, -7, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    findingLongestSubArray(arr, n, k);
    return 0;
}