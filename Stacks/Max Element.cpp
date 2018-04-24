// https://www.hackerrank.com/challenges/maximum-element/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Stack
{
    private:
    vector<int> s;
    int top;
    
    public:
    explicit Stack() : top {-1}
    {
        s.reserve(10000000);
    }
    
    void push(int e)
    {
        s.insert(begin(s) + (++top), e);
    }
    
    void pop()
    {
        --top;
    }
    
    int peek()
    {
        return s.at(top);
    }
    
    bool empty()
    {
        return top == -1;
    }
    
    
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    Stack s, s_max;
    
    int n, qt, val;
    cin >> n;
    
    while(n--)
    {
        cin >> qt;
        
        if(1 == qt)
        {
            cin >> val;
            s.push(val);
            
            if(s_max.empty() || val >= s_max.peek())
                s_max.push(val);
        }
        else if(2 == qt)
        {
            int temp = s.peek();
            s.pop();
            
            if(temp == s_max.peek())
                s_max.pop();
        }
        else
        {
            cout << s_max.peek() << endl;
        }
    }
        
 
 
    return 0;
}

