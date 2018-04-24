// https://www.hackerrank.com/challenges/sparse-arrays/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

unordered_multiset<string> readStrings()    // O(N)
{
    int n;
    cin >> n;
    string st;
    unordered_multiset<string> hashSet;
    while(n--){ //O(N)
        cin >> st; // O(1)
        hashSet.insert(st); // O(1)
    }
    return hashSet;
}

vector<string> readInputs()  // O(N)
{
    int n;
    cin >> n;
    string st;
    vector<string> inputs;
    while(n--){ // O(N)
        cin >> st; // O(1)
        inputs.emplace_back(st); // O(1)
    }
    return inputs;
}

size_t freqCount(const string& str, const unordered_multiset<string>& hashSet) // O(N)
{
    auto range = hashSet.equal_range(str); // O(N) avg
    return distance(range.first, range.second);
}

int main() {
    unordered_multiset<string> hashSet = readStrings();     // O(N)
    vector<string> inputs = readInputs(); // O(N)
    
    for(const auto& query : inputs) // Q inputs * O(N)
        cout << freqCount(query, hashSet) << "\n";  //
    
    return 0;
}

