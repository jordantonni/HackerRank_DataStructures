// https://www.hackerrank.com/challenges/qheap1/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Heap
{
    int v[100000];
    int pos;

    int getParent(int i) const
    {
        if (i <= 0)
            return -1;

        return floor((i - 1) / 2);
    }

    int getLeftChild(int i) const
    {
        int ret = 2 * i + 1;
        if (ret >= pos)
            return -1;
        return ret;
    }

    int getRightChild(int i) const
    {
        int ret = 2 * i + 2;
        if (ret >= pos)
            return -1;
        return ret;
    }

    void bubbleUp(int i)
    {
        int p = getParent(i);
        while (p != -1 && v[p] > v[i])
        {
            int temp = v[p];
            v[p] = v[i];
            v[i] = temp;
            i = p;
            p = getParent(i);
        }
    }

    void bubbleDown(int i)
    {
        int left = getLeftChild(i);
        int right = getRightChild(i);
        int smallest;

        if (left != -1 && v[left] < v[i])
            smallest = left;
        else
            smallest = i;
        if (right != -1 && v[right] < v[smallest])
            smallest = right;

        if (smallest != i)
        {
            int temp = v[smallest];
            v[smallest] = v[i];
            v[i] = temp;
            bubbleDown(smallest);
        }
    }

public:
    explicit Heap()
        : pos { 0 }
    {
    }
    
    void insert(int x)
    {
        v[pos] = x;
        ++pos;
        
        bubbleUp(pos - 1);
    }

    void removeMin()
    {
        if (empty())
            return;

        v[0] = v[--pos];
        bubbleDown(0);
    }

    bool empty() const
    {
        return pos == 0;
    }

    int getMin()
    {
        if (pos >= 0)
            return v[0];
        return -1;
    }

    void removeVal(int val)
    {
        int index = -1;
        for (int i = 0; i < pos; ++i)
        {
            if (v[i] == val)
            {
                index = i;
                break;
            }
        }

        if(index == pos-1)
        {
            --pos;
            return;
        }

        if (index != -1)
        {
            v[index] = v[pos - 1];
            --pos;

            bubbleDown(index);
        }
    }
};


int main()
{
    int Q;
    cin >> Q;
    Heap H;
    
    while(Q--)
    {
        int qt;
        cin >> qt;
        
        switch(qt)
        {
            case(1):
            {
                int val;
                cin >> val;
                H.insert(val);
                break;
            }
            case(2):
            {
                int val;
                cin >> val;
                H.removeVal(val);
                break;
            }
            default:
            {
                cout << H.getMin() << endl;
            }
                
        }
    }
    
    return 0;
}

