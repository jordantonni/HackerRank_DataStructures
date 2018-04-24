// https://www.hackerrank.com/challenges/no-prefix-set/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;

class Node
    {
        bool valid;
    public:
        unordered_map<char, shared_ptr<Node>> children;

        explicit Node()
            : valid { false }
        { }

        bool isValid() const
        {
            return valid;
        }

        void makeValid()
        {
            valid = true;
        }
    };

    class Trie
    {
        shared_ptr<Node> root;
    public:
        pair<bool, string> bad_set;
        
        explicit Trie()
            : root { make_shared<Node>() }, bad_set { make_pair(false, "")}
        { }
        
        void addString(const string& str) 
        {
            shared_ptr<Node> n = root;
            size_t str_indx = 0;
            while (str_indx < str.length())
            {
                auto search = n->children.find(str.at(str_indx));
                if (search != n->children.end())
                {
                    if (search->second->isValid())
                    {
                        bad_set.first = true;
                        bad_set.second = str;
                        return;
                    }

                    n = search->second;
                    ++str_indx;
                }
                else
                {
                    break;
                }
            }

            if (str_indx == str.length())
            {
                 bad_set.first = true;
                        bad_set.second = str;
                        return;
            }

            while (str_indx < str.length())
            {
                shared_ptr<Node> new_node { make_shared<Node>() };
                n->children.insert(make_pair(str.at(str_indx), new_node));
                ++str_indx;
                n = new_node;
            }

            n->makeValid();
        }
    };

int main() 
{
    int N;
    cin >> N;
    string str;
    
    Trie trie;
    
    while(N--){
        cin >> str;
        trie.addString(str);
        
        if(trie.bad_set.first)
            break;
    }
    
    if(N < 0)
        cout << "GOOD SET\n";
    else{
        cout << "BAD SET\n";
        cout << trie.bad_set.second << endl;
    }
        
    
    return 0;
}

