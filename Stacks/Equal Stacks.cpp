// https://www.hackerrank.com/challenges/equal-stacks/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    stack<int> s1, s2, s3;
    deque<int> d1, d2, d3;
    
    int sum1, sum2, sum3;
    sum1 = sum2 = sum3 = 0;
    
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    
    while(n1--){
        int val;
        cin >> val;
        d1.push_front(val);
        sum1 += val;
    }
    while(n2--){
        int val;
        cin >> val;
        d2.push_front(val);
        sum2 += val;
    }
    while(n3--){
        int val;
        cin >> val;
        d3.push_front(val);
        sum3 += val;
    }
    
    // Check if any stack has no elements or all the same sum to begin with, if so we can return them as the size
    if(sum1 == 0 || sum2 == 0 || sum3 == 0){
        cout << 0 << endl;
        return 0 ;
    }
    if(sum1 == sum2 && sum1 == sum3){
        cout << sum1 << endl;
        return 0;
    }
    
    for(auto e : d1)
        s1.push(e);
    for(auto e : d2)
        s2.push(e);
    for(auto e : d3)
        s3.push(e);
    
    // Pop element of the largest sum stack until they are all the same or 0
    while(true){
        int* max = NULL;
        stack<int>* s;
        if(sum1 > sum2){
            max = &sum1;
            s = &s1;
        }
        else{
            max = &sum2;
            s = &s2;
        }
        if(sum3 > *max){
            max = &sum3;
            s = &s3;
        }
        
        
        *max -= s->top();
        s->pop();
        
        if(sum1 == sum2 && sum2 == sum3)
            break;
        
    }
    
    cout << sum1 << endl;
    
    
    return 0;
}

