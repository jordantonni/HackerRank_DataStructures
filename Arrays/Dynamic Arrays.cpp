// https://www.hackerrank.com/challenges/dynamic-array/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

using SEQLIST = vector<shared_ptr<vector<int>>>;
int last_answer = 0;
int N = 0;

void query_one(int x, int y, shared_ptr<SEQLIST> list)
{
    (*list).at((x ^ last_answer) % N)->push_back(y);
}

void query_two(int x, int y, shared_ptr<SEQLIST> list)
{
    shared_ptr<vector<int>> seq = (*list).at((x ^ last_answer) % N);

    last_answer = seq->at(y % seq->size());
    cout << last_answer << endl;
}


int main()
{
    int Q = 0;
    cin >> N >> Q;

    shared_ptr<SEQLIST> seqList { make_shared<SEQLIST>(N) };

    for (int i = 0; i < N; ++i)
    {
        seqList->at(i) = make_shared<vector<int>>();
    }

    while (Q > 0)
    {
        int query_type, x, y;
        cin >> query_type >> x >> y;

        if (query_type == 1)
        {
            query_one(x, y, seqList);
        }
        else if (query_type == 2)
        {
            query_two(x, y, seqList);
        }

        --Q;
    }
    
    return 0;
}

