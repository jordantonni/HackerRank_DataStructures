// https://www.hackerrank.com/challenges/find-the-running-median/problem
// Jordan Tonni

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <functional>

using namespace std;

multiset<int, less<int>> largeBST;
multiset<int, greater<int>> smallBST;


void rebalance()
{
    if(fabs(smallBST.size() - largeBST.size()) <= 1)
        return;
        
    if(smallBST.size() > largeBST.size()) {
        while(smallBST.size() > largeBST.size() + 1) {
            largeBST.insert(*(smallBST.begin()));
            smallBST.erase(smallBST.begin());
        }
        return;
    }

    while(largeBST.size() > smallBST.size()) {
        smallBST.insert(*(largeBST.begin()));
        largeBST.erase(largeBST.begin());
    }
}

void addToTree(const int val)
{
    if(val < *(smallBST.begin()) || smallBST.empty())
        smallBST.insert(val);
    else
        largeBST.insert(val);

    rebalance();
}

float getMedian()
{
    int smallS = smallBST.size();
    int largeS = largeBST.size();

    if(smallS > largeS)
        return *(smallBST.begin());
    else if(largeS > smallS)
        return *(largeBST.begin());

    float sTop = static_cast<float>(*(smallBST.begin()));
    float lTop = static_cast<float>(*(largeBST.begin()));
    return (static_cast<float>(sTop) + lTop) / 2;
}

bool isFraud(const int amount)
{
    if(amount >= (getMedian() * 2) )
        return true;
    return false;
}

int main() 
{
    int n;
    cin >> n;
   
    int currentDay = 0;
    while(currentDay++ < n){
        int in;
        cin >> in;
        addToTree(in);
        cout << getMedian() << endl;
    }
    
}

