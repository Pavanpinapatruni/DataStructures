#include <bits/stdc++.h>
using namespace std;

void intersectionOptimal(vector<int> &arr1, vector<int> &arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int i = 0, j = 0;
    vector<int> result;

    while(i < m && j < n) {
        if(arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    for(int num : result) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 3, 5, 6};
    intersectionOptimal(arr1, arr2);
    return 0;
}