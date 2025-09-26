#include <bits/stdc++.h>
using namespace std;
// Optimal approach - O(m + n) time complexity and O(1) space complexity
void unionOptimal(vector<int> &arr1, vector<int> &arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int i = 0, j = 0;
    vector<int> result;

    while(i < m && j < n) { // O(m + n)
        if(arr1[i] < arr2[j]) {
            if(result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
        } else if(arr1[i] > arr2[j]) {
            if(result.empty() || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        } else {
            if(result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while(i < m) { // O(m)
        if(result.empty() || result.back() != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++;
    }

    while(j < n) { // O(n)
        if(result.empty() || result.back() != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }

    for(int num : result) {
        cout << num << " ";
    }
}
int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 5, 6};
    unionOptimal(arr1, arr2);
    return 0;
}
// Compare this snippet from Arrays/Union%2CInsertion/unionSorted.cpp:
// #include <bits/stdc++.h>
// using namespace std;