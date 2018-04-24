// https://www.hackerrank.com/challenges/contacts/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <stack>
using namespace std;

class Node
{
    bool isWord;

public:
    size_t size;
    unordered_map<char, shared_ptr<Node>> children;

    explicit Node(const bool legal = false)
        : isWord{ legal }, size { 0 }
    {}

    bool valid() const
    {
        return isWord;
    }

    void makeValid()
    {
        isWord = true;
    }
};

class Trie
{
    shared_ptr<Node> root;

public:
    explicit Trie()
        : root{ make_shared<Node>() }
    {}

    shared_ptr<Node> endOfPrefix(const string& str) const
    {
        shared_ptr<Node> n = root;
        int i = 0;
        while (i < str.length())
        {
            auto search = n->children.find(str.at(i));
            if (search != n->children.end())
            {
                n = search->second;
                ++i;
            }
            else
                return root;
        }

        return n;
    }

    void add(const string& name) const
    {
        shared_ptr<Node> n = root;

        int i = 0;
        while (i < name.length())
        {
            auto search = n->children.find(name.at(i));
            if (search != n->children.end())
            {
                n = search->second;
                ++n->size;
                ++i;
            }
            else
            {
                break;
            }
        }

        while (i < name.length())
        {
            shared_ptr<Node> newNode = make_shared<Node>();
            n->children.insert(make_pair(name[i], newNode));
            n = newNode;
            ++n->size;
            ++i;
        }

        n->makeValid();
    }
    
    size_t fastFind(const string& prefix)
    {
        shared_ptr<Node> n = endOfPrefix(prefix);

        return n->size;
    }

    size_t find(const string& str) const
    {
        size_t count = 0;

        shared_ptr<Node> n = endOfPrefix(str);
        if(n == root)
            return count;

        stack<shared_ptr<Node>> st;
        st.push(n);

        while (!st.empty())
        {
            shared_ptr<Node> n = st.top();
            st.pop();

            for (auto c : n->children)
                st.push(c.second);

            if (n->valid())
                ++count;
        }

        return count;
    }
};

int main() 
{
     Trie tr;
    
    int N;
    cin >> N;
    
    while(N--)
    {
        string q;
        cin >> q;
        
        if(q == "add")
        {
            string name;
            cin >> name;
            tr.add(name);
        }
        else if(q == "find")
        {
            string prefix;
            cin >> prefix;
            
            cout << tr.fastFind(prefix) << endl;
        }
    }
    
    return 0;
}

