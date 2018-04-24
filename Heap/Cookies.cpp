// https://www.hackerrank.com/challenges/jesse-and-cookies/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() 
{
    int N, K;
    cin >> N >> K;
    int num_ops = 0;
    priority_queue<int, vector<int>, std::greater<int> > Q;
    
    while(N--){
        int val;
        cin >> val;
        Q.push(val);
    }
    
    while(!Q.empty() && Q.top() < K){
        int a = -1, b = -1;
        
        if(!Q.empty()){
            a = Q.top();
            Q.pop();
        }
        
        if(!Q.empty()){
            b = Q.top();
            Q.pop();
        }
        
        if(a == -1 || b == -1){
            num_ops = -1;
            break;
        }
        
        int c = a + (2 * b);
        Q.push(c);
        ++num_ops;
    }
    
    cout << num_ops << endl;
    return 0;
}

