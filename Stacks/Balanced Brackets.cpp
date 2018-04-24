// https://www.hackerrank.com/challenges/balanced-brackets/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;



int main() {
    
    int n;
    cin >> n;
    vector<string> inputs;
    
    string st;
    getline(cin,st);
    
    while(n--){
        // Put input line into inputs vector
        getline(cin, st);
        inputs.push_back(st);
    }
    
    
    // For each input line
    for(auto i=0; i<inputs.size(); ++i)
    {
        if(inputs[i].length() % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        
        stack<char> s;
        bool fail = 0;
        // For each bracket in the input line
        for(auto e : inputs[i])
        {
            
            //If Left type push to stack
            if(e == '(' || e == '{' || e == '[')
            {
                s.push(e);
                continue;
            } 
            else if(e == ')' || e == '}' || e == ']') 
            {
                if(s.empty()) 
                {
                    fail = 1;
                    break;
                }

                char top = s.top();
                if(e == ')' && top == '(')
                    s.pop();
                else if(e == '}' && top == '{')
                    s.pop();
                else if(e == ']' && top == '[')
                    s.pop();
                
            }
        }
        
        if(!fail && s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
    
    
    return 0;
}

