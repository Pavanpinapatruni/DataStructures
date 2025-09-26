#include <bits/stdc++.h>
using namespace std;

void findingLongestSubArray(int arr[], int n, int k)
{
    int start = 0, end = 0;
    int currSum = 0;
    int maxLen = 0;

    while (end < n) {
        currSum += arr[end];

        while (currSum > k && start <= end) {
            currSum -= arr[start];
            start++;
        }

        if (currSum == k) {
            if (maxLen < end - start + 1) {
                maxLen = end - start + 1;
            }
        }
        end++;
    }
}

int main()
{
    int arr[] = {10, 0, 5, 2, 0, 7, 1, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    findingLongestSubArray(arr, n, k);
    return 0;
}