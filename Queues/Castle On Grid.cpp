// https://www.hackerrank.com/challenges/castle-on-the-grid/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

constexpr int N = 101;
int Q;
int q = 0;
char grid[N][N];
int sa, sb;
int ta, tb;

vector<vector<int>> graph;

void readIn()
{
    cin >> q;
    Q = q;
    int len = q;
    int row = 0;

    while (q--)
    {
        int qq = 0;
        while (qq < len)
        {
            char c;
            cin >> c;
            grid[row][qq++] = c;
        }
        ++row;
    }

    scanf(" %d %d", &sa, &sb);
    scanf(" %d %d", &ta, &tb);
}

int getNodeName(int x, int y)
{
    return x * Q + y;
}

void makeGraph()
{
    graph = vector<vector<int>>(Q * Q, vector<int>());

    for (int i = 0; i < Q; ++i)
    {
        for (int j = 0; j < Q; ++j)
        {
            if (grid[i][j] == '.')
            {
                int current = getNodeName(i, j);

                for (int up = i - 1; up >= 0; --up)
                {
                    if (grid[up][j] == '.')
                    {
                        int cell = getNodeName(up, j);
                        graph[current].push_back(cell);
                    }
                    else
                        break;
                }

                for (int right = j + 1; j < Q; ++right)
                {
                    if (grid[i][right] == '.')
                    {
                        int cell = getNodeName(i, right);
                        graph[current].push_back(cell);
                    }
                    else
                        break;
                }

                for (int down = i + 1; down < Q; ++down)
                {
                    if (grid[down][j] == '.')
                    {
                        int cell = getNodeName(down, j);
                        graph[current].push_back(cell);
                    }
                    else
                        break;
                }

                for (int left = j - 1; j >= 0; --left)
                {
                    if (grid[i][left] == '.')
                    {
                        int cell = getNodeName(i, left);
                        graph[current].push_back(cell);
                    }
                    else
                        break;
                }
            }
        }
    }
}

int BFS(int start, int goal)
{
    int visited[10001] = { 0 };
    int distance[10001] = { 0 };
    queue<int> Queue;
    Queue.push(start);
    visited[start] = 1;

    while (!Queue.empty())
    {
        int current = Queue.front();
        Queue.pop();

        for (int i = 0; i < graph[current].size(); ++i)
        {
            int node = graph[current][i];

            if (!visited[node])
            {
                visited[node] = 1;
                distance[node] = distance[current] + 1;
                Queue.push(node);
            }
        }
    }

    return distance[goal];
}

int main()
{
    readIn();
    makeGraph();

    int startPos = getNodeName(sa, sb);
    int goalPos = getNodeName(ta, tb);

    cout << BFS(startPos, goalPos) << endl;
    
    return 0;
}

