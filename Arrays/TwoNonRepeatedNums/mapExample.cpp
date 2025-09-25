#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

void demonstrateOrderedMap() {
    cout << "=== ORDERED MAP (std::map) ===" << endl;
    map<int, string> orderedMap;
    
    // Insert elements in random order
    orderedMap[5] = "Five";
    orderedMap[1] = "One";
    orderedMap[3] = "Three";
    orderedMap[2] = "Two";
    orderedMap[4] = "Four";
    
    cout << "Elements (automatically sorted by key):" << endl;
    for (const auto& pair : orderedMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Range operations (only available in ordered map)
    cout << "\nRange operations:" << endl;
    auto lower = orderedMap.lower_bound(2);
    auto upper = orderedMap.upper_bound(4);
    cout << "Elements from key 2 to 4:" << endl;
    for (auto it = lower; it != upper; ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << endl;
}

void demonstrateUnorderedMap() {
    cout << "=== UNORDERED MAP (std::unordered_map) ===" << endl;
    unordered_map<int, string> unorderedMap;
    
    // Insert elements in same order
    unorderedMap[5] = "Five";
    unorderedMap[1] = "One";
    unorderedMap[3] = "Three";
    unorderedMap[2] = "Two";
    unorderedMap[4] = "Four";
    
    cout << "Elements (random order based on hash):" << endl;
    for (const auto& pair : unorderedMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    cout << endl;
}

void performanceComparison() {
    cout << "=== PERFORMANCE COMPARISON ===" << endl;
    const int NUM_OPERATIONS = 100000;
    
    // Test ordered map
    auto start = high_resolution_clock::now();
    map<int, int> orderedMap;
    for (int i = 0; i < NUM_OPERATIONS; ++i) {
        orderedMap[i] = i * 2;
    }
    for (int i = 0; i < NUM_OPERATIONS; ++i) {
        auto it = orderedMap.find(i);
    }
    auto end = high_resolution_clock::now();
    auto orderedTime = duration_cast<milliseconds>(end - start);
    
    // Test unordered map
    start = high_resolution_clock::now();
    unordered_map<int, int> unorderedMap;
    for (int i = 0; i < NUM_OPERATIONS; ++i) {
        unorderedMap[i] = i * 2;
    }
    for (int i = 0; i < NUM_OPERATIONS; ++i) {
        auto it = unorderedMap.find(i);
    }
    end = high_resolution_clock::now();
    auto unorderedTime = duration_cast<milliseconds>(end - start);
    
    cout << "Operations: " << NUM_OPERATIONS << " insertions + " << NUM_OPERATIONS << " lookups" << endl;
    cout << "Ordered map time: " << orderedTime.count() << " ms" << endl;
    cout << "Unordered map time: " << unorderedTime.count() << " ms" << endl;
    cout << "Speedup: " << (double)orderedTime.count() / unorderedTime.count() << "x" << endl;
    
    cout << endl;
}

void practicalExample() {
    cout << "=== PRACTICAL EXAMPLE: WORD FREQUENCY COUNTER ===" << endl;
    
    string text = "the quick brown fox jumps over the lazy dog the fox is quick";
    unordered_map<string, int> wordCount;
    
    // Simple word parsing (split by spaces)
    string word = "";
    for (char c : text + " ") {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;
                word = "";
            }
        } else {
            word += c;
        }
    }
    
    cout << "Word frequencies (using unordered_map for fast counting):" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    cout << "\nSorted word frequencies (convert to map for ordering):" << endl;
    map<string, int> sortedWordCount(wordCount.begin(), wordCount.end());
    for (const auto& pair : sortedWordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    cout << endl;
}

int main() {
    demonstrateOrderedMap();
    demonstrateUnorderedMap();
    performanceComparison();
    practicalExample();
    
    cout << "=== KEY TAKEAWAYS ===" << endl;
    cout << "1. Use std::map when you need sorted keys or range operations" << endl;
    cout << "2. Use std::unordered_map when you need fast lookups and order doesn't matter" << endl;
    cout << "3. Both have similar API, easy to switch between them" << endl;
    cout << "4. unordered_map is generally faster for simple operations" << endl;
    cout << "5. map provides consistent O(log n) performance" << endl;
    
    return 0;
}