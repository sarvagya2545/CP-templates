#include<bits/stdc++.h>
using namespace std;

const int K = 26;

class TrieNode {
    char c, parent_char;
    vector<TrieNode*> next;
    TrieNode* parent;
public:
    TrieNode(
        char c = '*', 
        TrieNode* parent = NULL, 
        char parent_char = '%'
    ): c(c), parent_char(parent_char), parent(parent) {
        next = vector<TrieNode*> (K, NULL);
    }
};

class Trie {
public:

};