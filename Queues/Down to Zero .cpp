// https://www.hackerrank.com/challenges/down-to-zero-ii/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    vector<int> dist(1000001, 0);
    int q, n;
    cin >> q;
    
    
    while(q--){
        cin >> n;
        dist[n] = 1;
        
        queue<int> queue;
        queue.push(n);
        
        while(!queue.empty()){
            int now = queue.front();
            queue.pop();
            
            if(dist[now-1] == 0){
                dist[now-1] = dist[now] + 1;
                if(now-1 == 0)
                    break;
                queue.push(now-1);
            }
            
            for(int i=2; i <= sqrt(now); ++i){
                if(now%i == 0){
                    int fact = max(i, now/i);
                    
                    if(dist[fact] == 0){
                        dist[fact] = dist[now] + 1;
                        queue.push(fact);
                    }
                }
            }
        }
        
        cout << dist[0] - 1 << endl;
        fill(begin(dist), end(dist), 0);
        
    }
        
    
    
    return 0;
}

