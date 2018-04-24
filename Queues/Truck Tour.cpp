// https://www.hackerrank.com/challenges/truck-tour/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct stop
{
    long petrol;
    long distance;
};

void readIn(queue<stop>& Q)
{
    int N;
    cin >> N;
    
    while(N--){
        long val;
        long dist;
        cin >> val >> dist;
        
        stop st{val, dist};
        Q.push(st);
    }
}


int main() {
    
    queue<stop> Q;
    queue<stop> tripQ;
    int sPos = 0;
    long amount = 0;
    
    readIn(Q);
    
    while(!Q.empty())
    {
        stop current = Q.front();
        Q.pop();
        
        if(current.petrol + amount >= current.distance)
        {
            amount += current.petrol - current.distance;
            tripQ.push(current);
        }
        else
        {
            while(!tripQ.empty())
            {
                Q.push(tripQ.front());
                tripQ.pop();
                ++sPos;
            }
            Q.push(current);
            amount = 0;
            ++sPos;
        }
    }
    
    cout << sPos << endl;
    
    
    return 0;
}

