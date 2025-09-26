#include <bits/stdc++.h>
using namespace std;

// Your current approach (BEST for this problem)
void nonRepeatedNumUnordered(vector<int> &arr) {
    cout << "Using unordered_map:" << endl;
    unordered_map<int, int> freqMap;
    
    // Count frequencies - O(1) average per operation
    for(int num : arr) {
        freqMap[num]++;
    }
    
    // Find elements with frequency 1
    vector<int> result;
    for(auto &pair : freqMap) {
        if(pair.second == 1) {
            result.push_back(pair.first);
        }
    }
    
    // Output (order may vary due to hash table)
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

// Alternative using ordered map
void nonRepeatedNumOrdered(vector<int> &arr) {
    cout << "Using ordered map:" << endl;
    map<int, int> freqMap;
    
    // Count frequencies - O(log n) per operation
    for(int num : arr) {
        freqMap[num]++;
    }
    
    // Find elements with frequency 1 (will be in sorted order)
    vector<int> result;
    for(auto &pair : freqMap) {
        if(pair.second == 1) {
            result.push_back(pair.first);
        }
    }
    
    // Output (always in sorted order)
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

// Demonstrating when you might want ordered output
void nonRepeatedNumSorted(vector<int> &arr) {
    cout << "Using unordered_map but with sorted output:" << endl;
    unordered_map<int, int> freqMap;
    
    // Count frequencies - O(1) average per operation
    for(int num : arr) {
        freqMap[num]++;
    }
    
    // Find elements with frequency 1
    vector<int> result;
    for(auto &pair : freqMap) {
        if(pair.second == 1) {
            result.push_back(pair.first);
        }
    }
    
    // Sort the result if needed
    sort(result.begin(), result.end());
    
    // Output (sorted)
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

// Performance comparison
void performanceTest() {
    cout << "\n=== PERFORMANCE TEST ===" << endl;
    vector<int> largeArr;
    
    // Create large test array
    for(int i = 0; i < 100000; i++) {
        largeArr.push_back(i % 1000); // Many duplicates
    }
    for(int i = 0; i < 50; i++) {
        largeArr.push_back(100000 + i); // Some unique elements
    }
    
    // Test unordered_map
    auto start = chrono::high_resolution_clock::now();
    unordered_map<int, int> freqMapUnordered;
    for(int num : largeArr) {
        freqMapUnordered[num]++;
    }
    int countUnordered = 0;
    for(auto &pair : freqMapUnordered) {
        if(pair.second == 1) countUnordered++;
    }
    auto end = chrono::high_resolution_clock::now();
    auto unorderedTime = chrono::duration_cast<chrono::microseconds>(end - start);
    
    // Test ordered map
    start = chrono::high_resolution_clock::now();
    map<int, int> freqMapOrdered;
    for(int num : largeArr) {
        freqMapOrdered[num]++;
    }
    int countOrdered = 0;
    for(auto &pair : freqMapOrdered) {
        if(pair.second == 1) countOrdered++;
    }
    end = chrono::high_resolution_clock::now();
    auto orderedTime = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "Array size: " << largeArr.size() << endl;
    cout << "Unique elements found: " << countUnordered << endl;
    cout << "unordered_map time: " << unorderedTime.count() << " microseconds" << endl;
    cout << "map time: " << orderedTime.count() << " microseconds" << endl;
    cout << "Speedup: " << (double)orderedTime.count() / unorderedTime.count() << "x" << endl;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 1, 7, 8, 9, 9};
    
    cout << "Input array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    nonRepeatedNumUnordered(arr);
    nonRepeatedNumOrdered(arr);
    nonRepeatedNumSorted(arr);
    
    performanceTest();
    
    cout << "\n=== RECOMMENDATION ===" << endl;
    cout << "For frequency counting problems like yours:" << endl;
    cout << "✅ Use unordered_map (your current choice is PERFECT!)" << endl;
    cout << "❌ Avoid map unless you specifically need sorted keys" << endl;
    cout << "💡 Sort the final result if you need ordered output" << endl;
    
    return 0;
}