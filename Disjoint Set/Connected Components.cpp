// https://www.hackerrank.com/challenges/components-in-graph/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 30005;

class DisjointSet
{
    int array[MAX];
    int size[MAX];

    int getRoot(int a)
    {
        while (array[a] != a){
            array[a] = array[array[a]];
            a = array[a];
        }
        return a;
    }

public:
    explicit DisjointSet()
    {
        for (auto i = 0; i < MAX; ++i)
        {
            array[i] = i;
            size[i] = 1;
        }
    }

    void makeUnion(int a, int b)
    {
        int rootA = getRoot(a);
        int rootB = getRoot(b);

        if (rootA == rootB)
            return;

        if (size[rootA] >= size[rootB])
        {
            array[rootB] = rootA;
            size[rootA] += size[rootB];
        }
        else
        {
            array[rootA] = rootB;
            size[rootB] += size[rootA];
        }
    }

    bool find(int a, int b)
    {
        int rootA = getRoot(a);
        int rootB = getRoot(b);

        return (rootA == rootB);
    }

    int largestSubgraphSize()
    {
        return *std::max_element(begin(size), end(size));
    }

    int smallestSubgraphSize()
    {
        int min = INT32_MAX;
        for (int i = 0; i < MAX; ++i)
        {
            int par = getRoot(i);
            if (size[par] > 1 && size[par] < min)
                min = size[par];
        }

        return min;
    }
};


DisjointSet makeGraph()
{
    int N;
    cin >> N;

    DisjointSet G;

    while (N--)
    {
        int a, b;
        cin >> a >> b;

        G.makeUnion(a, b);
    }

    return G;
}


int main()
{
    DisjointSet G = makeGraph();

    cout << G.smallestSubgraphSize() << " ";
    cout << G.largestSubgraphSize() << endl;
    
    return 0;

}
