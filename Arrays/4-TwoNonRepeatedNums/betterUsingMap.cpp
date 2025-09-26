#include <bits/stdc++.h>
using namespace std;

void nonRepeatedNum(vector<int> &arr) {
    int n = arr.size();
    unordered_map<long long, int> freqMap;
    
    for(int num : arr) {
        freqMap[num]++;
    }
    
    vector<int> result;
    for(auto &pair : freqMap) {
        if(pair.second == 1) {
            result.push_back(pair.first);
        }
    }
    
    for(int num : result) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 1};
    nonRepeatedNum(arr);
    return 0;
}