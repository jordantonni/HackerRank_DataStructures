// https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> readIn(int N)
{
    vector<int> ret;
    
    while(N--){
        int val;
        cin >> val;
        ret.push_back(val);
    }
    return ret;
}


int main() 
{
    int N,Q;
    cin >> N >> Q;
    vector<int> vals = readIn(N);
    
    
    while(Q--){
        int k;
        cin >> k;
        vector<int> maxes;
        deque<int> D(k);
        
        int i;
        for(i=0; i<k; ++i){
            while((!D.empty()) && vals[i] >= vals[D.back()])
                D.pop_back();
            
            D.push_back(i);
        }
        
        for( ; i<N; ++i){
            maxes.push_back(vals[D.front()]);
            
            while(!D.empty() && D.front() <= i-k)
                D.pop_front();
            
            while(!D.empty() && vals[i] >= vals[D.back()])
                D.pop_back();
            
            D.push_back(i);
        }
        
        maxes.push_back(vals[D.front()]);
        
        cout << *min_element(begin(maxes), end(maxes)) << endl;
    }
    
    
    return 0;
}

