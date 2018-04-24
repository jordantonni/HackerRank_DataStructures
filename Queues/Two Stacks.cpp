// https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct queue
{
    private:
    stack<int> S1, S2;
    
    public:
    void enqueue(int elem)
    {
        S1.push(elem);
    }
    
    void dequeue()
    {
        if(S2.empty()){
            while(!S1.empty()){
                S2.push(S1.top());
                S1.pop();
            }
        }
        
        S2.pop();
    }
    
    int peek()
    {
        if(S2.empty()){
            while(!S1.empty()){
                S2.push(S1.top());
                S1.pop();
            }
        }
        
        return S2.top();
    }
};

int main() {
    queue Q;
    
    int N, qt;
    cin >> N;
    
    while(N--){
        cin >> qt;
        switch(qt){
            case(1):
                int val;
                cin >> val;
                Q.enqueue(val);
                break;
                
            case(2):
                Q.dequeue();
                break;
                
            default:
                cout << Q.peek() << endl;
                break;
        }
    }
    
    return 0;
}

