// https://www.hackerrank.com/challenges/merging-communities/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class DisjointSet
{
    vector<int> arr;
    vector<int> size;
    
    public:
    explicit DisjointSet (int N) : size(N,1)
    {
        arr.reserve(N);
        for(auto i = 0; i < N; ++i){
            arr.push_back(i);
        }
    }
    
    void merge(const int u, const int v)
    {
        int uParent = getRoot(u);
        int vParent = getRoot(v);
        
        if(uParent == vParent)
            return;
        
        int uComponentSize = size[uParent];
        int vComponentSize = size[vParent];
        
        if(uComponentSize >= vComponentSize){
            arr[vParent] = uParent;
            size[uParent] += size[vParent];
        }else{
            arr[uParent] = vParent;
            size[vParent] += size[uParent];
        }
    }
    
    int getSizeOfComponent(const int i)
    {
        return size[getRoot(i)];
    }
    
    private:
    int getRoot(int i)
    {
        while(arr[i] != i){
            arr[i] = arr[arr[i]];
            i = arr[i];
        }
        return i;
    }
};


int main() {
    
    int N,Q;
    cin >> N >> Q;
    
    DisjointSet set(100001);
    
    while(Q--){
        char qt;
        cin >> qt;
        
        switch(qt){
                case('Q'):{
                    int ele;
                    cin >> ele;
                    
                    cout << set.getSizeOfComponent(ele) << endl;
                    break;
                }
            default:{
                int u,v;
                cin >> u >> v;
                
                set.merge(u,v);
            }
        }
    }
    
    return 0;
}

