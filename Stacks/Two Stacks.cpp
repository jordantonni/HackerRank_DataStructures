// https://www.hackerrank.com/challenges/game-of-two-stacks/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
    vector<int>A;
    vector<int>B;
    vector<pair<int,int> > pairs;

    int g, n, m, x;
    cin >> g;

    while(g--) 
    {
        cin >> n >> m >> x;

        while(n--) {
            int val;
            cin >> val;
            A.push_back(val);
        }
        while(m--) {
            int val;
            cin >> val;
            B.push_back(val);
        }
        
        // Max (x,0)
        int sum = 0;
        int i = 0;
        while(i < A.size() && sum + A[i] <= x)
        {
            sum += A[i];
            ++i;
        }
        --i;
        
        pair<int,int> p = {i+1,0};
        pairs.push_back(p);
        
        for(int j=0; j<B.size(); ++j)
        {
            sum += B[j];
            
            while(sum > x && i>=0)
            {
                sum -= A[i];
                --i;
            }
            
            if(sum <= x)
            {
                pair<int,int> p = {i+1,j+1};
                pairs.push_back(p);
            }
        }
        
        int tMax = 0;
        for(auto e : pairs)
        {
            int temp = e.first + e.second;
            tMax = temp>tMax? temp : tMax;
        }
        
        cout << tMax << endl;
        A.clear();
        B.clear();
        pairs.clear();
    }


    return 0;
}
