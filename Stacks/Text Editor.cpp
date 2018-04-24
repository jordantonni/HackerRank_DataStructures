// https://www.hackerrank.com/challenges/simple-text-editor/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class StringStack
{
    private:
    stack<string> SS;
    
    public:
    explicit StringStack()
    {
        SS.push("");
    }
    
    void append(string w)
    {
        string temp = SS.top();
        temp.append(w);
        SS.push(temp);
    }
    
    void del(int k)
    {
        string temp = SS.top();
        int len = temp.size() - k;
        temp.resize(len);
        SS.push(temp);
    }
    
    void print(int k) const
    {
        cout << SS.top().at(k-1) << endl;
    }
    
    void undo()
    {
        SS.pop();
    }
};


int main() {
    
    StringStack ss;
    
    int q;
    int type;
    cin >> q;
    
    while(q--){
        cin >> type;
        
        switch(type){
                case(1):{
                    string t;
                    cin >> t;
                    ss.append(t);
                    break;
                }
                case(2):{
                    int k;
                    cin >> k;
                    ss.del(k);
                    break;
                }
                case(3):{
                    int k;
                    cin >> k;
                    ss.print(k);
                    break;
                }
                case(4):{
                    ss.undo();
                }
        }
        
    }
    
    return 0;
}

