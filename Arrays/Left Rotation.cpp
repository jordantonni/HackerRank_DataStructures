// https://www.hackerrank.com/challenges/array-left-rotation/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> readN(int n = 0)
{
    size_t size = 0;
    size = n;

    if (n == 0)
    {
        cin >> size;
    }

    vector<int> ret;

    for (int i = 0; i < size; ++i)
    {
        int temp;
        cin >> temp;
        ret.push_back(temp);
    }

    return ret;
}

int main()
{
    int size = 0, shift = 0;
    cin >> size >> shift;

    vector<int> v = readN(size);
    vector<int> ret(size);

    for (int i = 0; i < size; ++i)
    {
        int new_pos = i - shift;

        if(new_pos >= 0)
            ret[new_pos] = v[i];
        else
            ret[(size)+new_pos] = v[i];
    }

    for(auto e : ret)
        cout << e << " ";
    
    return 0;
}

